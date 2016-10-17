#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXN << 2];
int head[MAXN], nmax[MAXN][2], son[MAXN][2];
int n, cnt;

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs1( int u, int fa ) {
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs1( v, u );
        int tmp = nmax[v][0] + es[i].cost;
        if( tmp > nmax[u][0] ) {
            nmax[u][1] = nmax[u][0]; son[u][1] = son[u][0];
            nmax[u][0] = tmp; son[u][0] = v;
        } else if( tmp > nmax[u][1] ) {
            nmax[u][1] = tmp; son[u][1] = v;
        }
    }
    return ;
}

void dfs2( int u, int fa, int len ) {
    int tmp;
    if( son[fa][0] != u ) tmp = len + nmax[fa][0];
    else tmp = len + nmax[fa][1];
    if( tmp > nmax[u][0] ) {
        nmax[u][1] = nmax[u][0]; son[u][1] = son[u][0];
        nmax[u][0] = tmp; son[u][0] = fa;
    } else if( tmp > nmax[u][1] ) {
        nmax[u][1] = tmp; son[u][1] = fa;
    }
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs2( v, u, es[i].cost );
    }
    return ;
}

int main() {
    int ta, tb;
    while( ~scanf( "%d", &n ) ) {
        memset( head, -1, sizeof( head ) );
        memset( nmax, 0, sizeof( nmax ) );
        memset( son, -1, sizeof( son ) );
        for( int i = 2; i <= n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            add( i, ta, tb );
            add( ta, i, tb );
        }
        dfs1( 1, 0 );
        dfs2( 1, 0, 0 );
        for( int i = 1; i <= n; ++i ) printf( "%d\n", nmax[i][0] );
    }
    return 0;
}
