#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;

struct Edge { int u, v, cost; };
Edge es[MAXN];
struct Node { int to, cost, next; };
Node g[MAXN];
int head[MAXN], fa[MAXN], son[MAXN];
LL ans1, sum;
double ans2;
int n, m, cnt;

bool cmp( const Edge &a, const Edge &b ) {
    return a.cost < b.cost;
}

void add( int u, int v, int w ) {
    g[cnt].to = v; g[cnt].cost = w; g[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }

bool munion( int u, int v ) {
    int x = mfind( u ), y = mfind( v );
    if( x != y ) {
        fa[x] = y;
        return true;
    }
    return false;
}

int dfs( int u, int fa ) {
    int ret = 1;
    for( int i = head[u]; ~i; i = g[i].next ) {
        int v = g[i].to;
        if( v == fa ) continue;
        int tmp = dfs( v, u );
        ret += tmp;
        sum += 1LL * g[i].cost * tmp * ( n - tmp );
    }
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        ans1 = 0; sum = 0; cnt = 0;
        scanf( "%d%d", &n, &m );
        memset( head, -1, sizeof( head ) );
        for( int i = 1; i <= n; ++i ) fa[i] = i;
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d%d", &es[i].u, &es[i].v, &es[i].cost );
        }
        sort( es, es + m, cmp );
        for( int i = 0; i < m; ++i ) {
            int u = es[i].u, v = es[i].v, val = es[i].cost;
            if( munion( u, v ) ) {
                ans1 += val;
                add( u, v, val ); add( v, u, val );
            }
        }
        dfs( 1, -1 );
        ans2 = 2.0 * sum / ( 1LL * n * ( n - 1 ) );
        printf( "%I64d %.2f\n", ans1, ans2 );
    }
    return 0;
}
