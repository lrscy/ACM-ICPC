#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 1e5 + 10;

int sg[MAXN], a[MAXN];
int n, m;

int gao( int x ) {
    if( ~sg[x] ) return sg[x];
    int i, vis[100];
    memset( vis, 0, sizeof( vis ) );
    for( i = 0; i < n; ++i ) {
        if( x < a[i] ) break;
        vis[gao( x - a[i] )] = 1;
    }
    for( i = 0; vis[i]; ++i );
    return sg[x] = i;
}

int main() {
    int th, ta, ans;
    while( ~scanf( "%d", &n ) && n ) {
        memset( sg, -1, sizeof( sg ) );
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        sort( a, a + n );
        scanf( "%d", &m );
        while( m-- ) {
            ans = 0;
            scanf( "%d", &th );
            while( th-- ) {
                scanf( "%d", &ta );
                ans ^= gao( ta );
            }
            putchar( ans ? 'W' : 'L' );
        }
        puts( "" );
    }
    return 0;
}
