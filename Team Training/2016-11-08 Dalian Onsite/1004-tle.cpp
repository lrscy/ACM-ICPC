#include <bits/stdc++.h>
using namespace std;

int n, m;

int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a % b ); }

bool gao( int a ) {
    int tg, ta, tb;
    for( int i = 1; i * a <= n; ++i ) {
        ta = i * a; tb = n - ta; tg = gcd( ta, tb );
        if( ta / tg * tb == m ) {
            if( ta > tb ) swap( ta, tb );
            printf( "%d %d\n", ta, tb );
            return true;
        }
    }
    return false;
}

int main() {
    int a, b;
    while( ~scanf( "%d%d", &n, &m ) ) {
        bool flag = false;
        for( int i = 2; i * i <= m; ++i ) {
            if( m % i == 0 ) {
                if( gao( i ) || ( m / i != i && gao( m / i ) ) ) {
                    flag = true;
                    break;
                }
            }
        }
        if( !gao( m ) && !flag ) puts( "No Solution" );
    }
    return 0;
}
