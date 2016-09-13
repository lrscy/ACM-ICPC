#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

struct Edge { int to, next; };
Edge es[MAXN << 2];
int head[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN], bit[MAXN];
bool vis[MAXN];
LL ans, m;
int n, cnt, tn;

void adde( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

int sum( int i ) {
    int ret = 0;
    while( i ) {
        ret += bit[i];
        i -= i & -i;
    }
    return ret;
}

void add( int i, int x ) {
    while( i <= tn ) {
        bit[i] += x;
        i += i & -i;
    }
    return ;
}

void init() {
    memcpy( d, a, sizeof( a ) );
    sort( d + 1, d + n + 1 );
    tn = unique( d + 1, d + n + 1 ) - ( d + 1 );
    for( int i = 1; i <= n; ++i ) b[i] = lower_bound( d + 1, d + tn + 1, a[i] ) - d;
    for( int i = 1; i <= n; ++i ) {
        if( a[i] == 0 ) c[i] = tn;
        else c[i] = upper_bound( d + 1, d + tn + 1, m / a[i] ) - ( d + 1 );
    }
    return ;
}

void dfs( int u ) {
    ans += sum( c[u] );
    add( b[u], 1 );
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        dfs( v );
    }
    add( b[u], -1 );
    return ;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( head, -1, sizeof( head ) ); cnt = 0;
        memset( vis, false, sizeof( vis ) );
        memset( bit, 0, sizeof( bit ) );
        ans = 0;
        scanf( "%d%I64d", &n, &m );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
        for( int i = 1, u, v; i < n; ++i ) { scanf( "%d%d", &u, &v ); adde( u, v ); vis[v] = true; }
        init();
        int root;
        for( int i = 1; i <= n; ++i ) if( !vis[i] ) { root = i; break; }
        dfs( root );
        printf( "%I64d\n", ans );
    }
    return 0;
}
