#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1e3 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXN << 2];
int head[MAXN], dp[MAXN][MAXN], dist[MAXN][MAXN], w[MAXN], d[MAXN], best[MAXN];
int n, cnt;

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u, int fa, int len, int root ) {
    dist[root][u] = len;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs( v, u, len + es[i].cost, root );
    }
    return ;
}

void solve( int u, int fa ) {
    for( int i = 1; i <= n; ++i ) if( dist[u][i] <= d[u] ) dp[u][i] = w[i];
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        solve( v, u );
        for( int j = 1; j <= n; ++j ) {
            if( dist[u][j] <= d[u] )
                dp[u][j] += min( dp[v][j] - w[j], best[v] );
        }
    }
    for( int i = 1; i <= n; ++i ) best[u] = min( best[u], dp[u][i] );
    return ;
}

int main() {
    int t, ta, tb, tc;
    scanf( "%d", &t );
    while( t-- ) {
        memset( best, 0x3F, sizeof( best ) );
        memset( head, -1, sizeof( head ) );
        memset( dp, 0x3F, sizeof( dp ) );
        cnt = 0;
        scanf( "%d", &n );
        for( int i = 1; i <= n; ++i ) scanf( "%d", w + i );
        for( int i = 1; i <= n; ++i ) scanf( "%d", d + i );
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d%d", &ta, &tb, &tc );
            add( ta, tb, tc ); add( tb, ta, tc );
        }
        for( int i = 1; i <= n; ++i ) dfs( i, 0, 0, i );
        solve( 1, 0 );
        printf( "%d\n", best[1] );
    }
    return 0;
}
