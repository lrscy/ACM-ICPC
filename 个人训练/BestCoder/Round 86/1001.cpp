#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

int a[MAXN];
int n, m;
LL q;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        LL sum = 0;
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i ), sum += a[i];
        while( m-- ) {
            scanf( "%I64d", &q );
            if( q > sum ) { putchar( '1' ); continue; }
            else putchar( '0' );
        }
        puts( "" );
    }
    return 0;
}
