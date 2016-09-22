#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL l, r;

int main() {
    while( ~scanf( "%I64d%I64d", &l, &r ) ) {
        if( r < 2 ) puts( "0" );
        else if( r == 2 ) puts( "1" );
        else if( l == r ) puts( "2" );
        else if( l == 0 ) printf( "%I64d\n", 1LL + ( r - 1 ) / 2 );
        else printf( "%I64d\n", 2LL + ( r - l - 2 ) / 2 );
    }
    return 0;
}
