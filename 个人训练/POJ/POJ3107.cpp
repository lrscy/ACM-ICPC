#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1e5 + 10;

struct Edge { int to, next; };
Edge es[MAXN << 2];
int head[MAXN], son[MAXN], dp[MAXN], ans[MAXN];
int n, m, cnt, nmin;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u, int fa ) {
    son[u] = 1; dp[u] = 0;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs( v, u );
        son[u] += son[v];
        dp[u] = max( dp[u], son[v] );
    }
    dp[u] = max( dp[u], n - son[u] );
    nmin = min( nmin, dp[u] );
    return ;
}

int main() {
    int ta, tb;
    while( ~scanf( "%d", &n ) ) {
        memset( head, -1, sizeof( head ) );
        cnt = 0; nmin = INF;
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            add( ta, tb ); add( tb, ta );
        }
        dfs( 1, -1 );
        int tn = 0;
        for( int i = 1; i <= n; ++i ) {
            if( dp[i] == nmin ) ans[tn++] = i;
        }
        for( int i = 0; i < tn - 1; ++i ) printf( "%d ", ans[i] );
        printf( "%d\n", ans[tn - 1] );
    }
    return 0;
}
