#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

double dp[MAXN];
int n, m;

int main() {
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= m; ++i ) {
        dp[i] = dp[i - 1] + ( ( 1.0 * n - dp[i - 1] ) / n );
    }
    printf( "%.9f\n", dp[m] );
    return 0;
}
