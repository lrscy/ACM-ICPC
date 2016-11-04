#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;

int main() {
    int a, b, c, ans = INF;
    scanf( "%d%d%d", &a, &b, &c );
    for( int i = 1; i <= 100; ++i ) ans = min( ans, abs( a - i ) + abs( b - i ) + abs( c - i ) );
    printf( "%d\n", ans );
    return 0;
}
