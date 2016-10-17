#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long

LL c, s;

LL gcd( LL a, LL b ) {
    return b == 0 ? a : gcd( b, a % b );
}

LL pow( LL a, LL b ) {
    LL ans = 1;
    while( b ) {
        if( b & 1 ) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

LL polya() {
    LL i, j;
    LL sum = 0;
    for( i = 1; i <= s; i++ )
        sum += pow( c, gcd( s, i ) );
    if( s & 1 )
        sum += s * pow( c, s / 2 + 1 );
    else
        sum += ( ( s / 2 ) * pow( c, s / 2 ) ) + ( ( s / 2 ) * pow( c, s / 2 + 1 ) );
    sum /= ( 2 * s );
    return sum;
}

int main() {
    while( ~scanf( "%I64d%I64d", &c, &s ) && ( c || s ) )
        printf( "%I64d\n", polya() );
    return 0;
}
