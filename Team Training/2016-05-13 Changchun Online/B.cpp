#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;

struct Edge { int to, next; };
Edge es[MAXM << 1];
int head[MAXN], val[MAXN], deg[MAXN], que[MAXM << 2];
bool vis[MAXN];
map<PII, int> mp;
int n, m, cnt;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
}

int dfs( int u, LL &sum ) {
    int num = 1;
    sum += val[u];
    vis[u] = true;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( !vis[v] ) {
            num += dfs( v, sum );
        }
    }
    return num;
}

int main() {
    int t;
    int a, b, mf, me;
    scanf( "%d", &t );
    while( t-- ) {
        memset( vis, false, sizeof( vis ) );
        memset( head, -1, sizeof( head ) );
        memset( deg, 0, sizeof( deg ) );
        cnt = 0; mf = me = 0;
        mp.clear();
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < n; ++i ) scanf( "%d", val + i );
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d", &a, &b );
            --a; --b;
            if( a > b ) swap( a, b );
            PII tp = make_pair( a, b );
            if( a == b || mp[tp] ) continue;
            mp[tp] = 1;
            add( a, b ); add( b, a );
            ++deg[a]; ++deg[b];
        }
        for( int i = 0; i < n; ++i ) {
            if( deg[i] < 2 ) {
                que[me++] = i;
                vis[i] = true;
            }
        }
        while( mf != me ) {
            int u = que[mf++];
            if( mf >= MAXM ) mf -= MAXM;
            for( int i = head[u]; ~i; i = es[i].next ) {
                int v = es[i].to;
                if( --deg[v] < 2 && !vis[v] ) {
                    vis[v] = true;
                    que[me++] = v;
                    if( me >= MAXM ) me -= MAXM;
                }
            }
        }
        LL ans = 0;
        for( int i = 0; i < n; ++i ) if( !vis[i] ) {
            LL sum = 0;
            if( dfs( i, sum ) & 1 ) {
                ans += sum;
            }
        }
        printf( "%I64d\n", ans );
    }
    return 0;
}
