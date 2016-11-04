#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 100 + 10;

int a[MAXN], dp[MAXN][MAXN], sum[MAXN];
int n;

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        memset( dp, 0, sizeof( dp ) );
        sum[0] = 0;
        printf( "Case #%d: ", ncas );
        scanf( "%d", &n );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d", a + i );
            sum[i] = sum[i - 1] + a[i];
        }
        for( int i = 1; i <= n; ++i ) {
            for( int j = i + 1; j <= n; ++j )
                dp[i][j] = INF;
        }
        for( int m = 2; m <= n; ++m ) {
            for( int i = 1; i < n; ++i ) {
                int j = i + m - 1;
                dp[i][j] = INF;
                for( int k = i; k <= j; ++k ) {
                    dp[i][j] = min( dp[i][j], dp[i + 1][k] + a[i] * ( k - i ) + dp[k + 1][j] + ( sum[j] - sum[k] ) * ( k - i + 1 ) );
                }
            }
        }
        printf( "%d\n", dp[1][n] );
    }
    return 0;
}
