#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, cnt;
    while( ~scanf( "%d", &n ) ) {
        cnt = 0;
        for( int i = 0, x; i < n; ++i ) {
            scanf( "%d", &x );
            while( x ) {
                if( x % 256 == 97 ) ++cnt;
                x >>= 8;
            }
        }
        printf( "%d\n", cnt );
    }
    return 0;
}
