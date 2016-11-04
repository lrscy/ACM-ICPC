#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN];
int n, m, len, tlen, x1, x2, y1, y2;

int gao1() {
    int ret;
    if( x1 + len - 1 <= y1 ) ret = a[x1 + len - 1];
    else ret = a[x2 + len - ( y1 - x1 + 1 ) - 1];
    return ret;
}

int gao2() {
    int ret;
    if( x1 + len - 1 < x2 ) ret = a[x1 + len - 1];
    else if( x1 + len - 1 > y1 + tlen ) ret = a[x1 + len - tlen - 1];
    else {
        int t = x1 + len - x2;
        ret = a[x2 + ( ( t + 1 ) >> 1 ) - 1];
    }
    return ret;
}

int gao3() {
    int ret;
    if( x1 + len - 1 < x2 ) ret = a[x1 + len - 1];
    else if( x1 + len - 1 > y2 + tlen ) ret = a[x1 + len - tlen - 1];
    else {
        int t = x1 + len - x2;
        ret = a[x2 + ( ( t + 1 ) >> 1 ) - 1];
    }
    return ret;
}

int main() {
    int t, ta, tb;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
        while( m-- ) {
            scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
            if( x1 > x2 ) { swap( x1, x2 ); swap( y1, y2 ); }
            len = y1 - x1 + 1 + y2 - x2 + 1;
            if( x2 > y1 ) {
                if( len & 1 ) {
                    len >>= 1; ++len;
                    ta = gao1();
                    printf( "%.1f\n", 1. * ta );
                } else {
                    len >>= 1;
                    ta = gao1();
                    ++len;
                    tb = gao1();
                    printf( "%.1f\n", .5 * ( 1LL * ta + tb ) );
                }
            } else if( y1 < y2 ) {
                if( len & 1 ) {
                    len >>= 1; ++len;
                    tlen = y1 - x2 + 1;
                    ta = gao2();
                    printf( "%.1f\n", 1. * ta );
                } else {
                    len >>= 1;
                    tlen = y1 - x2 + 1;
                    ta = gao2();
                    ++len;
                    tb = gao2();
                    printf( "%.1f\n", .5 * ( 1LL * ta + tb ) );
                }
            } else {
                if( len & 1 ) {
                    len >>= 1; ++len;
                    tlen = y2 - x2 + 1;
                    ta = gao3();
                    printf( "%.1f\n", 1. * ta );
                } else {
                    len >>= 1;
                    tlen = y2 - x2 + 1;
                    ta = gao3();
                    ++len;
                    tb = gao3();
                    printf( "%.1f\n", .5 * ( 1LL * ta + tb ) );
                }
            }
        }
    }
    return 0;
}
