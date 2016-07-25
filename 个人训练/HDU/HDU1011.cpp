#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXN];
int head[MAXN], a[MAXN], b[MAXN], dp[MAXN][MAXN];
int n, m, cnt;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u, int fa ) {
    int num = ( a[u] + 19 ) / 20;
    for( int i = num; i <= m; ++i ) dp[u][i] = b[u];
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs( v, u );
        for( int j = m; j >= num; --j ) {
            for( int k = num; k < j; ++k )
                dp[u][j] = max( dp[u][j], dp[u][k] + dp[v][j - k] );
        }
    }
    return ;
}

int main() {
    int ta, tb;
    while( ~scanf( "%d%d", &n, &m ) && ( ~n && ~m ) ) {
        memset( head, -1, sizeof( head ) );
        memset( dp, 0, sizeof( dp ) );
        cnt = 0;
        for( int i = 1; i <= n; ++i ) scanf( "%d%d", a + i, b + i );
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            add( ta, tb ); add( tb, ta );
        }
        if( m == 0 ) puts( "0" );
        else {
            dfs( 1, -1 );
            printf( "%d\n", dp[1][m] );
        }
    }
    return 0;
}
