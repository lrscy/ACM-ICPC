#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5;

char s[MAXN][MAXN];
int mask[15], a[MAXN][MAXN];    // 0-3 row 4-7 col 8-11 square

bool dfs( int pos ) {
    if( pos == 16 ) {
        for( int i = 0; i < 12; ++i ) if( mask[i] != 30 ) return false;
        return true;
    }
    int x = pos / 4, y = pos % 4, sp = pos / 2;
    if( sp == 0 || sp == 2 ) sp = 8;
    if( sp == 1 || sp == 3 ) sp = 9;
    if( sp == 4 || sp == 6 ) sp = 10;
    if( sp == 5 || sp == 7 ) sp = 11;
    for( int i = 1; i <= 4; ++i ) {
        a[x][y] = i;
        if( !( mask[x] & ( 1 << i ) ) && !( mask[y + 4] & ( 1 << i ) ) && !( mask[sp] & ( 1 << i ) ) ) {
            mask[x] ^= ( 1 << i );
            mask[y + 4] ^= ( 1 << i );
            mask[sp] ^= ( 1 << i );
            for( int j = pos + 1; j <= 16; ++j ) {
                int tx = j / 4, ty = j % 4;
                if( a[tx][ty] == 0 && dfs( j ) )
                    return true;
            }
            mask[x] ^= ( 1 << i );
            mask[y + 4] ^= ( 1 << i );
            mask[sp] ^= ( 1 << i );
        }
        a[x][y] = 0;
    }
    return false;
}

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d:\n", ncas );
        memset( mask, 0, sizeof( mask ) );
        for( int i = 0; i < 4; ++i ) {
            scanf( "%s", s[i] );
            for( int j = 0; j < 4; ++j ) {
                if( s[i][j] == '*' ) a[i][j] = 0;
                else a[i][j] = s[i][j] - '0';
            }
        }
        for( int i = 0; i < 4; ++i ) {
            for( int j = 0; j < 4; ++j )
                mask[i] |= ( 1 << a[i][j] );
        }
        for( int j = 0; j < 4; ++j ) {
            for( int i = 0; i < 4; ++i ) {
                mask[j + 4] |= ( 1 << a[i][j] );
            }
        }
        for( int i = 0; i < 2; ++i ) {
            for( int j = 0; j < 2; ++j ) {
                mask[8] |= ( 1 << a[i][j] );
                mask[9] |= ( 1 << a[i][j + 2] );
                mask[10] |= ( 1 << a[i + 2][j] );
                mask[11] |= ( 1 << a[i + 2][j + 2] );
            }
        }
        for( int i = 0; i < 12; ++i ) if( mask[i] & 1 ) mask[i] ^= 1;
        bool flag = false;
        for( int i = 0; i < 4 && !flag; ++i ) {
            for( int j = 0; j < 4 && !flag; ++j ) {
                if( a[i][j] == 0 ) {
                    dfs( i * 4 + j );
                    flag = true;
                }
            }
        }
        for( int i = 0; i < 4; ++i ) {
            for( int j = 0; j < 4; ++j )
                s[i][j] = a[i][j] + '0';
        }
        for( int i = 0; i < 4; ++i ) puts( s[i] );
    }
    return 0;
}
