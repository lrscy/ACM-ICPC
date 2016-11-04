#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e3 + 10;

struct Edge { int to, next; };
Edge es[MAXN];
int head[MAXN], dp[MAXN][MAXN], son[MAXN];
int n, m, cnt;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u ) {
    int tot = 0;
    son[u] = 1;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        dfs( v );
        son[u] += son[v];
        ++tot;
    }
    dp[u][1] = tot;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        for( int j = son[u] + 1; j >= 2; --j ) {
            for( int k = 1; k < j; ++k )
                if( dp[u][k] < INF && dp[v][j - k] < INF )
                    dp[u][j] = min( dp[u][j], dp[u][k] - 1 + dp[v][j - k] );
        }
    }
    return ;
}

int main() {
    int ta, tb;
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( head, -1, sizeof( head ) );
        memset( dp, 0x7F, sizeof( dp ) );
        cnt = 0;
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            add( ta, tb );
        }
        dfs( 1 );
        int ans = dp[1][m];
        for( int i = 2; i <= n; ++i ) ans = min( ans, dp[i][m] + 1 );
        printf( "%d\n", ans );
    }
    return 0;
}
