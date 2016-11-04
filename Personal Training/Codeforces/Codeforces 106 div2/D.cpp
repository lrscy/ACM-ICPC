#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 10;

char s[MAXN];
int dp[MAXN][MAXN][3][3], match[MAXN], st[MAXN];
int n, len;

void gao() {
    int top = 0;
    for( int i = 0; i < len; ++i ) {
        if( s[i] == '(' ) st[top++] = i;
        else {
            match[i] = st[--top];
            match[st[top]] = i;
        }
    }
    return ;
}

void dfs( int left, int right ) {
    if( left + 1 == right ) {
        dp[left][right][0][1] = 1;
        dp[left][right][1][0] = 1;
        dp[left][right][0][2] = 1;
        dp[left][right][2][0] = 1;
    } else if( match[left] == right ) {
        dfs( left + 1, right - 1 );
        for( int i = 0; i < 3; ++i ) {
            for( int j = 0; j < 3; ++j ) {
                if( i != 1 ) dp[left][right][1][0] = ( 1LL * dp[left][right][1][0] + dp[left + 1][right - 1][i][j] ) % MOD;
                if( j != 1 ) dp[left][right][0][1] = ( 1LL * dp[left][right][0][1] + dp[left + 1][right - 1][i][j] ) % MOD;
                if( i != 2 ) dp[left][right][2][0] = ( 1LL * dp[left][right][2][0] + dp[left + 1][right - 1][i][j] ) % MOD;
                if( j != 2 ) dp[left][right][0][2] = ( 1LL * dp[left][right][0][2] + dp[left + 1][right - 1][i][j] ) % MOD;
            }
        }
    } else {
        int mid = match[left];
        dfs( left, mid ); dfs( mid + 1, right );
        for( int i = 0; i < 3; ++i ) {
            for( int j = 0; j < 3; ++j )
                for( int  x = 0; x < 3; ++x )
                    for( int y = 0; y < 3; ++y )
                        if( !( ( x == 1 && y == 1 ) || ( x == 2 && y == 2 ) ) )
                            dp[left][right][i][j] = ( dp[left][right][i][j] + 1LL * dp[left][mid][i][x] * dp[mid + 1][right][y][j] ) % MOD;
       }
    }
    return ;
}

int main() {
    int ans = 0;
    memset( dp, 0, sizeof( dp ) );
    scanf( "%s", s );
    len = strlen( s );
    gao();
    dfs( 0, len - 1 );
    for( int i = 0; i < 3; ++i ) {
        for( int j = 0; j < 3; ++j )
            ans = ( ans + dp[0][len - 1][i][j] ) % MOD;
    }
    printf( "%d\n", ans );
    return 0;
}
