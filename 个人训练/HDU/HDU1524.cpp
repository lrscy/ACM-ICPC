#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

vector<int> g[MAXN];
int sg[MAXN], a[MAXN];
int n;

int gao( int x ) {
    if( ~sg[x] ) return sg[x];
    int i, vis[MAXN];
    memset( vis, 0, sizeof( vis ) );
    for( i = 0; i < g[x].size(); ++i ) {
        int v = g[x][i];
        vis[gao(v)] = 1;
    }
    for( i = 0; vis[i]; ++i );
    return sg[x] = i;
}

int main() {
    int tn, ta;
    while( ~scanf( "%d", &n ) ) {
        memset( sg, -1, sizeof( sg ) );
        for( int i = 0; i < n; ++i ) g[i].clear();
        for( int i = 0; i < n; ++i ) {
            scanf( "%d", &tn );
            if( tn == 0 ) sg[i] = 0;
            while( tn-- ) {
                scanf( "%d", &ta );
                g[i].push_back( ta );
            }
        }
        while( ~scanf( "%d", &tn ) && tn ) {
            int ans = 0;
            for( int i = 0; i < tn; ++i ) {
                scanf( "%d", &ta );
                ans ^= gao( ta );
            }
            if( ans ) puts( "WIN" );
            else puts( "LOSE" );
        }
    }
    return 0;
}
