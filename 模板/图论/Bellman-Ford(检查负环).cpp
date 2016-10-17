#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF 0x7FFFFFFF
#define MAX_V 1000
#define MAX_E 1000000 + 10

struct edge { int from, to, cost; };

edge es[MAX_E];
int d[MAX_V];
int V, E;

bool bf_nagative( int s ) {
    memset( d, 0, sizeof( d ) );
    for( int i = 0; i < V; ++i ) {
        for( int j = 0; j < E; ++j ) {
            edge e = es[j];
            if( d[e.to] > d[e.from] + e.cost ) {
                d[e.to] = d[e.from] + e.cost;
                if( i == V - 1 ) return true;
            }
        }
    }
    return false;
}

int main() {
    return 0;
}
