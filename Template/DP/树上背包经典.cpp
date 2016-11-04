#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int NINF = 0x80808080;
const int MAXN = 3e3 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXN << 2];
int head[MAXN], dp[MAXN][MAXN], val[MAXN], num[MAXN];
int n, m, tn, cnt;

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u, int fa ) {
    memset( dp[u], 0x80, sizeof( dp[u] ) ); dp[u][0] = 0;
    if( head[u] == -1 ) { dp[u][1] = val[u]; return ; }
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to, cost = es[i].cost;
        if( v == fa ) continue;
        dfs( v, u );
        num[u] += num[v];
        for( int j = num[u]; j >= 1; --j ) {
            for( int k = 0; k < j; ++k )
                dp[u][j] = max( dp[u][j], dp[u][k] + dp[v][j - k] - cost );
        }
    }
    return ;
}

int main() {
    int ta, tb;
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( head, -1, sizeof( head ) );
        memset( num, 0, sizeof( num ) );
        cnt = 0;
        for( int i = 1; i <= n - m; ++i ) {
            scanf( "%d", &tn );
            for( int j = 0; j < tn; ++j ) {
                scanf( "%d%d", &ta, &tb );
                add( i, ta, tb );
            }
            val[i] = 0;
        }
        for( int i = n - m + 1; i <= n; ++i ) { scanf( "%d", val + i ); num[i] = 1; }
        dfs( 1, -1 );
        for( int i = num[1]; i >= 0; --i ) {
            if( dp[1][i] >= 0 ) {
                printf( "%d\n", i );
                break;
            }
        }
    }
    return 0;
}
