#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;
const int MAXN = 18;

UI ans, dp[1 << MAXN];
int color[1 << MAXN][MAXN], g[MAXN][MAXN];
int n;

void print( int mask ) {
    for( int i = n - 1; i >= 0; --i ) cout << ( bool )( ( 1 << i ) & mask ); cout << endl;
    return ;
}

UI qpow( UI a, UI b ) {
    UI ret = 1;
    while( b ) {
        if( b & 1 ) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int main() {
    int tco[MAXN];
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( color, -1, sizeof( color ) );
        memset( dp, 0x3F, sizeof( dp ) );
        ans = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < n; ++j )
                scanf( "%1d", &g[i][j] );
        }
        for( int s = 1; s < ( 1 << n ); ++s ) {
            for( int i = 0, j = 0; i < n; ++i ) {
                if( s & ( 1 << i ) ) {
                    UI tmp = 0;
                    int ts = s ^ ( 1 << i ), tc = 0;
                    memcpy( tco, color[ts], sizeof( color[ts] ) );
                    for( j = 0; j < n; ++j ) {
                        if( g[i][j] && ( ts & ( 1 << j ) ) ) {
                            tc |= ( 1 << color[ts][j] );
                        }
                    }
                    for( j = 0; tc & ( 1 << j ); ++j );
                    tco[i] = j;
                    tc = 0;
                    for( j = 0; j < n; ++j ) if( ~tco[j] ) tc |= ( 1 << tco[j] );
                    tmp = __builtin_popcount( tc );
                    if( tmp < dp[s] ) {
                        dp[s] = tmp;
                        memcpy( color[s], tco, sizeof( tco ) );
                    }
                }
            }
            ans += dp[s] * qpow( 233, s );
        }
        printf( "%u\n", ans );
    }
    return 0;
}
