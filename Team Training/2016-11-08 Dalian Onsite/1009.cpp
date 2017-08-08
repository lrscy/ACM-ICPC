#include <bits/stdc++.h>
using namespace std;
const double pi = acos( -1.0 );

double a[20];

int main() {
    int n, d;
    double ans;
    while( ~scanf( "%d%d", &n, &d ) ) {
        ans = 0;
        for( int i = 0; i < n; ++i ) {
            scanf( "%lf", a + i );
            ans += 1.0 * d * d * sin( pi / 180.0 * a[i] );
        }
        printf( "%.3f\n", ans / 2 );
    }
    return 0;
}
