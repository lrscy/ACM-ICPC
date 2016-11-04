#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6000 + 10;

struct Node { int to, next; };
Node es[MAXN << 2];
int head[MAXN], val[MAXN], dp[MAXN][2];
int n, cnt;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u, int fa ) {
    dp[u][0] = 0;
    dp[u][1] = val[u];
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs( v, u );
        dp[u][0] += max( dp[v][0], dp[v][1] );
        dp[u][1] += dp[v][0];
    }
    return ;
}

int main() {
    int ta, tb;
    while( ~scanf( "%d", &n ) ) {
        memset( head, -1, sizeof( head ) );
        memset( dp, 0, sizeof( dp ) );
        cnt = 0;
        for( int i = 1; i <= n; ++i ) scanf( "%d", val + i );
        while( scanf( "%d%d", &ta, &tb ) && ta + tb ) { add( ta, tb ); add( tb, ta ); }
        dfs( 1, -1 );
        printf( "%d\n", max( dp[1][0], dp[1][1] ) );
    }
    return 0;
}
