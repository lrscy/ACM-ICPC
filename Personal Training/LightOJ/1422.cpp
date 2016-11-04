#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int dp[MAXN][MAXN], a[MAXN];
int n;

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case %d: ", ncas );
        memset( dp, 0, sizeof( dp ) );
        scanf( "%d", &n );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i ), dp[i][i] = 1;
        for( int j = 2; j <= n; ++j ) {
            for( int i = 1; i <= j; ++i ) {
                dp[i][j] = dp[i][j - 1] + 1;
                for( int k = i; k < j; ++k ) {
                    if( a[j] == a[k] )
                        dp[i][j] = min( dp[i][j], dp[i][k] + dp[k + 1][j - 1] );
                }
            }
        }
        printf( "%d\n", dp[1][n] );
    }
    return 0;
}
