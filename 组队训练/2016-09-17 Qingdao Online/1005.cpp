#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d", &n );
        if( n & 1 ) puts( "Balanced" );
        else puts( "Bad" );
    }
    return 0;
}
