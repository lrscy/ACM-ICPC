#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int a[MAXN], b[MAXN];
int n, m;

int main() {
    scanf( "%d%d", &n, &m );
    int ans = 0;
    for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
    for( int i = 1; i < n; ++i ) {
        if( a[i - 1] + a[i] < m ) {
            ans += m - a[i - 1] - a[i];
            a[i] = m - a[i - 1];
        }
    }
    printf( "%d\n", ans );
    for( int i = 0; i < n - 1; ++i ) printf( "%d ", a[i] ); printf( "%d\n", a[n - 1] );
    return 0;
}
