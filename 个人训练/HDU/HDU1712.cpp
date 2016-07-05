#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int a[MAXN][MAXN], dp[MAXN];
int n, m;

int main() {
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        for( int i = 1; i <= n; ++i ) {
            for( int j = 1; j <= m; ++j )
                scanf( "%d", &a[i][j] );
        }
        memset( dp, 0, sizeof( dp ) );
        for( int i = 1; i <= n; ++i ) {
            for( int j = m; j >= 0; --j )
                for( int k = 1; k <= m; ++k )
                    if( j >= k )
                        dp[j] = max( dp[j], dp[j - k] + a[i][k] );
        }
        printf( "%d\n", dp[m] );
    }
    return 0;
}
