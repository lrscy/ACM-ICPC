#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 10;

int a[MAXN], b[MAXN], c[MAXN];
int n, m, tot;

int main() {
    tot = 0;
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < n; ++i ) {
        scanf( "%d", a + i );
        if( 1 <= a[i] && a[i] <= m) ++b[a[i]];;
    }
    int ans1 = n / m, ans2 = 0;
    for( int i = 1; i <= m; ++i ) if( b[i] < ans1 ) ans2 += ans1 - b[i], c[tot++] = i;
    for( int i = 0, j = 0; i < n && j < tot; ++i ) {
        if( !( 1 <= a[i] && a[i] <= m ) || b[a[i]] > ans1 ) {
            if( b[c[j]] < ans1 ) {
                if( 1 <= a[i] && a[i] <= m ) --b[a[i]];
                a[i] = c[j];
                ++b[c[j]];
            }
            if( b[c[j]] >= ans1 ) ++j;
        }
    }
    printf( "%d %d\n%d", ans1, ans2, a[0] );
    for( int i = 1; i < n; ++i ) printf( " %d", a[i] );
    puts( "" );
    return 0;
}
