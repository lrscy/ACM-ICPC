#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
const int MOD = 1e4 + 7;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

// lz1: +; lz2: *; p1: ^1; p2: ^2; p3: ^3;
int lz1[MAXN << 2], lz2[MAXN << 2], p1[MAXN << 2], p2[MAXN << 2], p3[MAXN << 2];
int n, m;

void build( int rt, int left, int right ) {
    lz1[rt] = 0; lz2[rt] = 1; p1[rt] = p2[rt] = p3[rt] = 0;
    if( left == right ) return ;
    int mid = ( left + right ) >> 1;
    build( lson ); build( rson );
}

void gao1( int rt, int l, int r, int x ) {
    lz1[rt] += x; if( lz1[rt] >= MOD ) lz1[rt] -= MOD;
    p3[rt] += ( 1LL * ( r - l + 1 ) * x % MOD * x * x % MOD + 3LL * p2[rt] * x % MOD + 3LL * p1[rt] * x * x % MOD ) % MOD; if( p3[rt] >= MOD ) p3[rt] -= MOD;
    p2[rt] += ( 1LL * ( r - l + 1 ) * x * x % MOD + 2LL * p1[rt] * x % MOD ) % MOD; if( p2[rt] >= MOD ) p2[rt] -= MOD;
    p1[rt] += 1LL * ( r - l + 1 ) * x % MOD; if( p1[rt] >= MOD ) p1[rt] -= MOD;
}

void gao2( int rt, int l, int r, int x ) {
    lz1[rt] *= x; if( lz1[rt] >= MOD ) lz1[rt] %= MOD;
    lz2[rt] *= x; if( lz2[rt] >= MOD ) lz2[rt] %= MOD;
    p3[rt] *= x * x % MOD * x % MOD; if( p3[rt] >= MOD ) p3[rt] %= MOD;
    p2[rt] *= x * x % MOD; if( p2[rt] >= MOD ) p2[rt] %= MOD;
    p1[rt] *= x; if( p1[rt] >= MOD ) p1[rt] %= MOD;
}

void pushdown( int rt, int left, int right ) {
    int mid = ( left + right ) >> 1;
    if( lz2[rt] != 1 ) { gao2( lson, lz2[rt] ); gao2( rson, lz2[rt] ); }
    if( lz1[rt] != 0 ) { gao1( lson, lz1[rt] ); gao1( rson, lz1[rt] ); }
    lz1[rt] = 0; lz2[rt] = 1;
}

void pushup( int rt ) {
    int s1 = rt << 1, s2 = rt << 1 | 1;
    p1[rt] = ( p1[s1] + p1[s2] ) % MOD;
    p2[rt] = ( p2[s1] + p2[s2] ) % MOD;
    p3[rt] = ( p3[s1] + p3[s2] ) % MOD;
}

void update( int rt, int left, int right, int l, int r, int flag, int x ) {
    if( l <= left && right <= r ) {
        if( flag == 1 ) gao1( rt, l, r, x );
        if( flag == 2 ) gao2( rt, l, r, x );
        if( flag == 3 ) { gao2( rt, l, r, 0 ); gao1( rt, l, r, x ); }
        return ;
    }
    pushdown( rt, left, right );
    int mid = ( left + right ) >> 1;
    if( r <= mid ) update( lson, l, r, flag, x );
    else if( l > mid ) update( rson, l, r, flag, x );
    else {
        update( lson, l, mid, flag, x );
        update( rson, mid + 1, r, flag, x );
    }
    pushup( rt );
}

int query( int rt, int left, int right, int l, int r, int x ) {
    if( l <= left && right <= r ) {
        if( x == 1 ) return p1[rt];
        else if( x == 2 ) return p2[rt];
        else return p3[rt];
    }
    pushdown( rt, left, right );
    int mid = ( left + right ) >> 1;
    if( r <= mid ) return query( lson, l, r, x );
    else if( l > mid ) return query( rson, l, r, x );
    else return ( query( lson, l, mid, x ) + query( rson, mid + 1, r, x ) ) % MOD;
}

int main() {
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        build( 1, 1, n );
        for( int i = 0, a, b, c, d; i < m; ++i ) {
            scanf( "%d%d%d%d", &a, &b, &c, &d );
            if( a <= 3 ) update( 1, 1, n, b, c, a, d );
            else printf( "%d\n", query( 1, 1, n, b, c, d ) );
        }
    }
    return 0;
}
