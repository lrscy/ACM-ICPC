#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

char s[MAXN];
int n, m;

int main() {
    int p1, p2, p3, flag = 0;
    scanf( "%d%d%s", &n, &m, s );
    for( int i = 0; i < n; ++i ) if( s[i] == '.' ) { p1 = i; break; }
    for( int i = p1; i < n; ++i ) s[i] = s[i + 1]; --n;
    p2 = -1; p3 = n;
    for( int i = p1; i < p3; ++i ) if( s[i] >= '5' ) { p2 = i; break; }
    while( m-- ) {
        if( p2 == -1 ) break;
        p3 = p2; flag = 1; p2 = -1;
        for( int i = p3 - 1; i >= 0; --i ) {
            s[i] += flag;
            if( s[i] >= '5' && i >= p1 ) p2 = i;
            if( s[i] > '9' ) s[i] = '0';
            else { flag = 0; break; }
        }
    }
    s[p3 + 1] = 0;
    for( int i = p3; i > p1; --i ) s[i] = s[i - 1];
    if( p1 != p3 ) s[p1] = '.';
    else s[p3] = 0;
    if( flag ) printf( "1%s\n", s );
    else printf( "%s\n", s );
    return 0;
}
