#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
#define lson rt << 1, left, mid 
#define rson rt << 1 | 1, mid + 1, right

int num[MAXN << 2], num2[MAXN], lazy[MAXN << 2], lazy2[MAXN << 2], val[MAXN], x[MAXN], y[MAXN], sum[MAXN];
int n, m;

void build( int rt, int left, int right ) {
    lazy[rt] = lazy[rt] = num[rt] = num2[rt] = 0;
    if( left == right ) return ;
    int mid = ( left + right ) >> 1;
    build( lson );
    build( rson );
    return ;
}

void update( int rt, int left, int right, int l, int r, int val );
void dowork( int rt ) {
    if( lazy[rt] ) {
        int son = rt << 1; num[son] = lazy[rt]; num2[son] = lazy2[rt]; lazy[son] = lazy[rt]; lazy2[son] = lazy2[rt];
        son = rt << 1 | 1; num[son] = lazy[rt]; num2[son] = lazy2[rt]; lazy[son] = lazy[rt]; lazy2[son] = lazy2[rt];
        lazy[rt] = lazy2[rt] = 0;
    }
    return ;
}

void update( int rt, int left, int right, int l, int r, int val ) {
    if( left == l && right == r ) {
        if( num[rt] == 0 ) num[rt] = num2[rt] = val;
        else num2[rt] = val;
        if( l != r ) lazy[rt] = num[rt], lazy2[rt] = num2[rt];
        return ;
    }
    dowork( rt );
    int mid = ( left + right ) >> 1;
    if( r <= mid ) update( lson, l, r, val );
    else if( l > mid ) update( rson, l, r, val );
    else {
        update( lson, l, mid, val );
        update( rson, mid + 1, r, val );
    }
    return ;
}

void query( int rt, int left, int right, int pos ) {
    if( left == pos && right == pos ) {
        x[pos] = num[rt]; y[pos] = num2[rt];
        return ;
    }
    dowork( rt );
    int mid = ( left + right ) >> 1;
    if( pos <= mid ) query( lson, pos );
    else query( rson, pos );
    return ;
}

int main() {
    int a, b;
    while( ~scanf( "%d%d", &n, &m ) ) {
        build( 1, 1, n );
        for( int i = 1; i < n; ++i ) scanf( "%d", val + i ), sum[i] += val[i];
        for( int i = 1; i <= m; ++i ) {
            scanf( "%d%d", &a, &b ); --b;
            update( 1, 1, n, a, b, i );
        }
        for( int i = 1; i < n; ++i ) query( 1, 1, n, i );
        LL ans = 0;
        for( int i = 1; i <= m; ++i ) {
            ;
        }
    }
    return 0;
}
