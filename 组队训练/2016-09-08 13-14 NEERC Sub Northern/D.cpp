#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3F3F3F3F3F3F3F3F;
const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;
const int MAXLEN = 2e5 + 10;

PII pii[MAXM];
struct Edge { int to, next; LL cost; };
Edge es[MAXM << 2];
LL val[MAXN], dis[MAXN];
int head[MAXN], que[MAXLEN];
bool vis[MAXN];
int n, m, cnt;

void add( int u, int v, LL w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void spfa( int src ) {
    int mf, me;
    mf = me = 0;
    memset( dis, 0x3F, sizeof( dis ) );
    memset( vis, false, sizeof( vis ) );
    dis[src] = 0; vis[src] = true; que[me++] = src; 
    while( mf != me ) {
        int u = que[mf++];
        if( mf >= MAXLEN ) mf -= MAXLEN;
        vis[u] = false;
        for( int i = head[u]; ~i; i = es[i].next ) {
            int v = es[i].to;
            if( dis[v] > dis[u] + es[i].cost ) {
                dis[v] = dis[u] + es[i].cost;
                if( !vis[v] ) {
                    vis[v] = true;
                    que[me++] = v;
                    if( me >= MAXLEN ) me -= MAXLEN;
                }
            }
        }
    }
    return ;
}

int main() {
//    freopen( "dwarf.in", "r", stdin );
//    freopen( "dwarf.out", "w+", stdout );
    int a, b, c, tot = 0;
    memset( head, -1, sizeof( head ) );
    cnt = 0;
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%I64d", val + i );
        add( 0, i, val[i] );
    }
    for( int i = 0; i < m; ++i ) {
        scanf( "%d%d%d", &a, &b, &c );
        add( b, a, val[c] );
        add( c, a, val[b] );
        if( a == 1 ) pii[tot++] = make_pair( b, c );
    }
    spfa( 0 );
    LL ans = dis[1];
    for( int i = 0; i < tot; ++i ) {
        ans = min( ans, dis[pii[i].first] + dis[pii[i].second] );
    }
    printf( "%I64d\n", ans );
    return 0;
}
