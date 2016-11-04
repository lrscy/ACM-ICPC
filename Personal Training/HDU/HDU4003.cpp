#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXN << 2];
int head[MAXN], dp[MAXN][15];
int n, m, s, cnt;

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u, int fa ) {
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs( v, u );
        for( int j = m; j >= 0; --j ) {
            dp[u][j] += dp[v][0] + 2 * es[i].cost;
            for( int k = 1; k <= j; ++k )
                dp[u][j] = min( dp[u][j], dp[u][j - k] + dp[v][k] + k * es[i].cost );
        }
    }
    return ;
}

int main() {
    int ta, tb, tc;
    while( ~scanf( "%d%d%d", &n, &s, &m ) ) {
        memset( dp, 0, sizeof( dp ) );
        memset( head, -1, sizeof( head ) );
        cnt = 0;
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d%d", &ta, &tb, &tc );
            add( ta, tb, tc ); add( tb, ta, tc );
        }
        dfs( s, -1 );
        printf( "%d\n", dp[s][m] );
    }
    return 0;
}
