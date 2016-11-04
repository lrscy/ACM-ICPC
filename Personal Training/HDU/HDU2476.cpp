#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

char sa[MAXN], sb[MAXN];
int dp[MAXN][MAXN], ans[MAXN];
int len;

int main() {
    while( ~scanf( "%s%s", sa, sb ) ) {
        len = strlen( sa );
        memset( dp, 0, sizeof( dp ) );
        for( int i = 0; i < len; ++i ) {
            for( int j = i; j >= 0; --j ) {
                dp[j][i] = dp[j + 1][i] + 1;
                for( int k = j + 1; k <= i; ++k ) {
                    if( sb[k] == sb[j] )
                        dp[j][i] = min( dp[j][i], dp[j + 1][k] + ( k + 1 <= i ? dp[k + 1][i] : 0 ) );
                }
            }
        }
        for( int i = 0; i < len; ++i ) ans[i + 1] = dp[0][i];
        for( int i = 0; i < len; ++i ) {
            if( sa[i] == sb[i] ) ans[i + 1] = ans[i];
            else {
                for( int j = 0; j < i; ++j )
                    ans[i + 1] = min( ans[i + 1], ans[j + 1] + dp[j + 1][i] );
            }
        }
        printf( "%d\n", ans[len] );
    }
    return 0;
}
