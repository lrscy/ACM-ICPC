#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int a[MAXN], b[MAXN], dp[MAXN][MAXN];
int n, m, k, s;

int main() {
    while( ~scanf( "%d%d%d%d", &n, &m, &k, &s ) ) {
        memset( dp, 0x80, sizeof( dp ) );
        dp[0][0] = 0;
        for( int i = 1; i <= k; ++i ) scanf( "%d%d", a + i, b + i );
        for( int i = 1; i <= k; ++i ) {
            for( int j = b[i]; j <= m; ++j )
                for( int k = 1; k <= s; ++k )
                    dp[j][k] = max( dp[j][k], dp[j - b[i]][k - 1] + a[i] );
        }
        int ans = 0;
        bool flag = false;
        for( int i = 0; i <= m && !flag; ++i ) {
            for( int j = 1; j <= s && !flag; ++j ) {
                if( dp[i][j] >= n ) {
                    flag = true;
                    ans = i;
                }
            }
        }
        if( !flag ) puts( "-1" );
        else printf( "%d\n", m - ans );
    }
    return 0;
}
