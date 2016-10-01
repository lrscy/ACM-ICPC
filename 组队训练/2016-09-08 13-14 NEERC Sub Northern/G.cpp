#include <bits/stdc++.h>
using namespace std;

int W, H, w, h;

int main() {
//    freopen( "garage.in", "r", stdin );
//    freopen( "garage.out", "w+", stdout );
    scanf( "%d%d%d%d", &W, &H, &w, &h );
//    printf( "%d\n", ( W / w / 2 + W / w % 2 ) * ( H / h / 2 + H / h % 2 ) )
    printf( "%d\n", ( int )ceil( 1. * W / w / 2 ) * ( int )ceil( 1. * H / h / 2 ) )
    return 0;
}
