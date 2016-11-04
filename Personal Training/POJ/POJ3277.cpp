#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

struct Node { int a, b, c; } node[MAXN];
LL h[MAXN << 2], ans;
bool lazy[MAXN << 2];
int num[MAXN];
int n, m;

bool cmp( const Node &a, const Node &b ) {
	return a.c < b.c;
}

void dowork( int rt ) {
	if( lazy[rt] ) {
		int son = rt << 1; h[son] = h[rt]; lazy[son] = true;
		son = rt << 1 | 1; h[son] = h[rt]; lazy[son] = true;
		lazy[rt] = false;
	}
	return ;
}

void update( int rt, int left, int right, int l, int r, int val ) {
	if( left == l && r == right ) { h[rt] = val; lazy[rt] = true; return ; }
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
		ans += 1LL * ( num[right] - num[left - 1] ) * h[rt];
		return ;
	}
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	query( lson ); query( rson );
	return ;
}

int main() {
	n = 0; ans = 0;
	memset( h, 0, sizeof( h ) );
	memset( lazy, 0, sizeof( lazy ) );
	scanf( "%d", &m );
	for( int i = 0; i < m; ++i ) {
		scanf( "%d%d%d", &node[i].a, &node[i].b, &node[i].c );
		num[n++] = node[i].a;
		num[n++] = node[i].b;
	}
	sort( num, num + n );
	n = unique( num, num + n ) - num;
	sort( node, node + m, cmp );
	for( int i = 0; i < m; ++i ) {
		int x, y;
		x = lower_bound( num, num + n, node[i].a ) - num + 1;
		y = lower_bound( num, num + n, node[i].b ) - num + 1;
		update( 1, 1, n - 1, x, y - 1, node[i].c );
	}
	query( 1, 1, n - 1 );
	printf( "%lld\n", ans );
	return 0;
}
