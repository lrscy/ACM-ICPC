#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    int n, m;
    while( ~scanf( "%d%d", &n, &m ) ) {
        LL tmp = 1LL * ( int )ceil( 1. * n / 2 ) * ( int )( n / 2 );
        puts( tmp > m ? "F" : "T" ) ;
    }
    return 0;
}
