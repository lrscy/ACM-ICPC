#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MASK = 0x2AA;

LL dp[20][60000];
int num[20];

bool check( int mask ) {
    for( int i = 0; i < 10; ++i, mask /= 3 ) {
        int tmp = mask % 3;
        if( tmp == 0 ) continue;
        if( tmp == 1 && ( i & 1 ) ) return false;
        if( tmp == 2 && !( i & 1 ) ) return false;
    }
    return true;
}

int newmask( int mask, int x ) {
    int cnt[10] = { 0 };
    for( int i = 0; i < 10; ++i, mask /= 3 ) cnt[i] = mask % 3;
    if( cnt[x] == 0 ) cnt[x] = 1;
    else cnt[x] = 3 - cnt[x];
    for( int i = 9; i >= 0; --i ) mask = mask * 3 + cnt[i];
    return mask;
}

LL dfs( int pos, int mask, bool zero, bool edge ) {
    if( pos == -1 ) return check( mask );
    if( !edge && ~dp[pos][mask] ) return dp[pos][mask];
    LL ret = 0;
    int ed = edge ? num[pos] : 9;
    for( int i = 0; i <= ed; ++i ) {
        ret += dfs( pos - 1, zero && ( ( i == 0 ) && zero ) ? 0 : newmask( mask, i ), ( i == 0 ) && zero, edge && ( i == ed ) );
    }
    if( !edge ) dp[pos][mask] = ret;
    return ret;
}

LL gao( LL x ) {
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
    while( t-- ) {
        memset( dp, -1, sizeof( dp ) );
        scanf( "%lld%lld", &a, &b );
        printf( "%lld\n", gao( b ) - gao( a - 1 ) );
    }
    return 0;
}
