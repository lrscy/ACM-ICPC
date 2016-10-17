#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const int INF = 0x3F3F3F3F;
const int MAXN = 1000000 + 10;

struct Point {
	int x, y, id;
	bool operator < ( const Point &p ) const {
		return x == p.x ? y < p.y : x < p.x;
	}
} poi[MAXN];
struct BIT {
	int minVal, pos;
	void init() { minVal = INF; pos = -1; }
} bit[MAXN << 2];
struct Edge {
	int u, v, cost;
	bool operator < ( const Edge &e ) const {
		return cost < e.cost;
	}
} es[MAXN << 2];
int fa[MAXN], a[MAXN], b[MAXN];
int n, k, cnt;

int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }

void add( int u, int v, int w ) {
	es[cnt].u = u; es[cnt].v = v; es[cnt].cost = w; ++cnt;
	return ;
}

int lowbit( int x ) { return x & -x; }

void update( int i, int val, int pos ) {
	while( i ) {
		if( val < bit[i].minVal ) {
			bit[i].minVal = val;
			bit[i].pos = pos;
		}
		i -= lowbit( i );
	}
	return ;
}

int ask( int i, int m ) {
	int minVal = INF, pos = -1;
	while( i <= m ) {
		if( bit[i].minVal < minVal ) {
			minVal = bit[i].minVal;
			pos = bit[i].pos;
		}
		i += lowbit( i );
	}
	return pos;
}

int dist( const Point &a, const Point &b ) {
	return abs( a.x - b.x ) + abs( a.y - b.y );
}

int MHT( int k ) {
	cnt = 0;
	for( int dir = 0; dir < 4; ++dir ) {
		if( dir == 1 || dir == 3 ) {
			for( int i = 0; i < n; ++i ) swap( poi[i].x, poi[i].y );
		}
		if( dir == 2 ) {
			for( int i = 0; i < n; ++i ) poi[i].x *= -1;
		}
		sort( poi, poi + n );
		for( int i = 0; i < n; ++i ) a[i] = b[i] = poi[i].y - poi[i].x;
		sort( b, b + n );
		int ncnt = unique( b, b + n ) - b;
		for( int i = 1; i <= ncnt; ++i ) bit[i].init();
		for( int i = n - 1; i >= 0; --i ) {
			int pos = lower_bound( b, b + ncnt, a[i] ) - b + 1;
			int ans = ask( pos, ncnt );
			if( ans != -1 ) add( poi[i].id, poi[ans].id, dist( poi[i], poi[ans] ) );
			update( pos, poi[i].x + poi[i].y, i );
		}
	}
	sort( es, es + cnt );
	for( int i = 0; i < n; ++i ) fa[i] = i;
	for( int i = 0; i < cnt; ++i ) {
		int u = es[i].u, v = es[i].v;
		int x = mfind( u ), y = mfind( v );
		if( x != y ) {
			--k;
			fa[x] = y;
			if( k == 0 ) return es[i].cost;
		}
	}
	return 0;
}

int main() {
	while( ~scanf( "%d%d", &n, &k ) ) {
		for( int i = 0; i < n; ++i ) {
			scanf( "%d%d", &poi[i].x, &poi[i].y );
			poi[i].id = i;
		}
		printf( "%d\n", MHT( n - k ) );
	}
	return 0;
}
