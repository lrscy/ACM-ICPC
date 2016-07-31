#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int a[MAXN], dp[MAXN][5];
int n;

int main() {
    memset( dp, 0x3F, sizeof( dp ) );
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
    for( int i = 1; i <= n; ++i ) {
        if( a[i] == 0 ) dp[i][0] = min( dp[i - 1][0], min( dp[i - 1][1], dp[i - 1][2] ) ) + 1;
        else if( a[i] == 1 ) {
            dp[i][1] = min( dp[i - 1][1] + 1, min( dp[i - 1][0], dp[i - 1][2] ) );
            dp[i][0] = min( dp[i - 1][0], min( dp[i - 1][1], dp[i - 1][2] ) ) + 1;
        } else if( a[i] == 2 ) {
            dp[i][2] = min( dp[i - 1][2] + 1, min( dp[i - 1][0], dp[i - 1][1] ) );
            dp[i][0] = min( dp[i - 1][0], min( dp[i - 1][1], dp[i - 1][2] ) ) + 1;
        } else {
            dp[i][2] = min( dp[i - 1][2] + 1, min( dp[i - 1][0], dp[i - 1][1] ) );
            dp[i][1] = min( dp[i - 1][1] + 1, min( dp[i - 1][0], dp[i - 1][2] ) );
            dp[i][0] = min( dp[i - 1][0], min( dp[i - 1][1], dp[i - 1][2] ) ) + 1;
        }
    }
    printf( "%d\n", min( dp[n][0], min( dp[n][1], dp[n][2] ) ) );
    return 0;
}
