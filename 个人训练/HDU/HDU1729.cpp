#include <bits/stdc++.h>
using namespace std;

int n;

int gao( int a, int b ) {
    int q = ( int )sqrt( 1.0 * a );
    while( q + q * q >= a ) --q;
    if( q < b ) return a - b;
    return gao( q, b );
}

int main() {
    int ta, tb, tt = 0;
    while( ~scanf( "%d", &n ) && n ) {
        int ans = 0;
        for( int i = 0; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            if( ta == 0 || tb == 0 || ta == tb ) continue;
            ans ^= gao( ta, tb );
        }
        printf( "Case %d:\n", ++tt );
        if( ans ) puts( "Yes" );
        else puts( "No" );
    }
    return 0;
}
