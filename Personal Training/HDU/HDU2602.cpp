#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int a[MAXN], b[MAXN], dp[MAXN];
int n, v;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( dp, 0, sizeof( dp ) );
        scanf( "%d%d", &n, &v );
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        for( int i = 0; i < n; ++i ) scanf( "%d", b + i );
        for( int i = 0; i < n; ++i ) {
            for( int j = v; j >= b[i]; --j )
                dp[j] = max( dp[j], dp[j - b[i]] + a[i] );
        }
        printf( "%d\n", dp[v] );
    }
    return 0;
}
