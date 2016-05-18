#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e4 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

struct Node { int x1, x2, y, flag; } node[MAXN];
int num[MAXN << 2], len[MAXN << 2], lcover[MAXN << 2], rcover[MAXN << 2], seg[MAXN << 2], x[MAXN];
int n, cnt, ans;

bool cmp( const Node &a, const Node &b ) {
	return a.y == b.y ? a.flag > b.flag : a.y < b.y;
}

void build( int rt, int left, int right ) {
	memset( lcover, 0, sizeof( lcover ) );
	memset( rcover, 0, sizeof( rcover ) );
	memset( len, 0, sizeof( len ) );
	memset( num, 0, sizeof( num ) );
	memset( seg, 0, sizeof( seg ) );
	return ;
}

void update( int rt, int left, int right, int l, int r, int val ) {
//	if( left == l && r == right && ( val > 0 || ( val < 0 && num[rt] > 0 ) ) ) {
//		num[rt] += val; len[rt] = ( x[right + 1] - x[left] ) * ( num[rt] > 0 );
//		seg[rt] = lcover[rt] = rcover[rt] = ( num[rt] > 0 );
//		return ;
//	}
	if( left == right ) {
		num[rt] += val; len[rt] = ( x[right + 1] - x[left] ) * ( num[rt] > 0 );
		seg[rt] = lcover[rt] = rcover[rt] = ( num[rt] > 0 );
		return ;
	}
	int mid = ( left + right ) >> 1, ls = rt << 1, rs = rt << 1 | 1;
	if( num[rt] ) {
		num[ls] += num[rt]; num[rs] += num[rt]; num[rt] = 0;
		seg[ls] = seg[rs] = seg[rt]; seg[rt] = 0;
		len[ls] = x[mid + 1] - x[left]; len[rs] = x[right + 1] - x[mid + 1]; len[rt] = 0;
		lcover[ls] = rcover[ls] = lcover[rs] = rcover[rs] = 1;
	}
	if( r <= mid ) update( lson, l, r, val );
	else if( l > mid ) update( rson, l, r, val );
	else { update( lson, l, mid, val ); update( rson, mid + 1, r, val ); }
	len[rt] = len[ls] + len[rs];
	seg[rt] = seg[ls] + seg[rs] - rcover[ls] * lcover[rs];
	lcover[rt] = lcover[ls]; rcover[rt] = rcover[rs];
	return ;
}

int main() {
	int x1, y1, x2, y2, pre;
	while( ~scanf( "%d", &n ) ) {
		cnt = 1; ans = 0; pre = 0;
		for( int i = 0; i < n; ++i ) {
			scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
			node[cnt] = { x1, x2, y1, 1 }; x[cnt++] = x1;
			node[cnt] = { x1, x2, y2, -1 }; x[cnt++] = x2;
		}
		sort( node + 1, node + cnt, cmp );
		sort( x + 1, x + cnt );
		int tn = unique( x + 1, x + cnt ) - x;
		build( 1, 1, tn - 2 );
		for( int i = 1; i < cnt; ++i ) {
			if( i != 1 ) ans += seg[1] * ( node[i].y - node[i - 1].y ) * 2;
			x1 = lower_bound( x + 1, x + tn, node[i].x1 ) - x;
			x2 = lower_bound( x + 1, x + tn, node[i].x2 ) - x;
			update( 1, 1, tn - 2, x1, x2 - 1, node[i].flag );
			ans += abs( len[1] - pre );
			pre = len[1];
		}
		printf( "%d\n", ans );
	}
	return 0;
}
