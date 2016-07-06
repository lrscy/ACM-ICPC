#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXM = 1e5 + 10;

int a[MAXN], b[MAXN], c[MAXN], dp[15][MAXM];
int n, m, K;

int main() {
    while( ~scanf( "%d%d%d", &n, &m, &K ) ) {
        memset( dp, 0x80, sizeof( dp ) );
        for( int i = 0; i <= m; ++i ) dp[0][i] = 0;
        for( int i = 1; i <= n; ++i ) scanf( "%d%d%d", a + i, b + i, c + i );
        for( int k = 1; k <= K; ++k ) {
            for( int i = 1; i <= n; ++i ) {
                if( a[i] == k ) {
                    for( int j = m; j >= b[i]; --j ) {
                        dp[k][j] = max( dp[k][j], dp[k][j - b[i]] + c[i] );
                        dp[k][j] = max( dp[k][j], dp[k - 1][j - b[i]] + c[i] );
                    }
                }
            }
        }
        if( dp[K][m] < 0 ) puts( "Impossible" );
        else printf( "%d\n", dp[K][m] );
    }
    return 0;
}
