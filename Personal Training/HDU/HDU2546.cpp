#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 10;

int a[MAXN], dp[MAXN];
int n, m;

int main() {
    while( ~scanf( "%d", &n ) && n ) {
        memset( dp, 0x80, sizeof( dp ) ); dp[0] = 0;
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        scanf( "%d", &m );
        if( m < 5 ) { printf( "%d\n", m ); continue; }
        sort( a, a + n );
        for( int i = 0; i < n - 1; ++i ) {
            for( int j = m - 5; j >= a[i]; --j )
                dp[j] = max( dp[j], dp[j - a[i]] + 1 );
        }
        int tmp = 0;
        for( int i = m - 5; i > 0; --i ) {
            if( dp[i] >= 0 ) {
                tmp = i;
                break;
            }
        }
        printf( "%d\n", m - tmp - a[n - 1] );
    }
    return 0;
}
