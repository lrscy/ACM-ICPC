#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const double INF = 0x3F3F3F3F;
const int MAXN = 100 + 10;
const int MAXE = 100000 + 10;

struct edge{ int u, v; double cost; };
edge es[MAXE];
int ID[MAXN], vis[MAXN], pre[MAXN], x[MAXN], y[MAXN];
double IN[MAXN];
int n, m, cnt;

void add( int u, int v, double c ) {
    es[cnt].u = u; es[cnt].v = v; es[cnt].cost = c; ++cnt;
    return ;
}

double direct_MST( int root ) {
    double ans = 0;
    while( true ) {
        memset( ID, -1, sizeof( ID ) );
        memset( vis, -1, sizeof( vis ) );
        for( int i = 0; i < MAXN; ++i ) IN[i] = INF;
        for( int i = 0; i < m; ++i ) {
            int u = es[i].u;
            int v = es[i].v;
            if( es[i].cost < IN[v] && u != v ) {
                IN[v] = es[i].cost;
                pre[v] = u;
            }
        }
        for( int i = 0; i < n; ++i ) {
            if( i == root ) continue;
            if( IN[i] == INF ) return -1;
        }
        int tv = 0;
        IN[root] = 0;// pre[root] = root;
        for( int i = 0; i < n; ++i ) {
            ans += IN[i];
            int v = i;
            while( vis[v] != i && ID[v] == -1 && v != root ) {
                vis[v] = i;
                v = pre[v];
            }
            if( v != root && ID[v] == -1 ) {
                for( int u = pre[v]; u != v; u = pre[u] ) {
                    ID[u] = tv;
                }
                ID[v] = tv++;
            }
        }
        if( !tv ) break;
        for( int i = 0; i < n; ++i ) {
            if( ID[i] == -1 ) ID[i] = tv++;
        }
        for( int i = 0; i < m; ++i ) {
            int v = es[i].v;
            es[i].u = ID[es[i].u];
            es[i].v = ID[es[i].v];
            if( es[i].u != es[i].v )
                es[i].cost -= IN[v];
        }
        n = tv;
        root = ID[root];
    }
    return ans;
}

double dis( int i, int j ) {
    double dx = abs( x[i] - x[j] );
    double dy = abs( y[i] - y[j] );
    return sqrt( dx * dx + dy * dy );
}

int main() {
    int a, b;
    while( ~scanf( "%d%d", &n, &m ) ) {
        cnt = 0;
        for( int i = 0; i < n; ++i ) scanf( "%d%d", x + i, y + i );
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d", &a, &b );
            --a; --b;
            add( a, b, dis( a, b ) );
        }
        double ans = direct_MST( 0 );
        if( ans < 0 ) puts( "poor snoopy" );
        else printf( "%.2f\n", ans );
    }
    return 0;
}
