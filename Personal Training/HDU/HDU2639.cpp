#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXM = 50;

int a[MAXN], b[MAXN], c[MAXN], dp[MAXN][MAXM];
int n, v, m;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( dp, 0, sizeof( dp ) );
        scanf( "%d%d%d", &n, &v, &m );
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        for( int i = 0; i < n; ++i ) scanf( "%d", b + i );
        for( int i = 0; i < n; ++i ) {
            for( int j = v; j >= b[i]; --j ) {
                int cnt = 0, p = 0;
                for( int k = 0; k < m; ++k ) {
                    c[cnt++] = dp[j][k];
                    c[cnt++] = dp[j - b[i]][k] + a[i];
                }
                sort( c, c + cnt );
                for( int k = cnt - 1; k >= 0 && p < m; --k ) {
                    if( k == cnt - 1 || c[k] != c[k + 1] )
                        dp[j][p++] = c[k];
                }
            }
        }
        printf( "%d\n", dp[v][m - 1] );
    }
    return 0;
}
