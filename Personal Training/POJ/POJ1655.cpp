#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 2e4 + 10;

struct Edge { int to, next; };
Edge es[MAXN << 4];
int head[MAXN], son[MAXN], dp[MAXN];
int n, cnt, nmin, id;

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
    if( dp[u] < nmin ) {
        id = u; nmin = dp[u];
    } else if( dp[u] == nmin && id < u ) {
        id = u;
    }
    return ;
}

int main() {
    int t, ta, tb;
    scanf( "%d", &t );
    while( t-- ) {
        memset( head, -1, sizeof( head ) );
        cnt = 0; nmin = INF;
        scanf( "%d", &n );
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            add( ta, tb ); add( tb, ta );
        }
        dfs( 1, -1 );
        printf( "%d %d\n", id, nmin );
    }
    return 0;
}
