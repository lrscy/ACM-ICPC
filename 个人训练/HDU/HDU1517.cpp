#include <bits/stdc++.h>
using namespace std;

int main() {
    double n;
    while( ~scanf( "%lf", &n ) ) {
        while( n > 18 ) n /= 18;
        if( n <= 9 ) puts( "Stan wins." );
        else puts( "Ollie wins." );
    }
    return 0;
}
