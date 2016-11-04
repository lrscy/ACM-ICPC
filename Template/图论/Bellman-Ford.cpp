#include <iostream>
#include <cstdio>
using namespace std;
#define INF 0x7FFFFFFF
#define MAX_V 1000
#define MAX_E 1000000 + 10

struct edge { int from, to, cost; };

edge es[MAX_E];
int d[MAX_V];
int V, E;

void bf( int s ) {
    for( int i = 0; i < V; ++i ) d[i] = INF;
    d[s] = 0;
    while( true ) {
        bool flag = false;
        for( int i = 0; i < E; ++i ) {
            edge e = es[i];
            if( d[e.from] != INF && d[e.to] > d[e.from] + e.cost ) {
                d[e.to] = d[e.from] + e.cost;
                flag = true;
            }
        }
        if( !flag ) break;
    }
    return ;
}

int main() {
    return 0;
}
