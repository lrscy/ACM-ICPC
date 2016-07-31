#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 2e5 + 10;

char s[MAXN];
int a[MAXN];
int n;

int main() {
    int nmin = INF;
    scanf( "%d", &n );
    scanf( "%s", s );
    for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
    for( int i = 1; i < n; ++i ) {
        if( s[i - 1] == 'R' && s[i] == 'L' ) {
            nmin = min( nmin, ( a[i] - a[i - 1] ) / 2 );
        }
    }
    if( nmin == INF ) puts( "-1" );
    else printf( "%d\n", nmin );
    return 0;
}
