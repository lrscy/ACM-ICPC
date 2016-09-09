#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Edge { int u, v, cost; };
Edge es[MAXN << 1];
bool vis[MAXN];
int n, m, k;

bool cmp( const Edge &a, const Edge &b ) {
    return a.cost < b.cost;
}

int main() {
    int t;
    memset( vis, false, sizeof( vis ) );
    scanf( "%d%d%d", &n, &m, &k );
    for( int i = 0; i < m; ++i ) scanf( "%d%d%d", &es[i].u, &es[i].v, &es[i].cost );
    for( int i = 0; i < k; ++i ) { scanf( "%d", &t ); vis[t] = true; }
    sort( es, es + m, cmp );
    int ans = -1;
    for( int i = 0; i < m; ++i ) {
        int u = es[i].u, v = es[i].v;
        if( vis[u] ^ vis[v] ) { ans = es[i].cost; break; }
    }
    printf( "%d\n", ans );
    return 0;
}
