#include <bits/stdc++.h>
using namespace std;
typedef int MyType;
const int INF = 0x3F3F3F3F;
const int MAXN = 1e3 + 10;
const int MAXE = 1e4 + 10;

struct Edge { int to, next; MyType cap; };
Edge es[MAXE << 1];
int head[MAXN], cur[MAXN], level[MAXN], que[MAXN];
int n, m, k, cnt, src, des;

void add( int u, int v, MyType c ) {
    es[cnt].to = v; es[cnt].cap = c; es[cnt].next = head[u]; head[u] = cnt++;
    es[cnt].to = u; es[cnt].cap = 0; es[cnt].next = head[v]; head[v] = cnt++;
    return ;
}

bool bfs() {
    int mf, me;
    memset( level, 0, sizeof( level ) );
    mf = me = 0;
    que[me++] = src;
    level[src] = 1;
    while( mf < me ) {
        int u = que[mf++];
        for( int i = head[u]; ~i; i = es[i].next ) {
            int v = es[i].to;
            if( level[v] == 0 && es[i].cap > 0 ) {
                level[v] = level[u] + 1;
                que[me++] = v;
            }
        }
    }
    return ( level[des] != 0 );
}

MyType dfs( int u, MyType f ) {
    if( u == des || f == 0 ) return f;
    MyType flow = 0;
    for( int &i = cur[u]; ~i; i = es[i].next ) {
        Edge &e = es[i];
        if( e.cap > 0 && level[e.to] == level[u] + 1 ) {
            MyType d = dfs( e.to, min( f, e.cap ) );
            if( d > 0 ) {
                e.cap -= d;
                es[i ^ 1].cap += d;
                flow += d;
                f -= d;
                if( f == 0 ) break;
            } else level[e.to] = -1;
        }
    }
    return flow;
}

MyType dinic() {
    MyType ret = 0;
    while( bfs() ) {
        for( int i = src; i <= des; ++i ) cur[i] = head[i];
        ret += dfs( src, INF );
    }
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( head, -1, sizeof head ); cnt = 0;
        scanf( "%d%d%d", &n, &m, &k );
        src = 0; des = 2 * n + 1;
        for( int i = 0, u, v, w; i < m; ++i ) {
            scanf( "%d%d%d", &u, &v, &w );
            add( u + n, v, w );
        }
        for( int i = 1, tmp; i <= n; ++i ) {
            scanf( "%d", &tmp );
            add( src, i, tmp );
        }
        for( int i = 1, tmp; i <= n; ++i ) {
            scanf( "%d", &tmp );
            add( i, i + n, tmp );
        }
        add( k + n, des, INF );
        printf( "%d\n", dinic() );
    }
    return 0;
}
