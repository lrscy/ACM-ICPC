#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

struct Martix {
    int a[2][2];
    Martix operator + ( const Martix &tm ) const {
        Martix retm;
        for( int i = 0; i < 2; ++i ) {
            for( int j = 0; j < 2; ++j )
                retm.a[i][j] = ( a[i][j] + tm.a[i][j] ) % MOD;
        }
        return retm;
    }
    Martix operator * ( const Martix &tm ) const {
        Martix retm;
        retm.a[0][0] = retm.a[0][1] = retm.a[1][0] = retm.a[1][1] = 0;
        for( int i = 0; i < 2; ++i ) {
            for( int k = 0; k < 2; ++k )
                if( a[i][k] )
                    for( int j = 0; j < 2; ++j )
                        retm.a[i][j] = ( retm.a[i][j] + 1LL * a[i][k] * tm.a[k][j] % MOD ) % MOD;
        }
        return retm;
    }
};
Martix node[MAXN << 2], lazy[MAXN << 2];
int n, m;

Martix mpow( Martix a, int b ) {
    Martix ret;
    ret.a[0][0] = ret.a[1][1] = 1; ret.a[0][1] = ret.a[1][0] = 0;
    while( b ) {
        if( b & 1 ) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

void build( int rt, int l, int r ) {
    node[rt].a[0][0] = 0; node[rt].a[0][1] = node[rt].a[1][0] = node[rt].a[1][1] = 1;
    lazy[rt].a[0][0] = lazy[rt].a[1][1] = 1; lazy[rt].a[0][1] = lazy[rt].a[1][0] = 0;
    if( l == r ) {
        int x;
        scanf( "%d", &x );
        node[rt] = mpow( node[rt], x );
        return ;
    }
    int mid = ( l + r ) >> 1;
    build( lson ); build( rson );
    node[rt] = node[rt << 1] + node[rt << 1 | 1];
}

bool judge( const Martix &tm ) {
    for( int i = 0; i < 2; ++i ) {
        for( int j = 0; j < 2; ++j )
            if( tm.a[i][j] )
                return false;
    }
    return true;
}

void dowork( int rt, int l, int r ) {
    if( !judge( lazy[rt] ) ) {
        int son = rt << 1;
        lazy[son] = lazy[son] * lazy[rt]; node[son] = node[son] * lazy[rt];
        son = rt << 1 | 1;
        lazy[son] = lazy[son] * lazy[rt]; node[son] = node[son] * lazy[rt];
        lazy[rt].a[0][0] = lazy[rt].a[1][1] = 1; lazy[rt].a[0][1] = lazy[rt].a[1][0] = 0;
    }
}

void update( int rt, int l, int r, int x, int y, Martix &tm ) {
    if( x <= l && r <= y ) {
        lazy[rt] = lazy[rt] * tm;
        node[rt] = node[rt] * tm;
        return ;
    }
    dowork( rt, l, r );
    int mid = ( l + r ) >> 1;
    if( y <= mid ) update( lson, x, y, tm );
    else if( x > mid ) update( rson, x, y, tm );
    else {
        update( lson, x, mid, tm );
        update( rson, mid + 1, y, tm );
    }
    node[rt] = node[rt << 1] + node[rt << 1 | 1];
}

Martix query( int rt, int l, int r, int x, int y ) {
    if( x <= l && r <= y ) { return node[rt]; }
    dowork( rt, l, r );
    Martix tm;
    tm.a[0][0] = tm.a[0][1] = tm.a[1][0] = tm.a[1][1] = 0;
    int mid = ( l + r ) >> 1;
    if( y <= mid ) tm = tm + query( lson, x, y );
    else if( x > mid ) tm = tm + query( rson, x, y );
    else {
        tm = tm + query( lson, x, mid );
        tm = tm + query( rson, mid + 1, y );
    }
    return tm;
}

int main() {
    scanf( "%d%d", &n, &m );
    build( 1, 1, n );
    for( int i = 0, t, x, y, z; i < m; ++i ) {
        scanf( "%d", &t );
        if( t == 1 ) {
            scanf( "%d%d%d", &x, &y, &z );
            Martix tm;
            tm.a[0][0] = 0; tm.a[0][1] = tm.a[1][0] = tm.a[1][1] = 1;
            tm = mpow( tm, z );
            update( 1, 1, n, x, y, tm );
        } else {
            scanf( "%d%d", &x, &y );
            Martix tm = query( 1, 1, n, x, y );
            printf( "%d\n", tm.a[1][0] );
        }
    }
    return 0;
}
