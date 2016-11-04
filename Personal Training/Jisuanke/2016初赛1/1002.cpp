#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXM = 1e5 + 10;

struct Edge { int to, next; };
Edge es[MAXN << 1];
int head[MAXN], a[MAXN], dis[MAXN];
bool vis[MAXN];
int n, cnt;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

int gcd( int a, int b ) {
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

int spfa( int st ) {
    int ret = 0;
    int que[MAXM], mf, me;
    memset( vis, false, sizeof( vis ) );
    memset( dis, 0x3F, sizeof( dis ) );
    mf = me = 0;
    que[me++] = st; vis[st] = true; dis[st] = 0;
    while( mf != me ) {
        int u = que[mf++];
        if( mf >= MAXM ) mf -= MAXM;
        vis[u] = false;
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
    return ret;
} 

int main() {
    int u, v;
    memset( head, -1, sizeof( head ) );
    cnt = 0;
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
    for( int i = 1; i < n; ++i ) {
        scanf( "%d%d", &u, &v );
        add( u, v ); add( v, u );
    }
    int ans = 0;
    for( int i = 1; i <= n; ++i ) {
        spfa( i );
        for( int j = i + 1; j <= n; ++j ) {
            if( gcd( a[i], a[j] ) == 1 ) {
                ans += dis[j];
            }
        }
    }
    printf( "%d\n", ans );
    return 0;
}
