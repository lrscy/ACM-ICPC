#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 2e2 + 10;

struct Edge { int to, next; };
Edge es[MAXN << 2];
int head[MAXN], dp[MAXN][MAXN][2], a[MAXN];
int n, m, cnt;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u ) {
    for( int i = 0; i <= m; ++i ) dp[u][i][0] = dp[u][i][1] = a[u];
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        dfs( v );
        for( int j = m; j >= 0; --j ) {
            for( int k = 0; k <= j; ++k ) {
                dp[u][j + 2][0] = max( dp[u][j + 2][0], dp[u][j - k][0] + dp[v][k][0] );
                dp[u][j + 2][1] = max( dp[u][j + 2][1], dp[u][j - k][1] + dp[v][k][0] );
                dp[u][j + 1][1] = max( dp[u][j + 1][1], dp[u][j - k][0] + dp[v][k][1] );
            }
        }
    }
    return ;
}

int main() {
    int ta, tb;
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( head, -1, sizeof( head ) );
        memset( dp, 0, sizeof( dp ) );
        cnt = 0;
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            if( ta < tb ) add( ta, tb );
            else add( tb, ta );
        }
        dfs( 1 );
        printf( "%d\n", dp[1][m][1] );
    }
    return 0;
}
