#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;

vector<int> vec;
double dp[1 << MAXN];
int a[MAXN];
int n;

bool judge( int i, int j, int k ) {
    if( a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[j] + a[k] > a[i] ) return true;
    return false;
}

double area( int a, int b, int c ) {
    double p = ( a + b + c ) * .5;
    return sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
}

int main() {
    while( ~scanf( "%d", &n ) && n ) {
        memset( dp, 0, sizeof dp );
        vec.clear();
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        sort( a, a + n );
        double ans = 0;
        for( int i = 0; i < n; ++i ) {
            for( int j = i + 1; j < n; ++j )
                for( int k = j + 1; k < n; ++k )
                    if( judge( i, j, k ) ) {
                        int msk = ( 1 << i ) | ( 1 << j ) | ( 1 << k );
                        dp[msk] = area( a[i], a[j], a[k] );
                        vec.push_back( msk );
                    }
        }
        int len = vec.size();
        for( int i = 0; i < ( 1 << n ); ++i ) {
            for( int j = 0; j < len; ++j ) {
                if( i & vec[j] ) continue;
                dp[i | vec[j]] = max( dp[i | vec[j]], dp[i] + dp[vec[j]] );
            }
        }
        printf( "%.2f\n", dp[( 1 << n ) - 1] );
    }
    return 0;
}
