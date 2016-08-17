#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0, a;
    scanf( "%d", &n );
    while( n-- ) {
        scanf( "%d", &a );
        if( a & 1 ) ans ^= 0;
        else ans ^= 1;
        puts( ans ? "1" : "2" );
    }
    return 0;
}
