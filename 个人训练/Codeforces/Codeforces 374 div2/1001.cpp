#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;

char s[MAXN];
int a[MAXN];
int n, tot, cnt;

int main() {
    tot = cnt = 0;
    scanf( "%d%s", &n, s );
    for( int i = 0; i < n; ++i ) {
        if( s[i] == 'B' ) {
            if( i && s[i - 1] == 'B' ) ++cnt;
            else cnt = 1;
        } else {
            if( cnt ) a[tot++] = cnt;
            cnt = 0;
        }
    }
    if( cnt ) a[tot++] = cnt;
    if( tot == 0 ) { puts( "0" ); return 0; }
    printf( "%d\n%d", tot, a[0] );
    for( int i = 1; i < tot; ++i ) printf( " %d", a[i] );
    puts( "" );
    return 0;
}
