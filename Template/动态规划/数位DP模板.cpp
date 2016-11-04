#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 2520;

LL dp[21][MOD + 10][50];
int index[MOD + 10], dig[21];

void init() {
    int cnt = 0;
    for( int i = 1; i <= MOD; ++i ) if( MOD % i == 0 ) index[i] = cnt++;
    memset( dp, -1, sizeof( dp ) );
    return ;
}

int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a % b ); }
int lcm( int a, int b ) { return a / gcd( a, b ) * b; }

LL dfs( int pos, int presum, int prelcm, bool edge ) {
    if( pos == -1 ) return presum % prelcm == 0;
    if( !edge && dp[pos][presum][index[prelcm]] != -1 ) {
        return dp[pos][presum][index[prelcm]];
    }
    LL ret = 0;
    int ed = edge ? dig[pos] : 9;
    for( int i = 0; i <= ed; ++i ) {
        int nowsum = ( presum * 10 + i ) % MOD;
        int nowlcm = prelcm;
        if( i ) nowlcm = lcm( prelcm, i );
        ret += dfs( pos - 1, nowsum, nowlcm, edge && ( i == ed ) );
    }
    if( !edge ) dp[pos][presum][index[prelcm]] = ret;
    return ret;
}

LL gao( LL x ) {
    int pos = 0;
    while( x ) {
        dig[pos++] = x % 10;
        x /= 10;
    }
    return dfs( pos - 1, 0, 1, true );
}

int main() {
    int t;
    init();
    scanf( "%d", &t );
    while( t-- ) {
        LL l, r;
        scanf( "%I64d %I64d", &l, &r );
        printf( "%I64d\n", gao( r ) - gao( l - 1 ) );
    }
    return 0;
}
