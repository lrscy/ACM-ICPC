#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e5 + 10;

int c[MAXN], w[MAXN], dp[MAXN];
int n;

int main() {
    int t, e, f;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d%d", &e, &f, &n );
        int sum = f - e;
        for( int i = 0; i < n; ++i ) scanf( "%d%d", w + i, c + i );
        memset( dp, 0x7F, sizeof( dp ) );
        dp[0] = 0;
        for( int i = 0; i < n; ++i ) {
            for( int j = c[i]; j <= sum; ++j )
                dp[j] = min( dp[j - c[i]] + w[i], dp[j] );
        }
        if( dp[sum] != INF ) printf( "The minimum amount of money in the piggy-bank is %d.\n", dp[sum] );
        else puts( "This is impossible." );
    }
    return 0;
}
