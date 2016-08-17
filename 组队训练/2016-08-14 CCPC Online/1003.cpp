#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXN << 2];
int head[MAXN], a[MAXN], down[MAXN][2], down2[MAXN], downb[MAXN], up[MAXN], upb[MAXN];
int n, cnt;

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs1( int u, int fa ) {
    down[u][0] = down2[u] = downb[u] = a[u];
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs1( v, u );
        downb[u] += max( 0, downb[v] - ( es[i].cost << 1 ) );
    }
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        int tmp = downb[u] - max( downb[v] - ( es[i].cost << 1 ), 0 ) + down[v][0] - es[i].cost;
        if( tmp > down[u][0] ) {
            if( down[u][1] ) down2[u] = down[u][0];
            down[u][0] = tmp;
            down[u][1] = v;
        } else if( tmp > down2[u] ) {
            down2[u] = tmp;
        }
    }
    return ;
}

void dfs2( int u, int fa ) {
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        up[v] = max( up[v], up[u] + downb[u] - max( downb[v] - ( es[i].cost << 1 ), 0 ) - es[i].cost );
        if( down[u][1] != v ) up[v] = max( up[v], upb[u] + down[u][0] - max( downb[v] - ( es[i].cost << 1 ), 0 ) - es[i].cost );
        else up[v] = max( up[v], upb[u] + down2[u] - max( downb[v] - ( es[i].cost << 1 ), 0 ) - es[i].cost );
        upb[v] = max( upb[v], upb[u] + downb[u] - max( downb[v] - ( es[i].cost << 1 ), 0 ) - ( es[i].cost << 1 ) );
        dfs2( v, u );
    }
    return ;
}

int main() {
    int t, tt = 0, ta, tb, tc;
    scanf( "%d", &t );
    while( t-- ) {
        printf( "Case #%d:\n", ++tt );
        memset( head, -1, sizeof( head ) );
        cnt = 0;
        scanf( "%d", &n );
        for( int i = 0; i <= n; ++i ) upb[i] = up[i] = 0;
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d%d", &ta, &tb, &tc );
            add( ta, tb, tc );
            add( tb, ta, tc );
        }
        dfs1( 1, 0 );
        dfs2( 1, 0 );
        for( int i = 1; i <= n; ++i ) printf( "%d\n", max( down[i][0] + upb[i], downb[i] + up[i] ) );
    }
    return 0;
}
