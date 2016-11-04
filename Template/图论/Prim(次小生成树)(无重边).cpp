#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x7F7F7F7F;
const int MAXN = 1000 + 10;

PII poi[MAXN];
double dis[MAXN][MAXN], path[MAXN][MAXN], mincost[MAXN];
int ren[MAXN], pre[MAXN];
bool vis[MAXN], used[MAXN][MAXN];
int n;

double dist( const int i, const int j ) {
    double dx = poi[i].first - poi[j].first;
    double dy = poi[i].second - poi[j].second;
    return sqrt( dx * dx + dy * dy );
}

double prim() {
    double ret = 0;
    memset( used, false, sizeof( used ) );
    memset( vis, false, sizeof( vis ) );
    memset( path, 0, sizeof( path ) );
    for( int i = 0; i < n; ++i ) { mincost[i] = INF; pre[i] = 0; }
    mincost[0] = 0;
    while( true ) {
        int v = -1;
        for( int u = 0; u < n; ++u ) if( !vis[u] && ( v == -1 || mincost[u] < mincost[v] ) ) v = u;
        if( v == -1 ) break;
        used[pre[v]][v] = used[v][pre[v]] = true;
        ret += mincost[v];
        vis[v] = true;
        for( int u = 0; u < n; ++u ) {
            if( vis[u] && v != u ) path[u][v] = path[v][u] = max( path[u][pre[v]], mincost[v] );
            if( !vis[u] && mincost[u] > dis[u][v] ) {
                mincost[u] = dis[u][v];
                pre[u] = v;
            }
        }
    }
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%d%d%d", &poi[i].first, &poi[i].second, ren + i );
            for( int j = 0; j < i; ++j ) dis[i][j] = dis[j][i] = dist( i, j );
            dis[i][i] = 0;
        }
        double tmp = prim();
        double ans = -1;
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < n; ++j ) if( i != j ) {
                if( used[i][j] ) ans = max( ans, ( ren[i] + ren[j] ) / ( tmp - dis[i][j] ) );
                else ans = max( ans, ( ren[i] + ren[j] ) / ( tmp - path[i][j] ) );
            }
        }
        printf( "%.2f\n", ans );
    }
    return 0;
}
