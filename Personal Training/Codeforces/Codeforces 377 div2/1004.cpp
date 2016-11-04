#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int d[MAXN], a[MAXN];
bool vis[MAXN];
int n, m;

bool gao( int mid ) {
    memset( vis, false, sizeof vis );
    int cnt = 0, tot = m; vis[0] = true;
    for( int i = mid; i >= 1; --i ) {
        if( !vis[d[i]] ) {
            if( cnt < 0 ) cnt = 0;
            cnt += a[d[i]]; vis[d[i]] = true; --tot;
        } else --cnt;
    }
    if( tot > 0 || cnt > 0 ) return false;
    return true;
}

int main() {
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i ) scanf( "%d", d + i );
    for( int i = 1; i <= m; ++i ) scanf( "%d", a + i );
    int low = 1, high = n;
    while( low < high ) {
        int mid = ( low + high ) >> 1;
        if( gao( mid ) ) high = mid;
        else low = mid + 1;
    }
    if( low == n && !gao( low ) ) puts( "-1" );
    else printf( "%d\n", low );
    return 0;
}
