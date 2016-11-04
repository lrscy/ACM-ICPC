#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 2e4 + 10;
const int MAXM = 30;

struct Edge { int to, next; };
Edge es[MAXN << 1];
int head[MAXN], dp[MAXN << 1][MAXM], num[MAXN];
int ver[MAXN << 1], dep[MAXN << 1], first[MAXN];
bool vis[MAXN];
int n, m, cnt, tot;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs1( int u, int depth ) {
    vis[u] = true; ver[++tot] = u; dep[tot] = depth; first[u] = tot;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( !vis[v] ) {
            dfs1( v, depth + 1 );
            ver[++tot] = u;
            dep[tot] = depth;
        }
    }
    return ;
}

void st() {
    for( int i = 1; i <= n; ++i ) dp[i][0] = i;
    for( int j = 1; ( 1 << j ) <= n; ++j ) {
        for( int i = 1; i + ( 1 << j ) - 1 <= n; ++i ) {
            int a = dp[i][j - 1], b = dp[i + ( 1 << ( j - 1 ) )][j - 1];
            dp[i][j] = dep[a] < dep[b] ? a : b;
        }
    }
    return ;
}

int rmq( int l, int r ) {
    int k = 0;
    while( ( 1 << ( k + 1 ) ) <= r - l + 1 ) ++k;
    int a = dp[l][k], b = dp[r - ( 1 << k ) + 1][k];
    return dep[a] < dep[b] ? a : b;
}

int lca( int u, int v ) {
    int x = first[u], y = first[v];
    if( x > y ) swap( x, y );
    int pos = rmq( x, y );
    return ver[pos];
}

void dfs2( int u, int fa ) {
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs2( v, u );
        num[u] += num[v];
    }
    return ;
}

int main() {
    int t, u, v;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        memset( vis, false, sizeof( vis ) );
        memset( head, -1, sizeof( head ) );
        memset( num, 0, sizeof( num ) );
        cnt = tot = 0;
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < n - 1; ++i ) {
            scanf( "%d%d", &u, &v );
            add( u, v ); add( v, u );
        }
        dfs1( 1, 0 ); st();
        for( int i = n; i <= m; ++i ) {
            scanf( "%d%d", &u, &v );
            int tt = lca( u, v );
            ++num[u]; ++num[v]; num[tt] -= 2;
        }
        dfs2( 1, 1 );
        int ans = INF;
        for( int i = 2; i <= n; ++i ) {
            ans = min( ans, num[i] + 1 );
        }
        printf( "Case #%d: %d\n", ncas, ans );
    }
    return 0;
}
