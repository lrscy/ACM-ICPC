#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e4 + 10;

struct Edge{ int to, next; };
Edge es[MAXN << 2];
int head[MAXN], son[MAXN], dp[MAXN], ans[MAXN];
int n, m, cnt, nmin, tot;

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
    if( 2 * dp[u] <= n ) ans[tot++] = u;
    return ;
}

int main() {
    int ta, tb;
    while( ~scanf( "%d", &n ) ) {
        memset( head, -1, sizeof( head ) );
        cnt = tot = 0;
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            add( ta, tb ); add( tb, ta );
        }
        dfs( 1, -1 );
        if( tot == 0 ) puts( "NONE" );
        else {
            sort( ans, ans + tot );
            for( int i = 0; i < tot; ++i ) printf( "%d\n", ans[i] );
        }
    }
    return 0;
}
