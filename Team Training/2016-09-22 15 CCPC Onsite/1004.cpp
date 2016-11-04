#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3F3F3F3F3F3F3F3F;
const int MAXN = 4e3 + 10;

LL dp[MAXN][3], c[MAXN];
int w[MAXN];
int n, m;

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( dp, 0, sizeof dp );
        LL ans = 0;
        scanf( "%d%d", &n, &m );
        m <<= 1;
        for( int i = 0; i < n; ++i ) scanf( "%d%I64d", w + i, c + i ), w[i] <<= 1, ans = max( ans, c[i] );
        for( int i = 0; i < n; ++i ) {
            for( int j = m; j >= w[i] / 2; --j ) {
                for( int k = 0; k < 3; ++k ) {
                    if( j >= w[i] ) dp[j][k] = max( dp[j][k], dp[j - w[i]][k] + c[i] );
                    if( k > 0 ) dp[j][k] = max( dp[j][k], dp[j - w[i] / 2][k - 1] + c[i] );
                    ans = max( ans, dp[j][k] );
                }
            }
        }
        printf( "%I64d\n", ans );
    }
    return 0;
}
