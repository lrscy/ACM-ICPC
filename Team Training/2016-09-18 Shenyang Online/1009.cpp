#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 10;

LL dp[MAXN][MAXN], b[MAXN];
int a[MAXN];
bool vis[MAXN][MAXN]; // 0: left 1: full
int n;

int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a % b ); }

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( vis, false, sizeof vis );
        memset( dp, 0, sizeof dp );
        scanf( "%d", &n );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
        for( int i = 1; i <= n; ++i ) scanf( "%I64d", b + i );
        for( int i = 1; i < n; ++i ) {
            if( gcd( a[i], a[i + 1] ) != 1 ) {
                vis[i][i + 1] = true;
                dp[i][i + 1] = b[i] + b[i + 1];
            }
        }
        for( int m = 3; m <= n; ++m ) {
            for( int i = 1; i + m - 1 <= n; ++i ) {
                int j = i + m - 1;
                for( int k = i; k <= j; ++k ) {
                    if( dp[i][j] < dp[i][k] + dp[k + 1][j] ) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                        vis[i][j] = ( vis[i][k] & vis[k + 1][j] );
                    }
                }
                if( i + 2 < j && vis[i + 1][j - 1] && gcd( a[i], a[j] ) != 1 ) {
                    dp[i][j] = max( dp[i][j], b[i] + b[j] + dp[i + 1][j - 1] );
                    vis[i][j] = true;
                }
            }
        }
        printf( "%I64d\n", dp[1][n] );
    }
    return 0;
}
