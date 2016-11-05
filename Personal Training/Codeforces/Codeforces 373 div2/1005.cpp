#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

struct Martix {
    LL a[2][2];
    void init() { a[0][0] = 0; a[0][1] = a[1][0] = 1; a[1][1] = 1; }
    void zero() { memset( a, 0, sizeof a ); }
    void one() { a[0][0] = a[1][1] = 1; a[0][1] = a[1][0] = 0; }
    bool operator == ( const Martix &tm ) {
        for( int i = 0; i < 2; ++i ) {
            for( int j = 0; j < 2; ++j )
                if( a[i][j] != tm.a[i][j] )
                    return false;
        }
        return true;
    }
    Martix operator + ( const Martix &tm ) {
        Martix retm;
        for( int i = 0; i < 2; ++i ) {
            for( int j = 0; j < 2; ++j )
                retm.a[i][j] = ( a[i][j] + tm.a[i][j] ) % MOD;
        }
        return retm;
    }
    Martix operator * ( const Martix &tm ) {
        Martix retm;
        retm.zero();
        for( int i = 0; i < 2; ++i ) {
            for( int j = 0; j < 2; ++j )
                for( int k = 0; k < 2; ++k )
                    retm.a[i][j] = ( retm.a[i][j] + a[i][k] * tm.a[k][j] % MOD ) % MOD;
        }
        return retm;
    }
};
Martix node[MAXN << 2], lazy[MAXN << 2], zero;
int n, m;

Martix mpow( Martix a, int b ) {
    Martix ret;
    ret.one();
    while( b ) {
        if( b & 1 ) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

void build( int rt, int l, int r ) {
    node[rt].init();
    lazy[rt].one();
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

void dowork( int rt, int l, int r ) {
    if( !( lazy[rt] == zero ) ) {
        int son = rt << 1;
        lazy[son] = lazy[son] * lazy[rt]; node[son] = node[son] * lazy[rt];
        son = rt << 1 | 1;
        lazy[son] = lazy[son] * lazy[rt]; node[son] = node[son] * lazy[rt];
        lazy[rt].one();
    }
}

void update( int rt, int l, int r, int x, int y, int z ) {
    if( x <= l && r <= y ) {
        Martix tm; tm.init();
        tm = mpow( tm, z );
        lazy[rt] = lazy[rt] * tm;
        node[rt] = node[rt] * tm;
        return ;
    }
    dowork( rt, l, r );
    int mid = ( l + r ) >> 1;
    if( y <= mid ) update( lson, x, y, z );
    else if( x > mid ) update( rson, x, y, z );
    else {
        update( lson, x, mid, z );
        update( rson, mid + 1, y, z );
    }
    node[rt] = node[rt << 1] + node[rt << 1 | 1];
}

Martix query( int rt, int l, int r, int x, int y ) {
    if( x <= l && r <= y ) { return node[rt]; }
    dowork( rt, l, r );
    Martix tm;
    tm.zero();
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
    zero.zero();
    scanf( "%d%d", &n, &m );
    build( 1, 1, n );
    for( int i = 0, t, x, y, z; i < m; ++i ) {
        scanf( "%d", &t );
        if( t == 1 ) {
            scanf( "%d%d%d", &x, &y, &z );
            update( 1, 1, n, x, y, z );
        } else {
            scanf( "%d%d", &x, &y );
            Martix tm = query( 1, 1, n, x, y );
            printf( "%lld\n", tm.a[1][0] );
        }
    }
    return 0;
}
