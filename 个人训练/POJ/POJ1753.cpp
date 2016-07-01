#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int INF = 0x3F3F3F3F;

char str[5][5];
int d[5] = { -4, -1, 1, 4 };
int src, des, ans;

void flip( int p ) {
    if( ( 1 << p ) & des ) des &= ( 1 << 16 ) - 1 - ( 1 << p );
    else des |= ( 1 << p );
    return ;
}

int main() {
    src = des = 0;
    for( int i = 0; i < 4; ++i ) {
        scanf( "%s", str + i );
        for( int j = 0; j < 4; ++j ) {
            int tmp = i * 4 + j;
            if( str[i][j] == 'b' ) src |= ( 1 << ( 16 - tmp - 1 ) );
        }
    }
    ans = INF;
    for( int s = 0; s < ( 1 << 16 ); ++s ) {
        int cnt = 0;
        des = src;
        for( int i = 0; i < 16; ++i ) {
            if( ( 1 << i ) & s ) {
                ++cnt;
                flip( i );
                for( int j = 0; j < 4; ++j ) {
                    int num = i + d[j];
                    if( num < 0 || num > 15 ) continue;
                    if( abs( d[j] ) == 1 &&
                            ( num < ( i / 4 * 4 ) ||
                              num > ( i / 4 * 4 ) + 3 ) ) continue;
                    flip( i + d[j] );
                }
            }
        }
        if( des == 0 || des == ( 1 << 16 ) - 1 ) {
            ans = min( ans, cnt );
        }
    }
    if( ans == INF ) puts( "Impossible" );
    else printf( "%d\n", ans );
    return 0;
}
