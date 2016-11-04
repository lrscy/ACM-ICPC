#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char str[5][5];
int cnt[5][5];
int ans;

int main() {
    memset( cnt, 0, sizeof( cnt ) );
    ans = 0;
    for( int i = 0; i < 4; ++i ) {
        scanf( "%s", str + i );
        for( int j = 0; j < 4; ++j ) {
            if( str[i][j] == '+' ) {
                ++cnt[i][j];
                for( int k = 0; k < 4; ++k ) {
                    ++cnt[k][j]; ++cnt[i][k];
                }
            }
        }
    }
    for( int i = 0; i < 4; ++i ) {
        for( int j = 0; j < 4; ++j ) {
            if( cnt[i][j] & 1 ) ++ans;
        }
    }
    printf( "%d\n", ans );
    for( int i = 0; i < 4; ++i ) {
        for( int j = 0; j < 4; ++j ) {
            if( cnt[i][j] & 1 ) printf( "%d %d\n", i + 1, j + 1 );
        }
    }
    return 0;
}
