#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;

int w[MAXN], num[10];
bool dp[MAXN];

int main() {
    int t = 0;
    while( true ) {
        int sum = 0;
        for( int i = 0; i < 6; ++i ) {
            scanf( "%d", num + i );
            sum += num[i] * ( i + 1 );
        }
        if( sum == 0 ) break;
        printf( "Collection #%d:\n", ++t );
        if( sum & 1 ) { puts( "Can't be divided.\n" ); continue; }
        sum /= 2;
        memset( dp, false, sizeof( dp ) );
        dp[0] = true;
        int s;
        for( int i = 0; i < 6; ++i ) {
            for( s = 0; ( 1 << s ) <= num[i]; ++s ) {
                w[s] = 1 << s;
                num[i] -= w[s];
            }
            if( num[i] ) w[s++] = num[i];
            for( int j = 0; j < s; ++j ) {
                int tmp = ( i + 1 ) * w[j];
                for( int k = sum; k >= tmp; --k ) 
                    dp[k] |= dp[k - tmp];
            }
        }
        if( dp[sum] ) puts( "Can be divided." );
        else puts( "Can't be divided." );
        puts( "" );
    }
    return 0;
}
