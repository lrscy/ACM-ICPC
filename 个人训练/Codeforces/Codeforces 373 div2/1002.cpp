#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

char s[MAXN];
int n;

int main() {
    int a1, a2;
    int c1, c2;
    c1 = c2 = 0;
    scanf( "%d%s", &n, s );
    for( int i = 0; i < n; ++i ) {
        if( s[i] == 'r' ) ++c1;
        if( s[i] == 'b' ) ++c2;
    }
    int t1, t2;
    t1 = t2 = 0;
    for( int i = 0; i < n; ++i ) {
        if( ( i & 1 ) && s[i] != 'b' ) ++t1;
        if( !( i & 1 ) && s[i] != 'r' ) ++t2;
    }
    a1 = max( t1, t2 );
    t1 = t2 = 0;
    for( int i = 0; i < n; ++i ) {
        if( ( i & 1 ) && s[i] != 'r' ) ++t1;
        if( !( i & 1 ) && s[i] != 'b' ) ++t2;
    }
    a2 = max( t1, t2 );
    printf( "%d\n", min( a1, a2 ) );
    return 0;
}
