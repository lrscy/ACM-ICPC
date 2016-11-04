#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

char s[MAXN][MAXN];
int x[MAXN], y[MAXN];
int n, m;

int main() {
    int cnt = 0;
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i ) scanf( "%s", s[i] + 1 );
    for( int i = 1; i <= n; ++i ) {
        for( int j = 1; j <= m; ++j ) {
            if( s[i][j] == '*' ) {
                ++x[i];
                ++y[j];
                ++cnt;
            }
        }
    }
    bool flag = false;
    for( int i = 1; i <= n; ++i ) {
        for( int j = 1; j <= m; ++j ) {
            if( x[i] + y[j] + ( s[i][j] == '*' ? -1 : 0 ) == cnt ) {
                flag = true;
                puts( "YES" );
                printf( "%d %d\n", i, j );
                return 0;
            }
        }
    }
    puts( "NO" );
    return 0;
}
