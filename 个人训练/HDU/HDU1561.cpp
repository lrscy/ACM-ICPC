#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;

struct Edge { int to, next; };
Edge es[MAXN << 1];
int head[MAXN], val[MAXN], dp[MAXN][MAXN];
int n, m, cnt;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
}

int dfs( int u ) {
    int tot = 1;
    dp[u][1] = val[u];
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        tot += dfs( v );
        for( int j = tot; j >= 1; --j ) {
            for( int k = 0; k < j; ++k )
                dp[u][j] = max( dp[u][j], dp[u][j - k] + dp[v][k] );
        }
    }
    return tot;
}

int main() {
    int a;
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        memset( head, -1, sizeof( head ) );
        memset( dp, 0, sizeof( dp ) );
        cnt = 0; val[0] = 0;
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d%d", &a, val + i );
            add( a, i );
        }
        dfs( 0 );
        printf( "%d\n", dp[0][m + 1] );
    }
    return 0;
}
