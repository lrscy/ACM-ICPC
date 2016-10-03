#include <bits/stdc++.h>
using namespace std;
//#pragma comment( linker, "/STACK:1024000000,1024000000" )
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef long long LL;
const int MAXN = 1e5 + 10;
const int B = 1e6 + 7;

struct Edge{ int to, next; };
Edge es[MAXN << 2];
int head[MAXN], dep[MAXN], num[MAXN], d[MAXN], que[MAXN];
unsigned long long mhash[MAXN];
bool vis[MAXN];
map<ULL, LL> mp;
map<ULL, LL>::iterator it;
//map<PII, int> mp;
//map<PII, int>::iterator it;
LL ans;
int n, cnt;

void add( int u, int v ) { es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++; }

void dfs( int u, int fa ) {
    num[u] = 1; dep[u] = 1; d[u] = 0;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        ++d[u];
        dfs( v, u );
        num[u] += num[v];
        dep[u] = max( dep[u], dep[v] + 1 );
        mhash[u] += mhash[v] * B;
    }
    mhash[u] += 1;
    return ;
}

void topo() {
    int mf, me, mt;
    mf = me = 0;
    mp.clear();
    for( int i = 1; i <= n; ++i ) if( d[i] == 0 ) que[me++] = i, vis[i] = true;
    mt = me;
    while( mf != me ) {
        int u = que[mf++];
        vis[u] = true;
//        if( mf > mt ) {
//            for( it = mp.begin(); it != mp.end(); ++it ) if( it->second > 1 ) {
//                ans += 1LL * ( it->second ) * ( it->second - 1 ) / 2;
//            }
//            mt = me; mp.clear();
//        }
        for( int i = head[u]; ~i; i = es[i].next ) {
            int v = es[i].to;
            if( vis[v] ) continue;
            ++mp[mhash[u]];
            --d[v];
            if( d[v] == 0 ) que[me++] = v;
        }
    }
    for( it = mp.begin(); it != mp.end(); ++it ) if( it->second > 1 ) {
        ans += 1LL * ( it->second ) * ( it->second - 1 ) / 2;
    }
    return ;
}

int main() {
    memset( head, -1, sizeof( head ) );
    memset( vis, false, sizeof( vis ) );
    ans = 0; cnt = 0;
    scanf( "%d", &n );
    for( int i = 1, u, v; i < n; ++i ) {
        scanf( "%d%d", &u, &v );
        add( u, v ); add( v, u );
    }
    dfs( 1, 0 );
//    for( int i = 1; i <= n; ++i ) cout << mhash[i] << endl;
    topo();
    printf( "%lld\n", ans );
    return 0;
}
