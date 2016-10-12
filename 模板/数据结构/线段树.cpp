/* POJ 3468 验过
    1. 有时候需要将节点改成结构体
    2. dowork 有时候需要提前声明update函数并调用update
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
#define lson rt << 1, left, mid 
#define rson rt << 1 | 1, mid + 1, right

LL num[MAXN << 2], lazy[MAXN << 2];
int n, q;

void build( int rt, int left, int right ) {
	lazy[rt] = 0;
	if( left == right ) { scanf( "%I64d", &num[rt] ); return ; }
	int mid = ( left + right ) >> 1;
	build( lson );
	build( rson );
	num[rt] = num[rt << 1] + num[rt << 1 | 1];
	return ;
}

void dowork( int rt, int len ) {
	if( lazy[rt] ) {
		int son = rt << 1; num[son] += lazy[rt] * ( len - ( len >> 1 ) ); lazy[son] += lazy[rt];
		son = rt << 1 | 1; num[son] += lazy[rt] * ( len >> 1 ); lazy[son] += lazy[rt];
		lazy[rt] = 0;
	}
	return ;
}

void update( int rt, int left, int right, int l, int r, LL val ) {
	if( left == l && right == r ) {
		num[rt] += val * ( r - l + 1 );
		if( l != r ) lazy[rt] += val;
		return ;
	}
	dowork( rt, right - left + 1 );
	int mid = ( left + right ) >> 1;
	if( r <= mid ) update( lson, l, r, val );
	else if( l > mid ) update( rson, l, r, val );
	else {
		update( lson, l, mid, val );
		update( rson, mid + 1, r, val );
	}
	num[rt] = num[rt << 1] + num[rt << 1 | 1];
	return ;
}

LL query( int rt, int left, int right, int l, int r ) {
	if( left == l && right == r ) return num[rt];
	dowork( rt, right - left + 1 );
	int mid = ( left + right ) >> 1;
	if( r <= mid ) return query( lson, l, r );
	else if( l > mid ) return query( rson, l, r );
	return query( lson, l, mid ) + query( rson, mid + 1, r );
}

int main() {
	int a, b, c;
	char st[2];
	memset( num, 0, sizeof( num ) );
	scanf( "%d%d", &n, &q );
	build( 1, 1, n );
	while( q-- ) {
		scanf( "%s", st );
		if( st[0] == 'Q' ) {
			scanf( "%d%d", &a, &b );
			printf( "%I64d\n", query( 1, 1, n, a, b ) );
		} else {
			scanf( "%d%d%d", &a, &b, &c );
			update( 1, 1, n, a, b, c );
		}
	}
	return 0;
}
