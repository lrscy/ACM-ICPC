#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x7FFFFFFF
#define MAX_V 1000
#define MAX_E 1000000 + 10

struct edge { int to, cost; };
typedef pair<int, int> PII;

vector<edge> G[MAX_V];
int d[MAX_V];
int V;

void dijskra( int s ) {
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    for( int i = 0; i < V; ++i ) d[i] = INF;
    d[s] = 0;
    pq.push( PII( 0, s ) );
    while( !pq.empty() ) {
        PII p = pq.top(); pq.pop();
        int v = p.second;
        if( d[v] < p.first ) continue;
        for( int i = 0; i < G[v].size(); ++i ) {
            edge e = G[v][i];
            if( d[e.to] > d[v] + e.cost ) {
                d[e.to] = d[v] + e.cost;
                pq.push( PII( d[e.to], e.to ) );
            }
        }
    }
    return ;
}

int main() {
    return 0;
}
