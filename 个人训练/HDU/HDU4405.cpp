#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

double dp[MAXN];
int f[MAXN];
int n, m;

int main() {
    int x, y;
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        memset( dp, 0, sizeof( dp ) );
        memset( f, -1, sizeof( f ) );
        while( m-- ) {
            scanf( "%d%d", &x, &y );
            f[x] = y;
        }
        for( int i = n - 1; i >= 0; --i ) {
            if( ~f[i] ) dp[i] = dp[f[i]];
            else {
                for( int j = 1; j <= 6; ++j ) {
                    dp[i] += 1. / 6 * dp[i + j];
                }
                ++dp[i];
            }
        }
        printf( "%.4f\n", dp[0] );
    }
    return 0;
}
