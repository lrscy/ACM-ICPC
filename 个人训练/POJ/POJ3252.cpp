#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;

int dp[40][40][40];
int num[40];

int dfs( int pos, int cnt0, int cnt1, bool zero, bool edge ) {
    if( pos == -1 ) return cnt0 && cnt0 >= cnt1;
    if( !edge && ~dp[pos][cnt0][cnt1] ) return dp[pos][cnt0][cnt1];
    int ret = 0;
    int ed = edge ? num[pos] : 1;
    for( int i = 0; i <= ed; ++i ) {
        if( zero ) {
            if( i ) ret += dfs( pos - 1, cnt0, cnt1 + 1, false, edge && ( i == ed ) );
            else ret += dfs( pos - 1, 0, 0, true, edge && ( i == ed ) );
        } else {
            if( i ) ret += dfs( pos - 1, cnt0, cnt1 + 1, false, edge && ( i == ed ) );
            else ret += dfs( pos - 1, cnt0 + 1, cnt1, false, edge && ( i == ed ) );
        }
    }
    if( !edge ) dp[pos][cnt0][cnt1] = ret;
    return ret;
}

int gao( int x ) {
    int pos = 0;
    while( x ) {
        num[pos++] = x & 1;
        x >>= 1;
    }
    return dfs( pos - 1, 0, 0, true, true );
}

int main() {
    int a, b;
    memset( dp, -1, sizeof( dp ) );
    scanf( "%d%d", &a, &b );
    printf( "%d\n", gao( b ) - gao( a - 1 ) );
    return 0;
}
