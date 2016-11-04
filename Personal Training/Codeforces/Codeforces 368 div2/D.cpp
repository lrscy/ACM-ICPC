#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 10;
#define lson ls[rt], left, mid 
#define rson rs[rt], mid + 1, right

bitset<MAXN> bs[MAXN << 3];
LL num[MAXN << 3], last[MAXN << 3], root[MAXN << 3], ls[MAXN << 3], rs[MAXN << 3];
int n, m, q, cnt, tot;

void build( int rt, int left, int right ) {
    num[rt] = 0;
    if( left == right ) return ;
    ls[rt] = cnt++; rs[rt] = cnt++;
    int mid = ( left + right ) >> 1;
    build( lson );
    build( rson );
    num[rt] = num[ls[rt]] + num[rs[rt]];
    return ;
}

int gao( int x, int y, int z ) {
    if( y == 1 ) bs[x][z] = 1;
    if( y == 2 ) bs[x][z] = 0;
    if( y == 3 ) for( int i = 0; i < n; ++i ) bs[x].flip( i );
    return bs[x].count();
}

void update( int rt, int left, int right, int pos, int v1, int v2 ) {
    if( left == pos && right == pos ) {
        num[rt] = gao( rt, v1, v2 );
        return ;
    }
    int mid = ( left + right ) >> 1;
    if( pos <= mid ) {
        ls[rt] = cnt++;
        rs[rt] = rs[last[rt]];
        update( lson, pos, v1, v2 );
    } else {
        ls[rt] = ls[last[rt]];
        rs[rt] = cnt++;
        update( rson, pos, v1, v2 );
    }
    num[rt] = num[ls[rt]] + num[rs[rt]];
    return ;
}

int main() {
    int tt, a, b, c, d, e;
    for( int i = 0; i < MAXN; ++i ) bs[i].reset();
    scanf( "%d%d%d", &n, &m, &q );
    cnt = tot = 0;
    root[tot++] = 0;
    build( root[tot - 1], 1, n );
    while( q-- ) {
        scanf( "%d", &tt );
        if( tt == 1 ) {
            scanf( "%d%d", &d, &e ); --e;
            last[cnt] = root[tot - 1]; root[tot++] = cnt; ++cnt;
            update( root[tot - 1], 1, n, d, 1, e );
        } else if( tt == 2 ) {
            scanf( "%d%d", &d, &e ); --e;
            root[tot++] = cnt; ++cnt;
            update( root[tot - 1], 1, n, d, 2, e );
        } else if( tt == 3 ) {
            scanf( "%d", &d );
            root[tot++] = cnt; ++cnt;
            update( root[tot - 1], 1, n, d, 3, e );
        } else {
            scanf( "%d", &d );
            tot = d + 1;
        }
        LL ans = 0;
        printf( "%d\n", num[root[tot - 1]] );
    }
    return 0;
}
