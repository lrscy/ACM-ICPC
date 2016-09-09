/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;

double a[MAXN];
int n;

int main() {
    double ans;
    while( ~scanf( "%d", &n ) ) {
        ans = 0;
        for( int i = 0; i < n; ++i ) scanf( "%lf", a + i );
        double sum = 0;
        for( int i = 1; i < ( 1 << n ); ++i ) {
            double sum = 0;
            for( int j = 0; j < n; ++j ) {
                if( i & ( 1 << j ) )
                    sum += a[j];
            }
            if( __builtin_popcount( i ) & 1 ) ans += 1. / sum;
            else ans -= 1. / sum;
        }
        printf( "%.6f\n", ans );
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;

double dp[1 << MAXN], a[MAXN];
int n;

int main() {
    while( ~scanf( "%d", &n ) ) {
        double sum = 0;
        for( int i = 0; i < n; ++i ) scanf( "%lf", a + i ), sum += a[i];
        dp[( 1 << n ) - 1] = 0;
        for( int i = ( 1 << n ) - 2; i >= 0; --i ) {
            double tsum = 1, tt = 0;
            for( int j = 0; j < n; ++j ) {
                if( i & ( 1 << j ) ) tt += a[j];
                else tsum += a[j] * dp[i | ( 1 << j )];
            }
            dp[i] = tsum / ( sum - tt );
        }
        printf( "%.6f\n", dp[0] );
    }
    return 0;
}
