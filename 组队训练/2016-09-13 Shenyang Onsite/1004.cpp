#include <bits/stdc++.h>
using namespace std;

int gcd( int a, int b ) {
    if( a < b ) return gcd( b, a );
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

int main() {
    int t, n, a, b;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        scanf( "%d%d%d", &n, &a, &b );
        int t = gcd( a, b );
        int sum = n / t - 2;
        if( sum & 1 ) puts( "Yuwgna" );
        else puts( "Iaka" );
    }
    return 0;
}
