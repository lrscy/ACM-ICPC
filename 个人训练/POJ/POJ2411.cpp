#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 15;

LL dp[2][1 << MAXN];
int n, m, cur;

void update( int a, int b ) {
    if( b & ( 1 << m ) ) dp[cur][b ^ ( 1 << m )] += dp[1 - cur][a];
    return ;
}

int main() {
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        if( n < m ) swap( n, m );
        memset( dp, 0, sizeof( dp ) );
        cur = 0; dp[cur][( 1 << m ) - 1] = 1;
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                cur ^= 1;
                memset( dp[cur], 0, sizeof( dp[cur] ) );
                for( int s = 0; s < ( 1 << m ); ++s ) {
                    update( s, s << 1 );
                    if( i && !( s & ( 1 << ( m - 1 ) ) ) ) update( s, ( s << 1 ) ^ ( 1 << m ) ^ 1 );
                    if( j && !( s & 1 ) ) update( s, ( s << 1 ) ^ 3 );
                }
            }
        }
        printf( "%lld\n", dp[cur][( 1 << m ) - 1] );
    }
    return 0;
}
