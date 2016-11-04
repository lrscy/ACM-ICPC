#include <bits/stdc++.h>
using namespace std;
const int NINF = 0x80808080;
const int MAXN = 1e3 + 10;

int a[MAXN], b[MAXN], dp[MAXN][MAXN];
int n, m, s, t;

int main() {
    while( ~scanf( "%d%d", &n, &t ) ) {
        memset( dp, 0, sizeof( dp ) );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d%d", &m, &s );
            for( int j = 1; j <= m; ++j ) {
                scanf( "%d%d", a + j, b + j );
            }
            if( s == 0 ) {
                for( int j = 0; j <= t; ++j ) dp[i][j] = NINF;
                for( int j = 1; j <= m; ++j ) {
                    for( int k = t; k >= a[j]; --k ) {
                        dp[i][k] = max( dp[i][k], dp[i][k - a[j]] + b[j] );
                        dp[i][k] = max( dp[i][k], dp[i - 1][k - a[j]] + b[j] );
                    }
                }
            } else if( s == 1 ) {
                for( int j = 0; j <= t; ++j ) dp[i][j] = dp[i - 1][j];
                for( int j = 1; j <= m; ++j ) {
                    for( int k = t; k >= a[j]; --k )
                        dp[i][k] = max( dp[i][k], dp[i - 1][k - a[j]] + b[j] );
                }
            } else {
                for( int j = 0; j <= t; ++j ) dp[i][j] = dp[i - 1][j];
                for( int j = 1; j <= m; ++j ) {
                    for( int k = t; k >= a[j]; --k ) {
                        dp[i][k] = max( dp[i][k], dp[i][k - a[j]] + b[j] );
                        dp[i][k] = max( dp[i][k], dp[i - 1][k - a[j]] + b[j] );
                    }
                }
            }
        }
        dp[n][t] = max( dp[n][t], -1 );
        printf( "%d\n", dp[n][t] );
    }
    return 0;
}
