#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    double s1, s2;
    scanf( "%d%d", &a, &b );
    if( a < b ) puts( "-1" );
    else if( a == b ) printf( "%.11f\n", 1.0 * b );
    else {
        s1 = 1.0 * ( a + b ) / 2 / ( ( a + b ) / 2 / b );
        s2 = 1.0 * ( a - b ) / 2 / ( ( a - b ) / 2 / b );
        printf( "%.11f\n", min( s1, s2 ) );
    }
    return 0;
}
