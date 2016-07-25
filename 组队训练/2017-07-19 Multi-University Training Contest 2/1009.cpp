#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int a[MAXN];
int n, m;

int gcd( int a, int b ) {
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

int main() {
    int t, ta, tb;
    scanf( "%d", &t );
    while( t-- ) {
        memset( a, -1, sizeof( a ) );
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d", &ta, &tb );
            a[ta] = tb;
        }
        int nmin = 0, sum = 0;
        for( int i = n; i > 2; --i ) {
            if( ~a[i] ) nmin = a[i];
            sum += nmin;
        }
        if( a[2] == -1 ){
            if( a[1] != -1 ) a[2] = a[1];
            else a[2] = 100;
        }
        if( a[1] == -1 ) a[1] = 100;
        ta = a[1] + a[2];
        sum += ta;
        tb = gcd( ta, sum );
        ta /= tb; sum /= tb;
        printf( "%d/%d\n", ta, sum );
    }
    return 0;
}
