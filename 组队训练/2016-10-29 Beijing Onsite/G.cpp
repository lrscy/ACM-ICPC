#include <bits/stdc++.h>
using namespace std;

int x[5], y[5];

bool gao2( int a, int b, int c ) {
    if( x[a] == x[b] && x[b] == x[c] ) return true;
    if( y[a] == y[b] && y[b] == y[c] ) return true;
    if( x[a] == x[b] + x[c] && y[b] == y[c] ) return true;
    if( x[b] == x[a] + x[c] && y[a] == y[c] ) return true;
    if( x[c] == x[a] + x[b] && y[a] == y[b] ) return true;
    if( y[a] == y[b] + y[c] && x[b] == x[c] ) return true;
    if( y[b] == y[a] + y[c] && x[a] == x[c] ) return true;
    if( y[c] == y[a] + y[b] && x[a] == x[b] ) return true;
    return false;
}

bool gao( int a, int b, int c ) {
    for( int i = 0; i < 8; ++i ) {
        if( i & 1 ) swap( x[a], y[a] );
        if( i & 2 ) swap( x[b], y[b] );
        if( i & 4 ) swap( x[c], y[c] );
        if( gao2( a, b, c ) ) return true;
        if( i & 4 ) swap( x[c], y[c] );
        if( i & 2 ) swap( x[b], y[b] );
        if( i & 1 ) swap( x[a], y[a] );
    }
    return false;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        for( int i = 1; i <= 4; ++i ) scanf( "%d%d", x + i, y + i );
        if( gao( 1, 2, 3 ) || gao( 1, 2, 4 ) || gao( 1, 3, 4 ) || gao( 2, 3, 4 ) ) puts( "Yes" );
        else puts( "No" );
    }
    return 0;
}
