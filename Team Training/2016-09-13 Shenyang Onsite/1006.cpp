#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e4 + 10;

int a[MAXN], vis[MAXN], num[MAXN];
int n, m, tn;

int gcd( int a, int b ) { if( b == 0 ) return a; return gcd( b, a % b ); }

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( vis, 0, sizeof vis );
        memset( num, 0, sizeof num );
        tn = 0;
        scanf( "%d%d", &n, &m );
        for( int i = 1; i * i <= m; ++i ) {
            if( m % i == 0 ) {
                a[tn++] = i;
                if( i * i != m ) a[tn++] = m / i;
            }
        }
        sort( a, a + tn );
        for( int i = 0, tmp, tt; i < n; ++i ) {
            scanf( "%d", &tmp );
            tt = gcd( tmp, m );
            for( int j = 0; j < tn; ++j ) if( a[j] % tt == 0 ) vis[j] = 1;
        }
        vis[tn - 1] = 0;
        LL ans = 0;
        for( int i = 0; i < tn; ++i ) {
            if( vis[i] != num[i] ) {
                LL tmp = m / a[i];
                ans += tmp * ( tmp - 1 ) / 2 * a[i] * ( vis[i] - num[i] );
                tmp = vis[i] - num[i];
                for( int j = i; j < tn; ++j ) if( a[j] % a[i] == 0 ) num[j] += tmp;
            }
        }
        printf( "%I64d\n", ans );
    }
    return 0;
}
