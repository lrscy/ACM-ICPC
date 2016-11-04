#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MASK = 0x2AA;

LL dp[20][20][5]; // oe 0: even 1: odd
int num[20];

LL dfs( int pos, int c, int oe, bool zero, bool edge ) {
    if( pos == -1 ) return oe ? !( c & 1 ) : ( c & 1 );
    if( !edge && ~dp[pos][c][oe] ) return dp[pos][c][oe];
    LL ret = 0;
    int ed = edge ? num[pos] : 9;
    for( int i = 0; i <= ed; ++i ) {
        if( i & 1 ) { // cur odd
            if( oe ) { // pre odd
                ret += dfs( pos - 1, c + 1, 1, ( i == 0 ) && zero, edge && ( i == ed ) );
            } else if( zero || ( c & 1 ) ) { // pre even
                ret += dfs( pos - 1, 1, 1, ( i == 0 ) && zero, edge && ( i == ed ) );
            }
        } else { // cur even
            if( !oe ) { // pre even
                ret += dfs( pos - 1, ( zero && i == 0 ) ? 0 : c + 1, 0, ( i == 0 ) && zero, edge && ( i == ed ) );
            } else if( !( c & 1 ) ) { // pre odd
                ret += dfs( pos - 1, 1, 0, ( i == 0 ) && zero, edge && ( i == ed ) );
            }
        }
    }
    if( !edge ) dp[pos][c][oe] = ret;
    return ret;
}

LL gao( LL x ) {
    int pos = 0;
    while( x ) {
        num[pos++] = x % 10;
        x /= 10;
    }
    return dfs( pos - 1, 0, 0, true, true );
}

int main() {
    LL a, b;
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( dp, -1, sizeof( dp ) );
        scanf( "%lld%lld", &a, &b );
        printf( "%lld\n", gao( b ) - gao( a - 1 ) );
    }
    return 0;
}
