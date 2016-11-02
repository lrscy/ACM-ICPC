#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int POW = 32;

struct Edge { int to, next, cost; };
Edge es[MAXN << 1];
int seq[MAXN << 1], dep[MAXN << 1], fir[MAXN], fa[MAXN];
int lg2[MAXN << 1], dp[MAXN << 1][POW], dis[MAXN];
int head[MAXN], a[MAXN];
int n, m, cnt2, tot;

void add( int u, int v, int w ) { es[cnt2].to = v; es[cnt2].cost = w; es[cnt2].next = head[u]; head[u] = cnt2++; }

void dfs( int u, int fu, int d ) {
    seq[++tot] = u; dep[tot] = d; fir[u] = tot; fa[u] = fu;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fu ) continue;
        dis[v] = dis[u] + es[i].cost;
        dfs( v, u, d + 1 );
        seq[++tot] = u; dep[tot] = d;
    }
}

void init_lca() {
    int tn = 2 * n - 1;
    lg2[0] = -1; for( int i = 1; i < ( MAXN << 1 ); ++i ) lg2[i] = ( ( i & ( i - 1 ) ) == 0 ) ? lg2[i - 1] + 1 : lg2[i - 1];
    for( int i = 1; i <= tn; ++i ) dp[i][0] = i;
    for( int j = 1; j < 20; ++j ) {
        for( int i = 1; i + ( 1 << j ) - 1 <= tn; ++i ) {
            int a = dp[i][j - 1], b = dp[i + ( 1 << ( j - 1 ) )][j - 1];
            dp[i][j] = dep[a] < dep[b] ? a : b;
        }
    }
}

int lca( int x, int y ) {
    int k = lg2[y - x + 1];
    int a = dp[x][k], b = dp[y - ( 1 << k ) + 1][k];
    return seq[ dep[a] < dep[b] ? a : b];
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( head, -1, sizeof head ); tot = cnt2 = 0;
        memset( dis, 0, sizeof dis );
        scanf( "%d%d", &n, &m );
        for( int i = 1, u, v, w; i < n; ++i ) { scanf( "%d%d%d", &u, &v, &w ); add( u, v, w ); add( v, u, w ); }
        dfs( 1, 0, 1 );
        init_lca();
        for( int i = 0, u, v, k; i < m; ++i ) {
            scanf( "%d%d", &u, &v );
            if( fir[u] > fir[v] ) swap( u, v );
            int tp = lca( fir[u], fir[v] );
            printf( "%d\n", dis[u] + dis[v] - 2 * dis[tp] );
        }
    }
    return 0;
}
