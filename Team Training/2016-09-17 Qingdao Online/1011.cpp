#include <bits/stdc++.h>
using namespace std;
typedef int MyType;
const int INF = 0x3F3F3F3F;
const int MAXN = 1000 + 10;
const int MAXE = 10000 + 10;

struct Edge { int to, next; MyType cap; };
Edge es[MAXE << 2], es2[MAXE << 2];
int head[MAXN], head2[MAXN], cur[MAXN], level[MAXN], que[MAXE], dis[MAXN];
bool vis[MAXN];
int n, m, F, D, cnt, cnt2, src, des;

void add( int u, int v, MyType c ) {
    es[cnt].to = v; es[cnt].cap = c; es[cnt].next = head[u]; head[u] = cnt++;
    es[cnt].to = u; es[cnt].cap = 0; es[cnt].next = head[v]; head[v] = cnt++;
    return ;
}

void add2( int u, int v, MyType c ) {
    es2[cnt2].to = v; es2[cnt2].cap = c; es2[cnt2].next = head2[u]; head2[u] = cnt2++;
    es2[cnt2].to = u; es2[cnt2].cap = c; es2[cnt2].next = head2[v]; head2[v] = cnt2++;
    return ;
}

bool bfs() {
    int mf, me;
    memset( level, 0, sizeof( level ) );
    mf = me = 0;
    que[me++] = src;
    level[src] = 1;
    while( mf != me ) {
        int u = que[mf++];
        if( mf >= MAXE ) mf -= MAXE;
        for( int i = head[u]; ~i; i = es[i].next ) {
            int v = es[i].to;
            if( level[v] == 0 && es[i].cap > 0 ) {
                level[v] = level[u] + 1;
                que[me++] = v;
                if( me >= MAXE ) me -= MAXE;
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
        for( int i = src; i <= des; ++i ) {
            cur[i] = head[i];
        }
        ret += dfs( src, INF );
    }
    return ret;
}

void spfa( int s ) {
    int mf, me;
    memset( dis, 0x3F, sizeof( dis ) ); dis[s] = 0;
    memset( vis, false, sizeof( vis ) );
    mf = me = 0;
    que[me++] = s; vis[s] = true;
    while( mf != me ) {
        int u = que[mf++];
        if( mf >= MAXE ) mf -= MAXE;
        vis[u] = false;
        for( int i = head2[u]; ~i; i = es2[i].next ) {
            int v = es2[i].to;
            if( dis[v] > dis[u] + 1 ) {
                dis[v] = dis[u] + 1;
                if( !vis[v] ) {
                    vis[v] = true;
                    que[me++] = v;
                    if( me >= MAXE ) me -= MAXE;
                }
            }
        }
    }
    return ;
}

void build( int s ) {
    int mf, me;
    memset( vis, false, sizeof( vis ) );
    mf = me = 0;
    que[me++] = s; vis[s] = true;
    while( mf != me ) {
        int u = que[mf++];
        if( mf >= MAXE ) mf -= MAXE;
        for( int i = head2[u]; ~i; i = es2[i].next ) {
            int v = es2[i].to;
            if( dis[u] - dis[v] == 1 ) {
                add( u, v, es2[i].cap );
                if( !vis[v] ) {
                    que[me++] = v;
                    if( me >= MAXE ) me -= MAXE;
                }
            }
        }
    }
    return ;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( head, -1, sizeof( head ) ); cnt = 0;
        memset( head2, -1, sizeof( head2 ) ); cnt2 = 0;
        scanf( "%d%d", &n, &m );
        for( int i = 0, u, v, w; i < m; ++i ) {
            scanf( "%d%d%d", &u, &v, &w );
            add2( u, v, w );
        }
        spfa( n );
        build( 1 );
        src = 1; des = n;
        printf( "%d\n", dinic() );
    }
    return 0;
}
