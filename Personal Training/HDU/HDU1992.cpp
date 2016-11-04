#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 10;

LL dp[2][1 << 4];
int n, cur;

void update( int a, int b ) {
    if( b & ( 1 << 4 ) ) dp[cur][b ^ ( 1 << 4 )] += dp[1 - cur][a];
    return ;
}

int main() {
    int t, tot = 0;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d", &n );
        memset( dp, 0, sizeof( dp ) );
        cur = 0; dp[0][( 1 << 4 ) - 1] = 1;
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < 4; ++j ) {
                cur ^= 1;
                memset( dp[cur], 0, sizeof( dp[cur] ) );
                for( int k = 0; k < ( 1 << 4 ); ++k ) {
                    update( k, k << 1 );
                    if( i && !( k & ( 1 << 3 ) ) ) update( k, ( k << 1 ) ^ ( 1 << 4 ) ^ 1 );
                    if( j && !( k & 1 ) ) update( k, ( k << 1 ) ^ 3 );
                }
            }
        }
        printf( "%d %I64d\n", ++tot, dp[cur][( 1 << 4 ) - 1] );
    }
    return 0;
}
