#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN], cnt[MAXN];
int n, m;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        bool flag = false;
        memset( cnt, 0, sizeof( cnt ) );
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d", a + i );
            a[i] += a[i - 1];
            a[i] %= m;
            ++cnt[a[i]];
            if( cnt[a[i]] > 1 || a[i] == 0 ) flag = true;
        }
        puts( flag ? "YES" : "NO" );
    }
    return 0;
}
