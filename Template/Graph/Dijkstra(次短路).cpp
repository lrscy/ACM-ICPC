#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 110
#define PII pair<int, int>
#define INF 0x7FFFFFFF

struct edge {
    int to, cost;
    edge( int t, int c ) { to = t; cost = c; }
};

vector<edge> G[N];
int V;
int dis[N], dis2[N];

void dijikstra( int s ) {
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    for( int i = 0; i < V; ++i ) dis[i] = dis2[i] = INF;
    dis[s] = 0;
    pq.push( PII( dis[s], s ) );
    while( !pq.empty() ) {
        PII p = pq.top();
        pq.pop();
        int v = p.second, d = p.first;
        if( dis2[v] < d ) continue;
        for( int i = 0; i < G[v].size(); ++i ) {
            edge &e = G[v][i];
            int d2 = d + e.cost;
            if( d2 < dis[e.to] ) {
                swap( d2, dis[e.to] );
                pq.push( PII( dis[e.to], e.to ) );
            }
            if( d2 < dis2[e.to] && d2 > dis[e.to] ) {
                dis[e.to] = d2;
                pq.push( PII( dis2[e.to], e.to ) );
            }
        }
    }
    return ;
}

int main() {
    int m, n;
    while( ~scanf( "%d%d" ,&m, &n ) && ( m || n ) ) {
        for( int i = 0; i < n; ++i ) G[i].clear();
        V = n;
        int u, v, w;
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d%d", &u, &v, &w );
            G[u - 1].push_back( edge( v - 1, w ) );
            G[v - 1].push_back( edge( u - 1, w ) );
        }
        dijikstra( 0 );
        cout << dis[n - 1] << endl;
    }
    return 0;
}
