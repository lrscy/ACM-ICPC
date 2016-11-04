#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1e4 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXN << 1];
int head[MAXN], son[MAXN], dp[MAXN], dep[MAXN];
bool vis[MAXN];
vector<int> vdep;
int n, m, cnt, root, size, ans;

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void getroot( int u, int fa ) {
    son[u] = 1; dp[u] = 0;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa || vis[v] ) continue;
        getroot( v, u );
        son[u] += son[v];
        dp[u] = max( dp[u], son[v] );
    }
    dp[u] = max( dp[u], size - son[u] );
    if( dp[u] < dp[root] ) root = u;
    return ;
}

void getdep( int u, int fa ) {
    vdep.push_back( dep[u] );
    son[u] = 1;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa || vis[v] ) continue;
        dep[v] = dep[u] + es[i].cost;
        getdep( v, u );
        son[u] += son[v];
    }
    return ;
}

int calc( int u, int init ) {
    int ret = 0;
    vdep.clear(); dep[u] = init;
    getdep( u, 0 );
    sort( vdep.begin(), vdep.end() );
    int l = 0, r = vdep.size() - 1;
    while( l < r ) {
        if( vdep[l] + vdep[r] <= m ) { ret += r - l; ++l; }
        else r--;
    }
    return ret;
}

void solve( int u ) {
    ans += calc( u, 0 );
    vis[u] = true;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( vis[v] ) continue;
        ans -= calc( v, es[i].cost );
        dp[0] = size = son[v];
        getroot( v, root = 0 );
        solve( root );
    }
    return ;
}

int main() {
    int ta, tb, tc;
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        memset( vis, false, sizeof( vis ) );
        memset( head, -1, sizeof( head ) );
        cnt = 0;
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d%d", &ta, &tb, &tc );
            add( ta, tb, tc ); add( tb, ta, tc );
        }
        ans = 0; dp[0] = size = n;
        getroot( 1, root = 0 );
        solve( root );
        printf( "%d\n", ans );
    }
    return 0;
}
