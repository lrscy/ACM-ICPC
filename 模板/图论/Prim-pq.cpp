#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x7FFFFFFF
#define MAX_V 1000
#define MAX_E 1e6

struct edge { to, cost };
typedef pair<int, int> PII;

vector<edge> G[MAX_V];
int mincost[MAX_V];
int V;

int prim() {
    int res = 0;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    for( int i = 0; i < V; ++i ) mincost[i] = INF;
    mincost[0] = 0; pq.push( P( 0, 0 ) );
    while( !pq.empty() ) {
        PII tmp = pq.top(); pq.pop();
        int v = tmp.second; res += v;
        if( mincost[v] < tmp.first ) continue;
        for( int i = 0; i < G[v].size(); ++i ) {
            edge e = G[v][i];
            if( mincost[e.to] > e.cost ) {
                mincost[e.to] = e.cost;
                pq.push( mincost[e.to], e.to );
            }
        }
    }
    return res;
}

int main() {
    return 0;
}
