#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int a[MAXN];
int n;

int main() {
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
    for( int i = 0; i < n - 1; ++i ) {
        if( a[i] < 0 ) { puts( "NO" ); return 0; }
        if( a[i] & 1 ) --a[i + 1];
    }
    if( a[n - 1] < 0 || ( a[n - 1] & 1 ) ) puts( "NO" );
    else puts( "YES" );
    return 0;
}
