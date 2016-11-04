#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 200000 + 10;
const double eps = 1e-8;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

struct Node { double x1, x2, y; int flag; } node[MAXN];
double x[MAXN];
int len[MAXN << 2];
double tmp, ans;
int n, m;

bool cmp( const Node &a, const Node &b ) {
	return a.y - b.y < eps;
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
	int tt = 0;
	double x1, y1, x2, y2;
	while( ~scanf( "%d", &m ) && m ) {
		printf( "Test case #%d\n", ++tt );
		n = 0;
		memset( len, 0, sizeof( len ) );
		for( int i = 0; i < m; ++i ) {
			scanf( "%lf%lf%lf%lf", &x1, &y1, &x2, &y2 );
			node[n].x1 = x1; node[n].x2 = x2; node[n].y = y1;
			node[n].flag = 1; x[n++] = x1;
			node[n].x1 = x1; node[n].x2 = x2; node[n].y = y2;
			node[n].flag = -1; x[n++] = x2;
		}
		sort( node, node + n, cmp );
		sort( x, x + n );
		int tn = unique( x, x + n ) - x;
		ans = 0;
		int x1, x2;
		x1 = lower_bound( x, x + tn, node[0].x1 ) - x + 1;
		x2 = lower_bound( x, x + tn, node[0].x2 ) - x + 1;
		update( 1, 1, tn - 1, x1, x2 - 1, node[0].flag );
		for( int i = 1; i < n; ++i ) {
			tmp = 0;
			query( 1, 1, tn - 1 );
			ans += tmp * ( node[i].y - node[i - 1].y );
			x1 = lower_bound( x, x + tn, node[i].x1 ) - x + 1;
			x2 = lower_bound( x, x + tn, node[i].x2 ) - x + 1;
			update( 1, 1, tn - 1, x1, x2 - 1, node[i].flag );
		}
		printf( "Total explored area: %.2f\n\n", ans );
	}
	return 0;
}
