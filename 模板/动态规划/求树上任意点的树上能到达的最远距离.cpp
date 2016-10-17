#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 50000 + 10;
const int MAXM = 100000 + 10;

struct Edge { int v, w, next; };
Edge es[MAXM];
int head[MAXN], mmax[MAXN][2], poi[MAXN][2], dis[MAXN], disf[MAXN][2], mlog[MAXN];
int d1[MAXN][17], d2[MAXN][17];
int n, m, cnt;

void add( int u, int v, int w ) {
    es[cnt].v = v; es[cnt].w = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u, int pre ) {
    bool flag = false;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].v, w = es[i].w;
        if( v != pre ) {
            flag = true;
            dfs( v, u );
            if( mmax[u][0] < mmax[v][0] + w ) {
                mmax[u][1] = mmax[u][0];
                mmax[u][0] = mmax[v][0] + w;
                poi[u][1] = poi[u][0];
                poi[u][0] = v;
            } else if( mmax[u][1] < mmax[v][0] + w ) {
                mmax[u][1] = mmax[v][0] + w;
                poi[u][1] = v;
            }
        }
    }
    if( !flag ) {
        dis[u] = 0;
        mmax[u][0] = mmax[u][1] = 0;
        poi[u][0] = poi[u][1] = 0;
    }
    return ;
}

void dfs2( int u, int pre ) {
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].v, w = es[i].w;
        if( v != pre ) {
            if( v == poi[u][0] ) {
                dis[v] = max( mmax[v][0], w + disf[u][0] );
                disf[v][0] = max( disf[u][0] + w, mmax[v][1] );
                disf[v][1] = max( disf[u][0] + w, mmax[v][0] );
            } else {
                dis[v] = max( mmax[v][0], w + disf[u][1] );
                disf[v][0] = max( disf[u][1] + w, mmax[v][1] );
                disf[v][1] = max( disf[u][1] + w, mmax[v][0] );
            }
            dfs2( v, u );
        }
    }
    return ;
}

int main() {
    int a, b, c, q;
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        memset( head, -1, sizeof( head ) );
        memset( mmax, 0, sizeof( mmax ) );
        memset( dis, 0, sizeof( dis ) );
        cnt = 0;
        add( 0, 1, 0 );
        for( int i = 0; i < n - 1; ++i ) {
            scanf( "%d%d%d", &a, &b, &c );
            add( a, b, c ); add( b, a, c );
        }
        dfs( 0, 0 );
        disf[0][0] = disf[0][1] = 0;
        poi[0][0] = 1; poi[0][1] = 0;
        dfs2( 0, 0 );
    }
    return 0;
}
