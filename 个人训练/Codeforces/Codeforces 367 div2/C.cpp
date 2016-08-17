#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3F3F3F3F3F3F3F3F;
const int MAXN = 1e5 + 10;

string s[MAXN], sr[MAXN];
LL dp[MAXN][2];
int a[MAXN];
int n;

LL mmin( LL a, LL b ) {
    return a < b ? a : b;
}

int main() {
    char st[MAXN];
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) scanf( "%d", a + i );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%s", st );
        s[i] = st;
        sr[i].assign( s[i].rbegin(), s[i].rend() );
    }
    s[0] = "";
    memset( dp, 0x3F, sizeof( dp ) );
    dp[0][0] = dp[0][1] = 0;
    bool flag = true;
    for( int i = 1; i <= n; ++i ) {
        if( ~dp[i - 1][0] && s[i] >= s[i - 1] ) dp[i][0] = min( dp[i][0], dp[i - 1][0] );
        if( ~dp[i - 1][1] && s[i] >= sr[i - 1] ) dp[i][0] = min( dp[i][0], dp[i - 1][1] );
        if( dp[i][0] == INF ) dp[i][0] = -1;
        if( ~dp[i - 1][0] && sr[i] >= s[i - 1] ) dp[i][1] = min( dp[i][1], dp[i - 1][0] + a[i] );
        if( ~dp[i - 1][1] && sr[i] >= sr[i - 1] ) dp[i][1] = min( dp[i][1], dp[i - 1][1] + a[i] );
        if( dp[i][1] == INF ) dp[i][1] = -1;
        if( dp[i][0] == -1 && dp[i][1] == -1 ) { flag = false; break; }
    }
    if( dp[n][0] == -1 ) dp[n][0] = INF;
    if( dp[n][1] == -1 ) dp[n][1] = INF;
    if( flag ) printf( "%I64d\n", mmin( dp[n][0], dp[n][1] ) );
    else puts( "-1" );
    return 0;
}
