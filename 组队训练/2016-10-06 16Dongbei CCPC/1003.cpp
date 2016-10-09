#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a, b, c, d;

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d:\n", ncas );
        scanf( "%I64d%I64d", &a, &b );
        puts( ( a == b ) ? "1" : "2" );
        printf( "%I64d %I64d\n", a, b );
        if( a != b ) printf( "%I64d %I64d\n", b, a );
    }
    return 0;
}
