/* HDU 4348 已验
    lazy 不下放，只标记，查询时带上即可 省去许多因下放而产生的新节点
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

struct Node { int ls, rs, add; LL sum; };
Node tr[MAXN << 5];
int root[MAXN];
int n, m, tot;

int build( int l, int r ) {
    int cur = ++tot;
    tr[cur].add = 0;
    if( l == r ) { scanf( "%I64d", &tr[cur].sum ); return cur; }
    int mid = ( l + r ) >> 1;
    tr[cur].ls = build( l, mid );
    tr[cur].rs = build( mid + 1, r );
    tr[cur].sum = tr[tr[cur].ls].sum + tr[tr[cur].rs].sum;
    return cur;
}

void update( int l, int r, int left, int right, int &x, int y, int val ) {
    x = ++tot; tr[x] = tr[y];
    tr[x].sum += val * ( right - left + 1 );
    if( left <= l && r <= right ) {
        tr[x].add += val;
        return ;
    }
    int mid = ( l + r ) >> 1;
    if( right <= mid ) update( l, mid, left, right, tr[x].ls, tr[y].ls, val );
    else if( mid < left ) update( mid + 1, r, left, right, tr[x].rs, tr[y].rs, val );
    else {
        update( l, mid, left, mid, tr[x].ls, tr[y].ls, val );
        update( mid + 1, r, mid + 1, right, tr[x].rs, tr[y].rs, val );
    }
}

LL query( int l, int r, int left, int right, int rt ) {
    if( left <= l && r <= right ) return tr[rt].sum;
    LL ret = tr[rt].add * ( right - left + 1 );
    int mid = ( l + r ) >> 1;
    if( right <= mid ) return ret + query( l, mid, left, right, tr[rt].ls );
    else if( mid < left ) return ret + query( mid + 1, r, left, right, tr[rt].rs );
    else return ret + query( l, mid, left, mid, tr[rt].ls ) + query( mid + 1, r, mid + 1, right, tr[rt].rs );
}

int main() {
    char s[5];
    int cur;
    while( ~scanf( "%d%d", &n, &m ) ) {
        tot = 0;
        root[cur = 0] = build( 1, n );
        for( int i = 0, x, y, z; i < m; ++i ) {
            scanf( "%s", s );
            if( s[0] == 'C' ) {
                scanf( "%d%d%d", &x, &y, &z ); ++cur;
                update( 1, n, x, y, root[cur], root[cur - 1], z );
            } else if( s[0] == 'Q' ) {
                scanf( "%d%d", &x, &y );
                printf( "%I64d\n", query( 1, n, x, y, root[cur] ) );
            } else if( s[0] == 'H' ) {
                scanf( "%d%d%d", &x, &y, &z );
                printf( "%I64d\n", query( 1, n, x, y, root[z] ) );
            } else scanf( "%d", &cur );
        }
    }
    return 0;
}
