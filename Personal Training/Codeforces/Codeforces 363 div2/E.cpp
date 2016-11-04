#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;

LL a[MAXN], b[MAXN], l[MAXN], r[MAXN];
int n, k, x;

int main() {
    int tmp;
    scanf( "%d%d%d", &n, &k, &x );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%I64d", a + i );
        b[i] = a[i]; tmp = k;
        while( tmp-- ) b[i] *= x;
    }
    l[0] = r[n + 1] = 0;
    for( int i = 1; i <= n; ++i ) l[i] = l[i - 1] | a[i];
    for( int i = n; i >= 1; --i ) r[i] = r[i + 1] | a[i];
    LL ans = 0;
    for( int i = 1; i <= n; ++i ) {
        b[i] = l[i - 1] | b[i] | r[i + 1];
        if( b[i] > ans ) ans = b[i];
    }
    printf( "%I64d\n", ans );
    return 0;
}
