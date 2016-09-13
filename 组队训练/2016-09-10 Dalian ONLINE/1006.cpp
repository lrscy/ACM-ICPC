#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

int a[MAXN];
int n, m;

int main() {
    while( ~scanf( "%d", &m ) ) {
        while( m-- ) {
            scanf( "%d", &n );
            for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
            sort( a + 1, a + n + 1 );
            LL sum = 0;
            bool flag = true;
            for( int i = 1; i < n; ++i ) {
                sum += a[i];
                if( sum < 1LL * i * ( i - 1 ) ) { flag = false; break; }
            }
            sum += a[n];
            if( sum != 1LL * n * ( n - 1 )  ) flag = false;
            if( flag ) puts( "T" );
            else puts( "F" );
        }
    }
    return 0;
}
