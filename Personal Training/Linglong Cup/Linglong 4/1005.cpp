#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

map<int, int> mp;
int dp[MAXN], a[MAXN];
int n, ans;

int main() {
    int t;
    scanf( "%d", &t );
    for( int i = 1, j = 0; i <= MOD; i <<= 1, ++j ) mp[i] = j;
    while( t-- ) {
        memset( dp, 0, sizeof dp ); ans = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        for( int i = 0; i < n; ++i ) {
            if( mp.count( a[i] ) ) {
                if( a[i] == 1 ) { ++dp[0]; ++ans; }
                else {
                    int tmp = dp[mp[a[i] >> 1]], tn = mp[a[i]];
                    ans += tmp;
                    dp[tn] += tmp;
                    if( dp[tn] >= MOD ) dp[tn] -= MOD;
                }
                if( ans >= MOD ) ans -= MOD;
            }
        }
        printf( "%d\n", ans );
    }
    return 0;
}
