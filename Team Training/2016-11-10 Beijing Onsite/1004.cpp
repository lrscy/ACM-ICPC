#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;

int dp[MAXN][MAXN], dp2[MAXN][MAXN], a[MAXN], b[MAXN];
int n;

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( dp, 0, sizeof dp );
        scanf( "%d", &n );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
        for( int i = 1; i <= n; ++i ) scanf( "%d", b + i );
        b[0] = b[n + 1] = 0;
        n += 2;
        for( int i = 0; i + 2 < n; ++i ) dp[i][i + 2] = b[i] + a[i + 1] + b[i + 2];
        for( int len = 3; len <= n; ++len ) {
            for( int i = 0; i + len - 1 < n; ++i ) {
                int j = i + len - 1;
                for( int k = i + 1; k < j; ++k ) {
                    if( dp[i][j] == 0 ) dp[i][j] = dp[i][k] + dp[k][j] + a[k] + b[i] + b[j];
                    else dp[i][j] = min( dp[i][j], dp[i][k] + dp[k][j] + a[k] + b[i] + b[j] );
                }
            }
        }
        printf( "%d\n", dp[0][n - 1] );
    }
    return 0;
}
