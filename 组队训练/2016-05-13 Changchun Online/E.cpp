#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 10;

struct Edge {
    int u, v, cost;
    bool operator < ( const Edge &ip ) const {
        return cost < ip.cost;
    }
};
Edge es[MAXN];
PII qu[MAXN];
int fa[MAXN], val[MAXN], ans[MAXN];
int n, m, q, tot;

int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }

void munion( int u, int v ) {
    if( u == v ) return ;
    int x = mfind( u ), y = mfind( v );
    if( x != y ) {
        tot += 2 * val[x] * val[y];
        val[x] += val[y];
        fa[y] = x;
    }
    return ;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( ans, 0, sizeof( ans ) );
        tot = 0;
        scanf( "%d%d%d", &n, &m, &q );
        for( int i = 1; i <= n; ++i ) { fa[i] = i; val[i] = 1; }
        for( int i = 0; i < m; ++i ) scanf( "%d%d%d", &es[i].u, &es[i].v, &es[i].cost );
        for( int i = 0; i < q; ++i ) {
            scanf( "%d", &qu[i].first );
            qu[i].second = i;
        }
        sort( es, es + m ); sort( qu, qu + q );
        int pos = 0;
        for( int i = 0; i < q; ++i ) {
            while( es[pos].cost <= qu[i].first ) {
                munion( es[pos].u, es[pos].v );
                ++pos;
            }
            ans[qu[i].second] = tot;
        }
        for( int i = 0; i < q; ++i ) printf( "%d\n", ans[i] );
    }
    return 0;
}
