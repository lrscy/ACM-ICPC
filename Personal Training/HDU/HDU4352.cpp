#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[20][1 << 10][11];
int num[20];
int k;

int getmask( int mask, int x ) {
    for( int i = x; i < 10; ++i ) {
        if( ( 1 << i ) & mask ) return ( mask ^ ( 1 << i ) ) | ( 1 << x );
    }
    return mask | ( 1 << x );
}

LL dfs( int pos, int mask, bool zero, bool edge ) {
    if( pos == -1 ) return __builtin_popcount( mask ) == k;
    if( !edge && ~dp[pos][mask][k] ) return dp[pos][mask][k];
    LL ret = 0;
    int ed = edge ? num[pos] : 9;
    for( int i = 0; i <= ed; ++i ) {
        ret += dfs( pos - 1, ( zero && ( i == 0 ) ) ? 0 : getmask( mask, i ), zero && ( i == 0 ), edge && ( i == ed ) );
    }
    if( !edge ) dp[pos][mask][k] = ret;
    return ret;
}

LL cal( LL x ) {
    int pos = 0;
    while( x ) {
        num[pos++] = x % 10;
        x /= 10;
    }
    return dfs( pos - 1, 0, true, true );
}

int main() {
    LL a, b;
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( dp, -1, sizeof( dp ) );
        scanf( "%I64d%I64d%d", &a, &b, &k );
        printf( "%I64d\n", cal( b ) - cal( a - 1 ) );
    }
    return 0;
}
