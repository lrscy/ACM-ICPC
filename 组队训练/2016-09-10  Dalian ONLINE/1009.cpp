#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 10;

vector<int> g[MAXN];
set<int> s1, s2;
int dis[MAXN];
int n, m, src;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( dis, -1, sizeof( dis ) );
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) g[i].clear();
        for( int i = 0, u, v; i < m; ++i ) {
            scanf( "%d%d", &u, &v );
            g[u].push_back( v );
            g[v].push_back( u );
        }
        scanf( "%d", &src );
        s1.clear(); s2.clear();
        for( int i = 1; i <= n; ++i ) if( i != src ) s1.insert( i );
        dis[src] = 0;
        queue<int> que;
        que.push( src );
        while( !que.empty() ) {
            int u = que.front(); que.pop();
            for( int i = 0; i < g[u].size(); ++i ) {
                int v = g[u][i];
                if( s1.count( v ) == 0 ) continue;
                s1.erase( v ); s2.insert( v );
            }
            for( set<int>::iterator it = s1.begin(); it != s1.end(); ++it ) {
                dis[*it] = dis[u] + 1;
                que.push( *it );
            }
            s1.swap( s2 );
            s2.clear();
        }
        for( int i = 1; i < n; ++i ) if( i != src ) printf( "%d ", dis[i] ); printf( "%d\n", dis[n] );
    }
    return 0;
}
