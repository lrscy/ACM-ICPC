#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf( "%d", &n );
    puts( "2" );
    for( int i = 2; i <= n; ++i ) printf( "%lld\n", 1LL * i * ( i + 1 ) * ( i + 1 ) - ( i - 1 ) );
    return 0;
}
