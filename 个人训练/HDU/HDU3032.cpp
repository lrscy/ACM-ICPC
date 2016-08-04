#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n;

int main() {
    int t, ta;
    scanf( "%d", &t );
    while( t-- ) {
        int ans = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%d", &ta );
            if( ta % 4 == 0 ) ans ^= ( ta - 1 );
            else if( ta % 4 == 1 || ta % 4 == 2 ) ans ^= ta;
            else ans ^= ( ta + 1 );
        }
        if( ans ) puts( "Alice" );
        else puts( "Bob" );
    }
    return 0;
}
