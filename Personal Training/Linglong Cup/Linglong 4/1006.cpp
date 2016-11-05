#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        int n;
        scanf( "%d", &n );
        if( n % 4 == 0 || n % 4 == 1 ) puts( "yes" );
        else puts( "no" );
    }
    return 0;
}
