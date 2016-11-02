#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int POW = 16;

char s[MAXN];
int lg2[MAXN], dp[MAXN][POW];
int n;

int nmin( int x, int y ) {
    return s[x] <= s[y] ? x : y;
}

void init( int tn ) {
    lg2[0] = -1; for( int i = 1; i < MAXN; ++i ) lg2[i] = ( ( i & ( i - 1 ) ) == 0 ) ? lg2[i - 1] + 1 : lg2[i - 1];
    for( int i = 1; i <= tn; ++i ) dp[i][0] = i;
    for( int j = 1; j <= 15; ++j ) {
        for( int i = 1; i + ( 1 << j ) - 1 <= tn; ++i ) {
            dp[i][j] = nmin( dp[i][j - 1], dp[i + ( 1 << ( j - 1 ) )][j - 1] );
        }
    }
}

int query( int x, int y ) {
    int k = lg2[y - x + 1];
    return nmin( dp[x][k], dp[y - ( 1 << k ) + 1][k] );
}

int main() {
    while( ~scanf( "%s%d", s + 1, &n ) ) {
        char ans[MAXN];
        int pos = 1, num = 0;
        int len = strlen( s + 1 );
        init( len );
        n = len - n;
        while( n ) {
            pos = query( pos, len - n + 1 );
            ans[num++] = s[pos]; ++pos;
            --n;
        }
        ans[num] = 0;
        pos = 0; while( pos < num && ans[pos] == '0' ) ++pos;
        if( pos == num ) puts( "0" );
        else printf( "%s\n", ans + pos );
    }
    return 0;
}
