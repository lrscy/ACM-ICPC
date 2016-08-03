#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXM = 20 + 10;

int f[MAXM], sg[MAXN];
int n, m, p;

int gao( int x ) {
    if( ~sg[x] ) return sg[x];
    int i, vis[MAXM];
    memset( vis, false, sizeof( vis ) );
    for( i = 2; i <= 16; ++i ) {
        if( x < f[i] ) break;
        vis[gao( x - f[i] )] = 1;
    }
    for( i = 0; vis[i]; ++i );
    return sg[x] = i;
}

int main() {
    f[1] = f[2] = 1;
    for( int i = 3; i <= 16; ++i ) f[i] = f[i - 1] + f[i - 2];
    while( ~scanf( "%d%d%d", &n, &m, &p ) && n + m + p ) {
        memset( sg, -1, sizeof( sg ) );
        int ans = 0;
        ans = gao( n ) ^ gao( m ) ^ gao( p );
        puts( ans ? "Fibo" : "Nacci" );
    }
    return 0;
}
