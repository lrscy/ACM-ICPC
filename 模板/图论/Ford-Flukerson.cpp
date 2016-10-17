#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
#define MAXV 10010
#define INF 0x7FFFFFFF

struct edge { int to, cap, rev; };

vector<edge> G[MAXV];
bool vis[MAXV];

void add_edge( int f, int t, int c ) {
    G[f].push_back( ( edge ){ t, c, G[t].size() } );
    G[t].push_back( ( edge ){ f, 0, G[f].size() - 1 } );
    return ;
}

int dfs( int v, int t, int f ) {
    if( v == t ) return f;
    vis[v] = true;
    for( int i = 0; i < G[v].size(); ++i ) {
        edge &e = G[v][i];
        if( !vis[e.to] && e.cap > 0 ) {
            int d = dfs( e.to, t, min( f, e.cap ) );
            if( d > 0 ) {
                e.cap -= d;
                G[e.to][e.rev] += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow( int s, int t ) {
    int flow = 0;
    while( true ) {
        memset( vis, 0, sizeof( vis ) );
        int f = dfs( s, t, INF );
        if( f == 0 ) return flow;
        flow += f;
    }
    return 0;
}

int main() {
    int n, m;
    int a, b, c;
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < n; ++i ) {
        scanf( "%d%d%d", a, b, c );
        add( a, b, c );
    }
    cout << max_flow( 0, n - 1 ) << endl;
    return 0;
}
