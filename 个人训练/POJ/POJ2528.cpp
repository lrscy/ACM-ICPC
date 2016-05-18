#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 200000 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

bool lazy[MAXN << 2], mhash[MAXN];
int color[MAXN << 2];
int a[MAXN], b[MAXN], num[MAXN], ans[MAXN];
int n, m, nn, cnt;

void dowork( int rt ) {
	if( lazy[rt] ) {
		int son = rt << 1; color[son] = color[rt]; lazy[son] = true;
		son = rt << 1 | 1; color[son] = color[rt]; lazy[son] = true;
		lazy[rt] = false;
	}
	return ;
}

void update( int rt, int left, int right, int l, int r, int val ) {
	if( left == l && r == right ) {
		color[rt] = val;
		lazy[rt] = true;
		return ;
	}
	dowork( rt );
	int mid = ( left + right ) >> 1;
	if( r <= mid ) update( lson, l, r, val );
	else if( l > mid ) update( rson, l, r, val );
	else {
		update( lson, l, mid, val );
		update( rson, mid + 1, r, val );
	}
	return ;
}

void query( int rt, int left, int right ) {
	if( lazy[rt] ) {
		mhash[color[rt]] = true;
		return ;
	}
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	query( lson ); query( rson );
	return ;
}

int main() {
	int t;
	scanf( "%d", &t );
	while( t-- ) {
		n = 1; nn = 0; cnt = 0;
		memset( lazy, false, sizeof( lazy ) );
		memset( mhash, false, sizeof( mhash ) );
		scanf( "%d", &m );
		for( int i = 1; i <= m; ++i ) {
			scanf( "%d%d", a + i, b + i );
			num[++nn] = a[i]; num[++nn] = b[i];
		}
		sort( num + 1, num + 1 + nn );
		n = unique( num + 1, num + 1 + nn ) - ( num + 1 );
		for( int i = n; i > 1; --i ) if( num[i] - num[i - 1] > 1 ) num[++n] = num[i] - 1;
		sort( num + 1, num + 1 + n );
		for( int i = 1; i <= m; ++i ) {
			int x, y;
			x = lower_bound( num + 1, num + n, a[i] ) - num;
			y = lower_bound( num + 1, num + n, b[i] ) - num;
			update( 1, 1, n, x, y, i );
		}
		query( 1, 1, n );
		for( int i = 1; i < MAXN; ++i ) {
			if( mhash[i] ) ++cnt;
		}
		printf( "%d\n", cnt );
	}
	return 0;
}
