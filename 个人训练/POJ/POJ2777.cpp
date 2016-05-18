#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100000 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

bool lazy[MAXN << 2];
int num[MAXN << 2];
int n, m, t;

void dowork( int rt ) {
	if( lazy[rt] ) {
		int son = rt << 1; num[son] = num[rt]; lazy[son] = true;
		son = rt << 1 | 1; num[son] = num[rt]; lazy[son] = true;
		lazy[rt] = false;
	}
	return ;
}

void update( int rt, int left, int right, int l, int r, int val ) {
	if( left == l && right == r ) { 
		num[rt] = ( 1 << ( val - 1 ) );
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
	num[rt] = num[rt << 1] | num[rt << 1 | 1];
	return ;
}

int query( int rt, int left, int right, int l, int r ) {
	if( left == l && r == right ) return num[rt];
	dowork( rt );
	int mid = ( left + right ) >> 1;
	if( r <= mid ) return query( lson, l, r );
	else if( l > mid ) return query( rson, l, r );
	return query( lson, l, mid ) | query( rson, mid + 1, r );
}

int main() {
	int a, b, c;
	char st[2];
	scanf( "%d%d%d", &n, &t, &m );
	memset( lazy, false, sizeof( lazy ) );
	num[1] = 1; lazy[1] = true;
	while( m-- ) {
		scanf( "%s", st );
		if( st[0] == 'C' ) {
			scanf( "%d%d%d", &a, &b, &c );
			if( a > b ) swap( a, b );
			update( 1, 1, n, a, b, c );
		} else {
			scanf( "%d%d", &a, &b );
			if( a > b ) swap( a, b );
			int tmp = query( 1, 1, n, a, b );
			int ans = __builtin_popcount( tmp );
			printf( "%d\n", ans );
		}
	}
	return 0;
}
