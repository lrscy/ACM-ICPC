#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

bitset<MAXN> bs[MAXN], vis[MAXN];
char s[MAXN][MAXN];
int n, m, q;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( vis, false, sizeof vis );
        scanf( "%d%d%d", &n, &m, &q );
        for( int i = 0, a, b, c, d; i < q; ++i ) {
            scanf( "%d", &a );
            if( a == 1 ) {
                scanf( "%d%d%d", &b, &c, &d );
                --c; --d;
                bs[c][d] = b - 1;
                vis[c][d] = 1;
            } else {
                scanf( "%d%d", &b, &c );
                --b; --c;
                if( b != c ) { swap( bs[b], bs[c] ); swap( vis[b], vis[c] ); }
            }
        }
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                s[i][j] = '.';
                if( vis[i][j] ) {
                    if( bs[i][j] ) s[i][j] = 'b';
                    else s[i][j] = 'w';
                }
            }
            s[i][m] = 0;
        }
        for( int i = 0; i < n; ++i ) printf( "%s\n", s[i] );
    }
    return 0;
}
