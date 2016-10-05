#include <bits/stdc++.h>
using namespace std;

int xx0, yy0, zz0;
int xx1, yy1, zz1;
int xx2, yy2, zz2;

bool inx( int x ) { return ( xx1 <= x && x <= xx2 ); }
bool iny( int y ) { return ( yy1 <= y && y <= yy2 ); }
bool inz( int z ) { return ( zz1 <= z && z <= zz2 ); }
int  sq ( int n ) { return n * n; }
int  dis( int a1, int b1, int a2, int b2 ) { return sq( a1 - a2 ) + sq( b1 - b2 ); }
int  dis3( int a1, int b1, int c1, int a2, int b2, int c2 ) { return sq( a1 - a2 ) + sq( b1 - b2 ) + sq( c1 - c2 ); }

int main() {
    scanf( "%d%d%d", &xx0, &yy0, &zz0 );
    scanf( "%d%d%d", &xx1, &yy1, &zz1 );
    scanf( "%d%d%d", &xx2, &yy2, &zz2 );
    if( inx( xx0 ) && iny( yy0 ) && inz( zz0 ) ) { puts( "0" ); return 0; }
    if( inx( xx0 ) && iny( yy0 ) && !inz( zz0 ) ) { printf( "%d\n", min( sq( zz0 - zz1 ), sq( zz0 - zz2 ) ) ); return 0; }
    if( inx( xx0 ) && !iny( yy0 ) && inz( zz0 ) ) { printf( "%d\n", min( sq( yy0 - yy1 ), sq( yy0 - yy2 ) ) ); return 0; }
    if( !inx( xx0 ) && iny( yy0 ) && inz( zz0 ) ) { printf( "%d\n", min( sq( xx0 - xx1 ), sq( xx0 - xx2 ) ) ); return 0; }
    if( !inx( xx0 ) && !iny( yy0 ) && inz( zz0 ) ) {
        printf( "%d\n", min( min( dis( xx0, yy0, xx1, yy1 ), dis( xx0, yy0, xx1, yy2 ) ), min( dis( xx0, yy0, xx2, yy1 ), dis( xx0, yy0, xx2, yy2 ) ) ) );
        return 0;
    }
    if( !inx( xx0 ) && iny( yy0 ) && !inz( zz0 ) ) {
        printf( "%d\n", min( min( dis( xx0, zz0, xx1, zz1 ), dis( xx0, zz0, xx1, zz2 ) ), min( dis( xx0, zz0, xx2, zz1 ), dis( xx0, zz0, xx2, zz2 ) ) ) );
        return 0;
    }
    if( inx( xx0 ) && !iny( yy0 ) && !inz( zz0 ) ) {
        printf( "%d\n", min( min( dis( zz0, yy0, zz1, yy1 ), dis( zz0, yy0, zz1, yy2 ) ), min( dis( zz0, yy0, zz2, yy1 ), dis( zz0, yy0, zz2, yy2 ) ) ) );
        return 0;
    }
    int t1, t2, t3, t4;
    t1 = min( dis3( xx0, yy0, zz0, xx1, yy1, zz1 ), dis3( xx0, yy0, zz0, xx1, yy1, zz2 ) );
    t2 = min( dis3( xx0, yy0, zz0, xx1, yy2, zz1 ), dis3( xx0, yy0, zz0, xx1, yy2, zz2 ) );
    t3 = min( dis3( xx0, yy0, zz0, xx2, yy1, zz1 ), dis3( xx0, yy0, zz0, xx2, yy1, zz2 ) );
    t4 = min( dis3( xx0, yy0, zz0, xx2, yy2, zz1 ), dis3( xx0, yy0, zz0, xx2, yy2, zz2 ) );
    printf( "%d\n", min( min( t1, t2 ), min( t3, t4 ) ) );
    return 0;
}
