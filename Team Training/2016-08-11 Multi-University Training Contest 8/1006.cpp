#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

LL v[MAXN];
int n, q, c, tt, k;

int main() {
    int t, x, d;
    scanf( "%d",  &t );
    while( t-- ) {
        scanf( "%d%d", &n, &c );
        for( int i = 0; i < n; ++i ) {
            scanf( "%I64d%d%d", v + i, &x, &d );
        }
        sort( v, v + n );
        scanf( "%d", &q );
        while( q-- ) {
            scanf( "%d%d", &tt, &k ); --k;
            printf( "%.3f\n", sqrt( v[k] * v[k] + 2.0 * c * tt ) );
        }
    }
    return 0;
}
