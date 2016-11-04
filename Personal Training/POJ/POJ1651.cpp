#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 100 + 10;

int a[MAXN], dp[MAXN][MAXN];
int n;

int main() {
    memset( dp, 0, sizeof( dp ) );
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
    for( int m = 3; m <= n; ++m ) {
        for( int i = 1; i <= n - m + 1; ++i ) {
            int j = i + m - 1;
            dp[i][j] = INF;
            for( int k = i + 1; k < j; ++k ) {
                dp[i][j] = min( dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j] );
            }
        }
    }
    printf( "%d\n", dp[1][n] );
    return 0;
}
