#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e7;

char s[MAXN];
int len;

LL mabs( LL a ) {
    return a < 0 ? -a : a;
}

int main() {
    int tt = 1;
    LL ta = 0, tb = 0;
    while( ~scanf( "%s", &s ) ) {
        printf( "Case #%d: ", tt++ );
        ta = tb = 0;
        len = strlen( s );
        int tmp = len % 4;
        bool flag = false;
        for( int i = len - 1; i >= tmp; i -= 4 ) {
            if( !flag ) ta += ( s[i] - '0' ) + ( s[i - 1] - '0' ) * 10 + ( s[i - 2] - '0' ) * 100 + ( s[i - 3] - '0' ) * 1000;
            else tb += ( s[i] - '0' ) + ( s[i - 1] - '0' ) * 10 + ( s[i - 2] - '0' ) * 100 + ( s[i - 3] - '0' ) * 1000;
            flag = !flag;
        }
        if( tmp >= 0 ) {
            int tt = 1;
            while( --tmp >= 0 ) {
                if( !flag ) ta += tt * ( s[tmp] - '0' );
                else tb += tt * ( s[tmp] - '0' );
                tt *= 10;
            }
        }
        if( mabs( ta - tb ) % 10001 == 0 ) puts( "YES" );
        else puts( "NO" );
    }
    return 0;
}
