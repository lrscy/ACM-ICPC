#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN], d[MAXN];
int n, m;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( d, 0, sizeof d );
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
        for( int i = 0, u, v; i < m; ++i ) {
            scanf( "%d%d", &u, &v );
            ++d[u]; ++d[v];
        }
        int cnt = 0, ans = 0;
        bool flag = true;
        for( int i = 1; i <= n; ++i ) {
            if( d[i] & 1 ) { ans ^= a[i]; ++cnt; }
            if( cnt > 2 ) { flag = false; break; }
            ans ^= ( ( d[i] >> 1 ) & 1 ) ? a[i] : 0;
        }
        if( cnt == 1 || cnt > 2 ) flag = false;
        if( cnt == 0 ) {
            int ret = ans; ans = 0;
            for( int i = 1; i <= n; ++i ) ans = max( ans, ret ^ a[i] );
        }
        if( flag ) printf( "%d\n", ans );
        else puts( "Impossible" );
    }
    return 0;
}
