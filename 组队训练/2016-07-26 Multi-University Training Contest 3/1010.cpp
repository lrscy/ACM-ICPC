#include <bits/stdc++.h>
using namespace std;

int v1, v2, a;

int main() {
    while( ~scanf( "%d%d%d", &a, &v1, &v2 ) ) {
        if( a == 0 ) { puts( "0.0000" ); continue; }
        if( v1 <= v2 ) puts( "Infinity" );
        else printf( "%f\n", 1.0 * v1 * a / ( v1 * v1 - v2 * v2 ) );
    }
    return 0;
}
