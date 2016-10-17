#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef int MyType;
const MyType INF = 0x7F7F7F7F;
const int MAXN = 1000 + 10;
const int MAXE = 100000 + 10;

struct Edge { int to, next; MyType cap, cost; };
Edge es[MAXE];
int head[MAXN], que[MAXE], dis[MAXN], pre[MAXN];
bool vis[MAXN];
int n, m, cnt, src, des;

void add( int u, int v, MyType f, MyType c ) {
    es[cnt].to = v; es[cnt].cap = f; es[cnt].cost = c;
    es[cnt].next = head[u]; head[u] = cnt++;
    es[cnt].to = u; es[cnt].cap = 0; es[cnt].cost = -c;
    es[cnt].next = head[v]; head[v] = cnt++;
    return ;
}

bool spfa() {
    int mf, me;
    memset( vis, false, sizeof( vis ) );
    memset( dis, 0x7F, sizeof( dis ) );
    memset( pre, -1, sizeof( pre ) );
    mf = me = 0;
    que[me++] = src; dis[src] = 0; vis[src] = true;
    while( mf < me ) {
        int u = que[mf++];
        for( int i = head[u]; ~i; i = es[i].next ) {
            int v = es[i].to;
            if( es[i].cap > 0 && dis[v] > dis[u] + es[i].cost ) {
                dis[v] = dis[u] + es[i].cost;
                pre[v] = i;
                if( !vis[v] ) {
                    vis[v] = true;
                    que[me++] = v;
                }
            }
        }
        vis[u] = false;
    }
    return dis[des] != INF;
}

MyType cflow() {
    MyType flow = INF;
    int u = des;
    while( ~pre[u] ) {
        u = pre[u];
        flow = min( flow, es[u].cap );
        u = es[u ^ 1].to;
    }
    u = des;
    while( ~pre[u] ) {
        u = pre[u];
        es[u].cap -= flow;
        es[u ^ 1].cap += flow;
        u = es[u ^ 1].to;
    }
    return flow;
}

MyType MCMF() {
    MyType mincost, maxflow;
    mincost = maxflow = 0;
    while( spfa() ) {
        MyType flow = cflow();
        maxflow += flow;
        mincost += flow * dis[des];
    }
    return mincost;
}

int main() {
    int a, b, c;
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( head, -1, sizeof( head ) );
        cnt = 0;
        src = 0; des = n + 1;
        add( src, 1, 2, 0 );
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d%d", &a, &b, &c );
            add( a, b, 1, c );
            add( b, a, 1, c );
        }
        add( n, des, 2, 0 );
        printf( "%d\n", MCMF() );
    }
    return 0;
}
