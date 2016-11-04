#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

struct Node { int x1, x2, y, flag; };
Node node[MAXN];
int len[MAXN << 2], x[MAXN];
LL ans;
int n, cnt, tmp;

bool cmp( const Node &a, const Node &b ) {
	return a.y < b.y;
}

void dowork( int rt ) {
	if( len[rt] ) {
		len[rt << 1] += len[rt];
		len[rt << 1 | 1] += len[rt];
		len[rt] = 0;
	}
	return ;
}

void update( int rt, int left, int right, int l, int r, int val ) {
	if( left == l && r == right && ( val > 0 || ( len[rt] > 0 && val < 0 ) ) ) {
		len[rt] += val;
		return ;
	}
	if( left == right ) { len[rt] += val; return ; }
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
	if( len[rt] ) {
		tmp += x[right] - x[left - 1];
		return ;
	}
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	query( lson ); query( rson );
	return ;
}

int main() {
	int x1, y1, x2, y2;
	while( true ) {
		memset( len, 0, sizeof( len ) );
		bool tflag = false;
		n = cnt = 0;
		while( ~scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 ) && 
				( ~x1 || ~y1 || ~x2 || ~y2 ) ) {
			tflag = true;
			node[cnt++] = { x1, x2, y1, 1 };
			node[cnt++] = { x1, x2, y2, -1 };
			x[n++] = x1; x[n++] = x2;
		}
		if( !tflag ) break;
		sort( node, node + cnt, cmp );
		sort( x, x + n );
		int tn = unique( x, x + n ) - x;
		ans = 0;
		int t1 = lower_bound( x, x + tn, node[0].x1 ) - x + 1;
		int t2 = lower_bound( x, x + tn, node[0].x2 ) - x + 1;
		update( 1, 1, tn - 1, t1, t2 - 1, node[0].flag );
		for( int i = 1; i < n; ++i ) {
			tmp = 0;
			query( 1, 1, tn - 1 );
			ans += 1LL * tmp * ( node[i].y - node[i - 1].y );
			t1 = lower_bound( x, x + tn, node[i].x1 ) - x + 1;
			t2 = lower_bound( x, x + tn, node[i].x2 ) - x + 1;
			update( 1, 1, tn - 1, t1, t2 - 1, node[i].flag );
		}
		printf( "%I64d\n", ans );
	}
	return 0;
}
