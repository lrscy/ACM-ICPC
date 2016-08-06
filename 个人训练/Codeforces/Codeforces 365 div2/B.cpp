#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN];
int n, m;

int main() {
    LL sum = 0, ans = 0;
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < n; ++i ) {
        scanf( "%d", a + i );
        sum += a[i];
        if( i ) ans += 1LL * a[i] * a[i - 1];
    }
    ans += 1LL * a[0] * a[n - 1];
    LL tsum = 0, tans = 0;
    int ta, tb;
    for( int i = 0; i < m; ++i ) {
        scanf( "%d", b + i ); --b[i];
        tsum += a[b[i]];
        ta = ( b[i] - 1 + n ) % n; tb = ( b[i] + 1 ) % n;
        ans += ( sum - a[b[i]] - a[ta] - a[tb] ) * a[b[i]];
    }
    for( int i = 0; i < m; ++i ) {
        LL tmp = tsum - a[b[i]];
        tans += tmp * a[b[i]];
    }
    tans /= 2;
    ans -= tans;
    for( int i = 1; i < m; ++i ) {
        if( b[i - 1] + 1 == b[i] ) ans += a[b[i - 1]] * a[b[i]];
    }
    if( b[0] == 0 && b[m - 1] == n - 1 ) ans += a[0] * a[n - 1];
    printf( "%lld\n", ans );
    return 0;
}
