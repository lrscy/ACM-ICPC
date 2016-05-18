#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 2e5 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

int cnt[MAXN << 2], a[MAXN], b[MAXN], ans[MAXN];
int n, pos;

void build( int rt, int left, int right ) {
	int mid = ( left + right ) >> 1;
	cnt[rt] = right - left + 1;
	if( left == right ) return ;
	build( lson ); build( rson );
	return ;
}

void update( int rt, int left, int right, int val ) {
	int mid = ( left + right ) >> 1;
	--cnt[rt];
	if( left == right ) { pos = left; return ; }
	if( cnt[rt << 1] >= val ) {
		update( lson, val );
	} else {
		val -= cnt[rt << 1];
		update( rson, val );
	}
	return ;
}

int main() {
	while( ~scanf( "%d", &n ) ) {
		build( 1, 1, n );
		for( int i = 0; i < n; ++i ) scanf( "%d%d", a + i, b + i );
		for( int i = n - 1; i >= 0; --i ) {
			update( 1, 1, n, a[i] + 1 );
			ans[pos] = b[i];
		}
		for( int i = 1; i < n; ++i ) printf( "%d ", ans[i] );
		printf( "%d\n", ans[n] );
	}
	return 0;
}
