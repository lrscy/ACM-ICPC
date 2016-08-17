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
            if( ta % 8 == 0 ) ans ^= ta - 1;
            else if( ta % 8 == 7 ) ans ^= ta + 1;
            else ans ^= ta;
        }
        if( ans ) puts( "First player wins." );
        else puts( "Second player wins." );
    }
    return 0;
}
