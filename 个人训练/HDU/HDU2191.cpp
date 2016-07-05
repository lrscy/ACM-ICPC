#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int a[MAXN], b[MAXN], dp[MAXN];
int n, m;

int main() {
    int t, ta, tb, tc;
    scanf( "%d", &t );
    while( t-- ) {
        memset( dp, 0x80, sizeof( dp ) ); dp[0] = 0;
        int tn = 0;
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d%d", &ta, &tb, &tc );
            for( int j = 0; ( 1 << j ) <= tc; ++j ) {
                a[tn] = ( 1 << j ) * ta;
                b[tn] = ( 1 << j ) * tb;
                tc -= ( 1 << j );
                ++tn;
            }
            if( tc ) { a[tn] = tc * ta; b[tn] = tc * tb; ++tn; }
        }
        m = tn;
        for( int i = 0; i < m; ++i ) {
            for( int j = n; j >= a[i]; --j )
                dp[j] = max( dp[j], dp[j - a[i]] + b[i] );
        }
        printf( "%d\n", dp[n] );
    }
    return 0;
}
