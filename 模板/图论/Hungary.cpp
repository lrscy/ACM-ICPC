#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
#define INF 0x7FFFFFFF
#define MAX_V 1000
#define MAX_E 1000000 + 10

vector<int> G[MAX_V];
bool used[MAX_V];
int match[MAX_V];
int VX;

int findPath( int k ) {
    for( int i = 0; i < G[k].size(); ++i ) {
        int t = G[k][i];
        if( !used[t] ) {
            used[t] = true;
            if( match[i] == -1 || findPath( match[i] ) ) {
                match[t] = k;
                return 1;
            }
        }
    }
    return 0;
}

int hungary() {
    int res;
    memset( match, -1, sizeof( match ) );
    for( int i = 0; i < VX; ++i ) {
        memset( used, false, sizeof( used ) );
        res += findPath( i );
    }
    return res;
}

int main() {
    return 0;
}
