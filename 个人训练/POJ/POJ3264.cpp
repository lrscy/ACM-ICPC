#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1000000 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

int nmax[MAXN << 2], nmin[MAXN << 2];
int n, m;

void build( int rt, int left, int right ) {
	if( left == right ) { scanf( "%d", &nmax[rt] ); nmin[rt] = nmax[rt]; return ; }
	int mid = ( left + right ) >> 1;
	build( lson );
	build( rson );
	nmax[rt] = max( nmax[rt << 1], nmax[rt << 1 | 1] );
	nmin[rt] = min( nmin[rt << 1], nmin[rt << 1 | 1] );
	return ;
}

int query( int rt, int left, int right, int l, int r, int id ) {
	if( left == l && r == right ) {
		if( id == 1 ) return nmax[rt];
		else return nmin[rt];
	}
	int mid = ( left + right ) >> 1;
	if( r <= mid ) return query( lson, l, r, id );
	else if( l > mid ) return query( rson, l, r, id );
	if( id == 1 ) return max( query( lson, l, mid, id ), query( rson, mid + 1, r, id ) );
	else return min( query( lson, l, mid, id ), query( rson, mid + 1, r, id ) );
}

int main() {
	int a, b;
	scanf( "%d%d", &n, &m );
	build( 1, 1, n );
	while( m-- ) {
		scanf( "%d%d", &a, &b );
		if( a == b ) { puts( "0" ); continue; }
		printf( "%d\n", query( 1, 1, n, a, b, 1 ) - query( 1, 1, n, a, b, 0 ) );
	}
	return 0;
}
