#include <bits/stdc++.h>
using namespace std;
const int NINF = 0x80808080;
const int MAXN = 1e3 + 10;
const int MAXM = 1e5 + 10;

int a[MAXN], b[MAXN], dp[MAXM];
int n, m;

void zeroonepack( int w, int c ) {
    for( int i = m; i >= c; --i ) {
        dp[i] = max( dp[i], dp[i - c] + w );
    }
    return ;
}

void completepack( int w, int c ) {
    for( int i = c; i <= m; ++i ) {
        dp[i] = max( dp[i], dp[i - c] + w );
    }
    return ;
}

void multipack( int w, int c, int cnt ) {
    if( w * cnt >= m ) completepack( w, c );
    else {
        int k = 1;
        while( k <= cnt ) {
            zeroonepack( k * w, k * c );
            cnt -= k;
            k <<= 1;
        }
        if( cnt ) zeroonepack( cnt * w, cnt * c );
    }
    return ;
}

int main() {
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        int tn = 0;
        memset( dp, 0x80, sizeof( dp ) ); dp[0] = 0;
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        for( int i = 0; i < n; ++i ) scanf( "%d", b + i );
        for( int i = 0; i < n; ++i ) multipack( a[i], a[i], b[i] );
        for( int i = 1; i <= m; ++i ) if( dp[i] == i ) ++tn;
        printf( "%d\n", tn );
    }
    return 0;
}
