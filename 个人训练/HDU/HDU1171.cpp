#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

int a[MAXN], num[MAXN], dp[MAXN];
int n;

void gao( int c, int w, int sum ) {
    for( int j = sum; j >= c; --j )
        dp[j] = max( dp[j], dp[j - c] + w );
    return ;
}

int main() {
    int x, y;
    while( ~scanf( "%d", &n ) && n >= 0 ) {
        memset( dp, 0, sizeof( dp ) );
        int sum = 0;
        for( int i = 0; i < n; ++i ) {
            scanf( "%d%d", a + i, num + i );
            sum += a[i] * num[i];
        }
        int tmp = sum;
        sum >>= 1;
        for( int i = 0; i < n; ++i ) {
            int s = 1;
            while( num[i] >= s ) {
                gao( a[i] * s, a[i] * s, sum );
                num[i] -= s;
                s <<= 1;
            }
            if( a[i] ) gao( a[i] * s, a[i] * s, sum );
        }
        printf( "%d %d\n", tmp - dp[sum], dp[sum] );
    }
    return 0;
}
