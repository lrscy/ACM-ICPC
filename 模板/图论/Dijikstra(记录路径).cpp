#include <iostream>
#include <cstdio>
using namespace std;
#define N 1010
#define INF 0x7FFFFFFF

int d[N], vis[N], pre[N];
int cost[N][N];
int V;

void dijkstra( int s ) {
    for( int i = 1; i <= V; ++i ) {
        d[i] = INF;
        vis[i] = 0;
        pre[i] = -1;
    }
    d[s] = 0;
    while( true ) {
        int v = -1;
        for( int u = 1; u <= V; ++u ) {
            if( !vis[u] && ( v == -1 || d[u] < d[v] ) ) v = u;
        }

        if( v == -1 ) break;
        vis[v] = 1;

        for( int u = 1; u <= V; ++u ) {
            if( d[u] > d[v] + cost[v][u] ) {
                d[u] = d[v] + cost[v][u];
                pre[u] = v;
            }
        }
    }
    return ;
}

int main() {
    return 0;
}
