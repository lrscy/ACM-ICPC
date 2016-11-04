#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1000000 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

int nmax[MAXN << 2], nmin[MAXN << 2];
int n, k;

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
	scanf( "%d%d", &n, &k );
	build( 1, 1, n );
	for( int i = 1; i < n - k + 1; ++i ) printf( "%d ", query( 1, 1, n, i, i + k - 1, 0 ) );
	printf( "%d\n", query( 1, 1, n, n - k + 1, n, 0 ) );
	for( int i = 1; i < n - k + 1; ++i ) printf( "%d ", query( 1, 1, n, i, i + k - 1, 1 ) );
	printf( "%d\n", query( 1, 1, n, n - k + 1, n, 1 ) );
	return 0;
}
