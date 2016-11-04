#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100000 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

int cnt[MAXN << 2], ans[MAXN];
int n;

void update( int rt, int left, int right, int tx ) {
	++cnt[rt];
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	if( tx <= mid ) update( lson, tx );
	else update( rson, tx );
	return ;
}

int query( int rt, int left, int right, int l, int r ) {
	if( left == l && r == right ) return cnt[rt];
	int mid = ( left + right ) >> 1;
	if( r <= mid ) return query( lson, l, r );
	else if( l > mid ) return query( rson, l, r );
	return query( lson, l, mid ) + query( rson, mid + 1, r );
}

int main() {
	int tx, ty;
	memset( cnt, 0, sizeof( cnt ) );
	memset( ans, 0, sizeof( ans ) );
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) {
		scanf( "%d%d", &tx, &ty );
		++tx;
		int tmp = query( 1, 1, MAXN, 1, tx );
		++ans[tmp];
		update( 1, 1, MAXN, tx );
	}
	for( int i = 0; i < n; ++i ) printf( "%d\n", ans[i] );
	return 0;
}
