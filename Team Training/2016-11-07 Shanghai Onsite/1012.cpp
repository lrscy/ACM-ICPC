#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 10;

set<PII> s;
int a[MAXN];
int n, m, tg;

int gcd( int x, int y ) { return y == 0 ? x : gcd( y, x % y ); }

int gao( int x, int y ) {
    if( x > y ) swap( x, y );
    int m1, m2, ret = 1;
    m1 = x / tg;
    if( y / tg % ( m1 + 1 ) ) return 1;
    m2 = y / tg / ( m1 + 1 );
    ret += gao( m1 * tg, m2 * tg );
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        scanf( "%d%d", &n, &m );
        tg = gcd( n, m );
        printf( "%d\n", gao( n, m ) );
    }
    return 0;
}
