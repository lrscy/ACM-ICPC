#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;

int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a % b ); }

int main() {
    while( ~scanf( "%d%d", &n, &m ) ) {
        int tg = gcd( n, m );
        n /= tg; m /= tg;
        LL tmp = 1LL * n * n - 4 * m;
        LL ts = sqrt( tmp );
        if( ts * ts != tmp ) { puts( "No Solution" ); continue; }
        printf( "%d %d\n", ( int )( n - ts ) / 2 * tg, ( int )( n + ts ) / 2 * tg );
    }
    return 0;
}
