#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100 + 10;

char s[MAXN];
int dp[MAXN][MAXN];

bool check( int i, int j ) {
    if( s[i] == '(' && s[j] == ')' ) return true;
    if( s[i] == '[' && s[j] == ']' ) return true;
    return false;
}

int main() {
    int len;
    while( ~scanf( "%s", s + 1 ) && strcmp( s + 1, "end" ) ) {
        memset( dp, 0, sizeof( dp ) );
        len = strlen( s + 1 );
        for( int m = 1; m <= len; ++m ) {
            for( int i = 1; i + m <= len; ++i ) {
                int j = i + m;
                dp[i][j] = dp[i][j - 1];
                for( int k = i; k < j; ++k ) {
                    if( check( k, j ) )
                        dp[i][j] = max( dp[i][j], dp[i][k - 1] + dp[k + 1][j - 1] + 2 );
                }
            }
        }
        printf( "%d\n", dp[1][len] );
    }
    return 0;
}
