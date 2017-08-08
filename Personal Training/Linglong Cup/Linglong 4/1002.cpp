#include <bits/stdc++.h>
using namespace std;
typedef long long MyType;
const int INF = 0x3F3F3F3F;
const int MAXN = 210;
const int MAXE = 1e5 + 10;

struct Edge { int to, next; MyType cap, cost; };
Edge es[MAXE];
int head[MAXN], que[MAXE], dis[MAXN], pre[MAXN], d[MAXN][MAXN];
bool vis[MAXN];
int n, m, tn, cnt, src, des;

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
    memset( dis, 0x3F, sizeof( dis ) );
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
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( head, -1, sizeof head );
        memset( d, 0x3F, sizeof d );
        cnt = 0;
        scanf( "%d%d", &n, &m );
        tn = n + m;
        for( int i = 1; i <= tn; ++i ) {
            for( int j = 1; j <= tn; ++j ) {
                scanf( "%d", &d[i][j] );
                if( d[i][j] == -1 ) d[i][j] = INF;
            }
        }
        for( int k = 1; k <= tn; ++k ) {
            for( int i = 1; i <= tn; ++i )
                for( int j = 1; j <= tn; ++j )
                    d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
        }
        src = 0; des = tn + 1;
        for( int i = 1; i <= n; ++i ) add( src, i, 1, 0 );
        for( int i = 1; i <= n; ++i ) {
            for( int j = n + 1; j <= n + m; ++j )
                if( d[i][j] != INF )
                    add( i, j, 1, 10000 - d[i][j] );
        }
        for( int i = n + 1; i <= n + m; ++i ) add( i, des, 1, 0 );
        long long tmp = MCMF();
        int tot = 0;
        for( int i = head[des]; ~i; i = es[i].next ) if( es[i].cap ) ++tot;
        cout << tot * 10000 - tmp << endl;
    }
    return 0;
}
