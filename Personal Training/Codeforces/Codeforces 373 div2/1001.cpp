#include <bits/stdc++.h>
using namespace std;

int a[20];
int n;

int main() {
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
    if( n == 1 ) {
        if( a[0] == 0 ) puts( "UP" );
        else if( a[0] == 15 ) puts( "DOWN" );
        else puts( "-1" );
        return 0;
    }
    if( a[n - 1] == 15 ) puts( "DOWN" );
    else if( a[n - 1] == 0 ) puts( "UP" );
    else {
        if( a[n - 1] > a[n - 2] ) puts( "UP" );
        else puts( "DOWN" );
    }
    return 0;
}
