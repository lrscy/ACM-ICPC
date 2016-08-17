#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL MOD = 1e9 + 7;

struct Mat {
    LL a[10][10];
    int n, m;
    Mat() {
        memset( a, 0, sizeof( a ) );
        n = m = 0;
    }
    Mat( int tn, int tm ) {
        memset( a, 0, sizeof( a ) );
        n = tn; m = tn;
    }
    Mat operator * ( const Mat &b ) {
        Mat c( n, b.m );
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < b.m; ++j )
                for( int k = 0; k < m; ++k )
                    c.a[i][j] = ( c.a[i][j] + ( a[i][k] % MOD * b.a[k][j] ) % MOD ) % MOD;
        }
        return c;
    }
};
LL n, a, b, c, d;

LL qpow( LL a, LL b ) {
    LL ret = 1;
    while( b ) {
        if( b & 1 ) ret = ( ret * a ) % MOD;
        a = ( a * a ) % MOD;
        b >>= 1;
    }
    return ret;
}

Mat mat_qpow( Mat &a, LL b ) {
    Mat ret( 3, 3 );
    for( int i = 0; i < 3; ++i ) ret.a[i][i] = 1;
    while( b ) {
        if( b & 1 ) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%I64d%I64d%I64d%I64d%I64d", &n, &a, &b, &c, &MOD );
        if( n == 1 ) puts( "1" );
        else if( n == 2 ) printf( "%I64d\n", qpow( a, b ) );
        else {
            Mat mat( 3, 3 );
            mat.a[0][0] = c; mat.a[0][1] = 1; mat.a[0][2] = b;
            mat.a[1][0] = 1; mat.a[1][1] = 0; mat.a[1][2] = 0;
            mat.a[2][0] = 0; mat.a[2][1] = 0; mat.a[2][2] = 1;
            --MOD;
            mat = mat_qpow( mat, n - 2 );
            LL tmp = mat.a[0][0] * b + mat.a[0][2];
            ++MOD;
            printf( "%I64d\n", qpow( a, tmp ) );
        }
    }
    return 0;
}
