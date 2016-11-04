#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

int lsum[MAXN << 2], msum[MAXN << 2], rsum[MAXN << 2], lazy[MAXN << 2];
int n, m;

void build( int rt, int left, int right ) {
	lazy[rt] = 1; lsum[rt] = msum[rt] = rsum[rt] = ( right - left + 1 ) * lazy[rt];
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	build( lson ); build( rson );
	return ;
}

void update( int rt, int left, int right, int l, int r, int val ) {
	if( left == l && r == right ) {
		lazy[rt] = val; lsum[rt] = msum[rt] = rsum[rt] = ( r - l + 1 ) * lazy[rt];
		return ;
	}
	int mid = ( left + right ) >> 1, sl, sr;
	sl = rt << 1; sr = rt << 1 | 1;
	if( ~lazy[rt] ) {
		lazy[sl] = lazy[sr] = lazy[rt]; lazy[rt] = -1;
		lsum[sl] = msum[sl] = rsum[sl] = ( mid - left + 1 ) * lazy[sl];
		lsum[sr] = msum[sr] = rsum[sr] = ( right - mid ) * lazy[sr];
	}
	if( r <= mid ) update( lson, l, r, val );
	else if( l > mid ) update( rson, l, r, val );
	else {
		update( lson, l, mid, val );
		update( rson, mid + 1, r, val );
	}
	if( lsum[sl] == mid - left + 1 ) lsum[rt] = lsum[sl] + lsum[sr];
	else lsum[rt] = lsum[sl];
	if( rsum[sr] == right - mid ) rsum[rt] = rsum[sl] + rsum[sr];
	else rsum[rt] = rsum[sr];
	msum[rt] = max( max( msum[sl], msum[sr] ), rsum[sl] + lsum[sr] );
	return ;
}

int query( int rt, int left, int right, int val ) {
	if( left == right ) return left;
	int mid = ( left + right ) >> 1, sl, sr;
	sl = rt << 1; sr = rt << 1 | 1;
	if( ~lazy[rt] ) {
		lazy[sl] = lazy[sr] = lazy[rt]; lazy[rt] = -1;
		lsum[sl] = msum[sl] = rsum[sr] = ( mid - left + 1 ) * lazy[sl];
		lsum[sr] = msum[sr] = rsum[sr] = ( right - mid ) * lazy[sr];
	}
	if( lsum[rt] >= val ) return left;
	else if( msum[sl] >= val ) return query( lson, val );
//	if( msum[sl] >= val ) return query( lson, val );
	else if( rsum[sl] + lsum[sr] >= val ) return mid - rsum[sl] + 1;
	else return query( rson, val );
}

int main() {
	int x, a, b;
	while( ~scanf( "%d%d", &n, &m ) ) {
		build( 1, 1, n );
		while( m-- ) {
			scanf( "%d", &x );
			if( x == 1 ) {
				scanf( "%d", &b );
				if( msum[1] < b ) { puts( "0" ); continue; }
				a = query( 1, 1, n, b );
				update( 1, 1, n, a, a + b - 1, 0 );
				printf( "%d\n", a );
			} else {
				scanf( "%d%d", &a, &b );
				update( 1, 1, n, a, a + b - 1, 1 );
			}
		}
	}
	return 0;
}
