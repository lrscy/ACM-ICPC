#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e3 + 10;

char g1[MAXN][MAXN], g2[MAXN][MAXN], st[20], bg[MAXN][MAXN];
char c;
int n, m;

bool chk( int x, int y ) {
    return ( 0 <= x && x < n && 0 <= y && y < m );
}

int main() {
    char line[20];
    int xx1, yy1, xx2, yy2;
    while( NULL != fgets( line, 20, stdin ) ) {
        memset( g1, 0, sizeof g1 );
        memset( g2, 0, sizeof g2 );
        memset( bg, 0, sizeof bg );
        if( !strcmp( "0 0 ' '\n", line ) ) break;
        sscanf( line, "%d%d%s", &n, &m, st ); c = st[1];
        for( int i = 0; i < n; ++i ) fgets( g1[i], MAXN, stdin ), g1[i][strlen( g1[i] ) - 1] = 0;
        fgets( line, 20, stdin );
        for( int i = 0; i < n; ++i ) fgets( g2[i], MAXN, stdin ), g2[i][strlen( g2[i] ) - 1] = 0;
        fgets( line, 20, stdin );
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                if( g1[i][j] != c ) bg[i][j] = g1[i][j];
                else xx1 = i, yy1 = j;
            }
        }
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                if( g2[i][j] != c ) bg[i][j] = g2[i][j];
                else xx2 = i, yy2 = j;
            }
        }
        int dx = xx2 - xx1, dy = yy2 - yy1;
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                if( g2[i][j] == c ) {
                    int tx = i + dx, ty = j + dy;
                    if( !chk( tx, ty ) ) continue;
                    bg[tx][ty] = c;
                }
            }
        }
        for( int i = 0; i < n; ++i ) printf( "%s\n", bg[i] );
        puts( "" );
    }
    return 0;
}
