#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while( ~scanf( "%d", &n ) ) {
        if( n == 1 ) puts( "0" );
        else puts( ( n & 1 ) ? "0" : "1" );
    }
    return 0;
}
