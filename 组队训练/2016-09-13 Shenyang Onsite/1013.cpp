#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x3F3F3F3F;
const int MAXN = 1e5 + 10;
const int MAXM = 1e6 + 10;

vector<int> s1[MAXN], s2[MAXM];
int dis1[MAXN], dis2[MAXN], ds[MAXM], cost[MAXN], ans[MAXN];
int n, m;

void dij( int src, int *dis ) {
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    memset( ds, 0x3F, sizeof( ds ) );
    dis[src] = 0; pq.push( PII( 0, src ) );
    while( !pq.empty() ) {
        PII p = pq.top(); pq.pop();
        int u = p.second, td = p.first;
        if( dis[u] < td ) continue;
        dis[u] = td;
        for( int i = 0; i < s2[u].size(); ++i ) {
            int s = s2[u][i];
            if( ds[s] <= dis[u] ) continue;
            ds[s] = dis[u];
            for( int j = 0; j < s1[s].size(); ++j ) {
                int v = s1[s][j];
                if( v == u ) continue;
                if( dis[v] > dis[u] + cost[s] ) {
                    dis[v] = dis[u] + cost[s];
                    pq.push( PII( dis[v], v ) );
                }
            }
        }
    }
    return ;
}

bool cmp( const int &a, const int &b ) {
    return cost[a] < cost[b];
}

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( dis1, 0x3F, sizeof( dis1 ) );
        memset( dis2, 0x3F, sizeof( dis2 ) );
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) s2[i].clear();
        for( int i = 1; i <= m; ++i ) s1[i].clear();
        for( int i = 1, tn; i <= m; ++i ) {
            scanf( "%d%d", cost + i, &tn );
            for( int j = 0, tmp; j < tn; ++j ) {
                scanf( "%d", &tmp );
                s1[i].push_back( tmp );
                s2[tmp].push_back( i );
            }
        }
        dij( 1, dis1 );
//        for( int i = 1; i <= n; ++i ) cout << dis1[i] << " "; cout << endl;
        dij( n, dis2 );
//        for( int i = 1; i <= n; ++i ) cout << dis2[i] << " "; cout << endl;
        int nmin = INF, cnt = 0;
        for( int i = 1; i <= n; ++i ) {
            int tmp = max( dis1[i], dis2[i] );
            if( tmp < nmin ) {
                cnt = 0;
                nmin = tmp;
                ans[cnt++] = i;
            } else if( tmp == nmin ) {
                ans[cnt++] = i;
            }
        }
        if( nmin == INF ) { puts( "Evil John" ); continue; }
        printf( "%d\n%d", nmin, ans[0] );
        for( int i = 1; i < cnt; ++i ) printf( " %d", ans[i] ); puts( "" );
    }
    return 0;
}
