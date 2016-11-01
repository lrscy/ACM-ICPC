#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> PIC;
const int MAXN = 1e3 + 10;

vector<PIC> vec;
int a[MAXN], b[MAXN];
int n, m;

bool gao( int l, int r, int pos ) {
    int mx = 0;
    for( int i = l; i <= r; ++i ) if( mx < a[i] ) mx = a[i];
    for( int i = l; i <= r; ++i ) if( a[i] == mx ) {
        if( i > l && a[i] > a[i - 1] ) {
            int j = i + 1, k;
            for( ; i > l; --i ) vec.push_back( PIC( pos + i - l + 1, 'L' ) ), a[i - 1] += a[i];
            for( k = i + 1; j <= r; ++j, ++k ) a[k] = a[j];
            mx = a[i]; r = k - 1; --i;
        } else if( i < r && a[i] > a[i + 1] ) {
            for( int j = i + 1; j <= r; ++j ) vec.push_back( PIC( pos + i - l + 1, 'R' ) ), a[i] += a[j];
            mx = a[i]; r = i; --i;
        }
    }
    return ( l == r );
}

int main() {
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
    scanf( "%d", &m );
    for( int i = 1; i <= m; ++i ) scanf( "%d", b + i );
    int tsum = 0, j = 1;
    bool flag = true;
    for( int i = 1, pre = 1; i <= n && flag; ++i ) {
        tsum += a[i];
        if( j > m ) flag = false;
        if( tsum == b[j] ) {
            if( !gao( pre, i, j - 1 ) ) flag = false;
            tsum = 0; pre = i + 1; ++j;
        } else if( tsum > b[j] ) flag = false;
    }
    if( tsum != 0 || j <= m ) flag = false;
    if( flag ) {
        puts( "YES" );
        int len = vec.size();
        for( int i = 0; i < len; ++i ) printf( "%d %c\n", vec[i].first, vec[i].second );
    } else puts( "NO" );
    return 0;
}
