#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 500000;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

struct Node {
	int val, id;
	bool operator < ( const Node &tmp ) const { return val < tmp.val; }
};
Node node[MAXN];
LL cnt[MAXN << 2];
int a[MAXN], num[MAXN];
int n;

void update( int rt, int left, int right, int val ) {
	++cnt[rt];
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	if( val <= mid ) update( lson, val );
	else update( rson, val );
	return ;
}

LL query( int rt, int left, int right, int l, int r ) {
	if( left == l && right == r ) return cnt[rt];
	int mid = ( left + right ) >> 1;
	if( r <= mid ) return query( lson, l, r );
	else if( l > mid ) return query( rson, l, r );
	return query( lson, l, mid ) + query( rson, mid + 1, r );
}

int main() {
	while( ~scanf( "%d", &n ) && n ) {
		memset( cnt, 0, sizeof( cnt ) );
		for( int i = 0; i < n; ++i ) {
			scanf( "%d", a + i );
			node[i].val = a[i];
			node[i].id = i;
		}
		sort( node, node + n );
		for( int i = 0; i < n; ++i ) num[node[i].id] = i + 1;
		LL ans = 0;
		for( int i = 0; i < n; ++i ) {
			int tmp = num[i];
			ans += query( 1, 1, n + 1, tmp + 1, n + 1 );
			update( 1, 1, n + 1, tmp );
		}
		printf( "%lld\n", ans );
	}
	return 0;
}
