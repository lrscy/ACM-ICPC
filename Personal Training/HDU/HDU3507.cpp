#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5e5 + 10;

LL sum[MAXN], que[MAXN], dp[MAXN];
int a[MAXN];
int n, m;

LL getval( int x, int y ) { return dp[y] + m + ( sum[x] - sum[y] ) * ( sum[x] - sum[y] ); }
LL getup( int x, int y ) { return ( dp[x] + sum[x] * sum[x] ) - ( dp[y] + sum[y] * sum[y] ); }
LL getdown( int x, int y ) { return 2 * ( sum[x] - sum[y] ); }

int main() {
    int mf, me;
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( sum, 0, sizeof sum );
        mf = me = 0;
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i ), sum[i] = sum[i - 1] + a[i];
        que[me++] = 0;
        for( int i = 1; i <= n; ++i ) {
            while( mf + 1 < me && getup( que[mf + 1], que[mf] ) <= sum[i] * getdown( que[mf + 1], que[mf] ) ) ++mf;
            dp[i] = getval( i, que[mf] );
            while( mf + 1 < me && getup( i, que[me - 1] ) * getdown( que[me - 1], que[me - 2] ) <= getup( que[me - 1], que[me - 2] ) * getdown( i, que[me - 1] ) ) --me;
            que[me++] = i;
        }
        printf( "%lld\n", dp[n] );
    }
    return 0;
}
