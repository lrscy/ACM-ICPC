#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1e5 + 10;

int c[MAXN], w[MAXN], dp[MAXN];
int n, m, p;

int main() {
    int tt, t, u, v, nn;
    scanf( "%d", &tt );
    while( tt-- ) {
        scanf( "%d%d%d", &n, &m, &p );
        nn = 0;
        for( int i = 0; i < n; ++i ) {
            scanf( "%d%d%d", &t, &u, &v );
            int k = 0;
            while( v - ( 1 << ( k + 1 ) ) + 1 > 0 ) ++k;
            for( int j = 0; j < k; ++j ) {
                ++nn;
                c[nn] = t * ( 1 << j );
                w[nn] = u * ( 1 << j );
            }
            ++nn;
            c[nn] = t * ( v - ( 1 << k ) + 1 );
            w[nn] = u * ( v - ( 1 << k ) + 1 );
        }
        memset( dp, 0x3F, sizeof( dp ) );
        dp[0] = 0;
        for( int i = 1; i <= nn; ++i ) {
            for( int j = p + 100; j >= c[i]; --j )
                dp[j] = min( dp[j], dp[j - c[i]] + w[i] );
        }
        int tmpV = INF;
        for( int i = p; i <= p + 100; ++i ) tmpV = min( tmpV, dp[i] );
        nn = 0;
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d%d", &u, &t, &v );
            int k = 0;
            while( v - ( 1 << ( k + 1 ) ) + 1 > 0 ) ++k;
            for( int j = 0; j < k; ++j ) {
                ++nn;
                c[nn] = t * ( 1 << j );
                w[nn] = u * ( 1 << j );
            }
            ++nn;
            c[nn] = t * ( v - ( 1 << k ) + 1 );
            w[nn] = u * ( v - ( 1 << k ) + 1 );
        }
        memset( dp, 0, sizeof( dp ) );
        for( int i = 1; i <= nn; ++i ) {
            for( int j = 50000; j >= c[i]; --j )
                dp[j] = max( dp[j], dp[j - c[i]] + w[i] );
        }
        int ans = INF;
        for( int i = 50000; i >= 0; --i ) {
            if( dp[i] >= tmpV ) ans = min( ans, i );
        }
        if( ans == INF ) puts( "TAT" );
        else printf( "%d\n", ans );
    }
    return 0;
}
