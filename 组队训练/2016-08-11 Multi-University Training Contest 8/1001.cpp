#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int a[MAXN], b[MAXN], c[MAXN];
bool vis[MAXN];
int n, m;

int main() {
    int t, ta, tb;
    scanf( "%d", &t );
    while( t-- ) {
        memset( vis, false, sizeof( vis ) );
        memset( c, 0, sizeof( c ) );
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
        for( int i = 1; i <= n; ++i ) scanf( "%d", b + i );
        for( int i = 1; i <= n; ++i ) {
            for( int j = 1; j <= n; ++j ) {
                if( !vis[j] && a[i] == b[j] ) {
                    c[i] = j;
                    vis[j] = true;
                    break;
                }
            }
        }
        bool flag = true;
        for( int i = 1; i <= n; ++i ) if( c[i] == 0 ) { flag = false; break; }
        while( m-- ) {
            scanf( "%d%d", &ta, &tb );
            if( flag ) sort( c + ta, c + tb + 1 );
        }
        if( flag ) {
            flag = true;
            for( int i = 1; i <= n; ++i ) {
                if( c[i] != i ) {
                    flag = false;
                    break;
                }
            }
        }
        puts( flag ? "Yes" : "No" );
    }
    return 0;
}
