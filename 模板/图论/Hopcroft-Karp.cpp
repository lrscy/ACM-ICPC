#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x7FFFFFFF
#define MAX_V 1000
#define MAX_E 1000000 + 10

vector<int> G[MAX_V];
int VX;
int dx[MAX_V], dy[MAX_V];
int cx[MAX_V], cy[MAX_V];
int mindis;
bool mask[MAX_V];

bool searchPath() {
    queue<int> q;
    memset( dx, -1, sizeof( dx ) );
    memset( dy, -1, sizeof( dy ) );
    mindis = INF;
    for( int i = 0; i < VX; ++i ) {
        if( cx[i] == -1 ) {
            dx[i] = 0;
            q.push( i );
        }
    }
    while( !q.empty() ) {
        int t = q.front(); q.pop();
        if( dx[t] > mindis ) break;
        for( int i = 0; i < G[t].size(); ++i ) {
            int v = G[t][i];
            if( dy[v] == -1 ) {
                dy[v] = dx[t] + 1;
                if( cy[v] == -1 ) mindis = dy[v];
                else {
                    dx[cy[v]] = dy[v] + 1;
                    q.push( v );
                }
            }
        }
    }
    return mindis != INF;
}

int findPath( int u ) {
    for( int i = 0; i < G[u].size(); ++i ) {
        int v = G[u][i];
        if( !mask[v] && dy[v] == dx[u] + 1 ) {
            mask[v] = true;
            if( cy[v] != -1 && dy[v] == mindis ) continue;
            else {
                cx[u] = v; cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hk() {
    int res = 0;
    memset( cx, -1, sizeof( cx ) );
    memset( cy, -1, sizeof( cy ) );
    while( searchPath() ) {
        memset( mask, 0, sizeof mask );
        for( int i = 0; i < VX; ++i ) {
            if( cx[i] == -1 )
                res += findPath( i );
        }
    }
    return res;
}

int main() {
    return 0;
}
