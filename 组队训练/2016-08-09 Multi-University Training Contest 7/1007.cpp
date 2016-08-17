#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3F3F3F3F3F3F3F3F;
const int MAXN = 1e3 + 10;
const int MAXM = 1e5 + 10;

struct Edge{ int to, next; };
Edge es[MAXN << 2];
LL dis[MAXN];
int head[MAXN], c[MAXN], b[MAXN], que[MAXM], vis[MAXN];
int n, m, cnt;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void spfa() {
    int mf, me;
    memset( dis, 0x3F, sizeof( dis ) );
    memset( vis, 0, sizeof( vis ) );
    mf = me = 0; que[me++] = 1; dis[1] = 0; vis[1] = 1;
    while( mf != me ) {
        int u = que[mf++];
        if( mf >= MAXM ) mf -= MAXM;
        vis[u] = 0;
        for( int i = head[u]; ~i; i = es[i].next ) {
            int v = es[i].to;
            if( dis[v] > dis[u] + 1 ) {
                dis[v] = dis[u] + 1;
                if( !vis[v] ) {
                    vis[v] = true;
                    que[me++] = v;
                    if( me >= MAXM ) me -= MAXM;
                }
            }
        }
    }
    return ;
}

int main() {
    int t, u, v;
    scanf( "%d", &t );
    while( t-- ) {
        memset( head, -1, sizeof( head ) );
        cnt = 0;
        scanf( "%d%d", &n, &m );
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d", &u, &v );
            add( u, v ); add( v, u );
        }
        spfa();
        int low = 0, high = 1e9 + 1;
        while( low < high ) {
            int mid = ( low + high ) >> 1;
            ;
        }
    }
    return 0;
}
