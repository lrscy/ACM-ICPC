#include <bits/stdc++.h>
using namespace std;

int dp[10][2], num[10];

int dfs( int pos, int s, bool edge ) {
    if( pos == -1 ) return 1;
    if( !edge && ~dp[pos][s] ) return dp[pos][s];
    int ret = 0;
    int ed = edge ? num[pos] : 9;
    for( int i = 0; i <= ed; ++i ) {
        if( i == 4 || ( s && ( i == 2 ) ) ) continue;
        ret += dfs( pos - 1, i == 6, edge && ( i == ed ) );
    }
    if( !edge ) dp[pos][s] = ret;
    return ret;
}

int cal( int x ) {
    int len = 0;
    while( x ) {
        num[len++] = x % 10;
        x /= 10;
    }
    return dfs( len - 1, 0, true );
}

int main() {
    int n, m;
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        memset( dp, -1, sizeof( dp ) );
        printf( "%d\n", cal( m ) - cal( n - 1 ) );
    }
    return 0;
}
