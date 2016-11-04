#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 30;
const int INF = 0x3F3F3F3F;

int a[MAXN];
int n;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        int nmin = INF, cnt = 0;
        for( int i = 0; i < 26; ++i ) {
            scanf( "%d", a + i );
            if( a[i] ) {
                nmin = min( nmin, a[i] );
                ++cnt;
            }
        }
        if( cnt = 1 ) {
            printf( "%d\n", ( 2 + nmin ) * ( nmin - 1 ) / 2 );
        } else printf( "%d\n", nmin - 1 );
    }
    return 0;
}
