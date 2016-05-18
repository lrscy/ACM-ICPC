#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

int a[MAXN];
double b[MAXN], dp[MAXN];
int n, m;

int main() {
    while( ~scanf( "%d%d", &n, &m ) && m + n ) {
        fill( dp, dp + MAXN, 1 );
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%lf", a + i, b + i );
            b[i] = 1.0 - b[i];
        }
        for( int i = 0; i < m; ++i ) {
            for( int j = n; j >= a[i]; --j ) {
                dp[j] = min( dp[j], dp[j - a[i]] * b[i] );
            }
        }
        printf( "%.1f%%\n", ( 1 - dp[n] ) * 100 );
    }
    return 0;
}
