#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN], st[MAXN][20], lg2[MAXN];
int n, m;

void init() {
    for( int i = 0; i < n; ++i ) st[i][0] = a[i];
    for( int j = 0; j < 19; ++j ) {
       for( int i = 0; i < n; ++i )
           if( i + ( 1 << ( j + 1 ) ) <= n )
                st[i][j + 1] = min( st[i][j], st[i + ( 1 << j )][j] );
    }
    return ;
}

int query( int l, int r ) {
    int k = lg2[r - l + 1];
    return min( st[l][k], st[r - ( 1 << k ) + 1][k] );
}

int gao( int pos, int r, int num ) {
    bool flag = false;
    int low = pos, high = r + 1;
    while( low < high ) {
        int mid = ( low + high ) >> 1;
        if( query( pos, mid ) <= num ) { flag = true; high = mid; }
        else low = mid + 1;
    }
    return flag ? high : -1;
}

int main() {
    int t;
    lg2[0] = -1;
    for( int i = 1; i < MAXN; ++i ) lg2[i] = ( ( i & ( i - 1 ) ) == 0 ) ? lg2[i - 1] + 1 : lg2[i - 1];
    scanf( "%d", &t );
    while( t-- ) {
        memset( st, 0, sizeof( st ) );
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        init();
        scanf( "%d", &m );
        for( int i = 0, l, r; i < m; ++i ) {
            scanf( "%d%d", &l, &r ); --l; --r;
            int num = a[l], pos = l + 1;
            while( pos <= r ) {
                pos = gao( pos, r, num );
                if( pos == -1 ) break;
                num %= a[pos++];
            }
            printf( "%d\n", num );
        }
    }
    return 0;
}
