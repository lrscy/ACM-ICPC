#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

double c[MAXN], x[MAXN];
int le[MAXN], ri[MAXN];
double r;
int n, m;

int main() {
    double ans = 0;
    scanf( "%d%d%lf", &m, &n, &r );
    for( int i = 0; i < m; ++i ) scanf( "%lf", c + i );
    for( int i = 0; i < n; ++i ) scanf( "%lf", x + i );
    for( int i = 0; i < n; ++i ) {
        double dl = x[i] - sqrt( r * r - 1 );
        double dr = x[i] + sqrt( r * r - 1 );
        le[i] = lower_bound( c, c + m, dl ) - c;
        ri[i] = upper_bound( c, c + m, dr ) - 1 - c;
    }
    int cur = 0;
    for( int i = 0; i < n; ++i ) {
        if( cur < le[i] ) {
            ans += abs( c[le[i]] - c[cur] );
            cur = le[i];
        } else if( cur > ri[i] ) {
            ans += abs( c[ri[i]] - c[cur] );
            cur = ri[i];
        }
    }
    printf( "%.1f\n", ans );
    return 0;
}
