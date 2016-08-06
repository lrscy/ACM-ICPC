#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, na = 0, nb = 0, a, b;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i ) {
        scanf( "%d%d", &a, &b );
        if( a == b ) continue;
        if( a > b ) ++na;
        if( a < b ) ++nb;
    }
    if( na == nb ) puts( "Friendship is magic!^^" );
    else if( na > nb ) puts( "Mishka" );
    else puts( "Chris" );
    return 0;
}
