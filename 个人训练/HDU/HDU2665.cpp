#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Node { int l, r, sum; };
Node tr[MAXN << 6];
vector<int> vec;
int root[MAXN], a[MAXN];
int n, m, cnt;

int getid( int x ) { return upper_bound( vec.begin(), vec.end(), x ) - vec.begin(); }

void update( int l, int r, int &x, int y, int pos ) {
    x = ++cnt; tr[x] = tr[y]; ++tr[x].sum;
    if( l == r ) return ;
    int mid = ( l + r ) >> 1;
    if( pos <= mid ) update( l, mid, tr[x].l, tr[y].l, pos );
    else update( mid + 1, r, tr[x].r, tr[y].r, pos );
}

int query( int l, int r, int x, int y, int k ) {
    if( l == r ) return l;
    int mid = ( l + r ) >> 1;
    int sum = tr[tr[y].l].sum - tr[tr[x].l].sum;
    if( sum >= k ) return query( l, mid, tr[x].l, tr[y].l, k );
    else return query( mid + 1, r, tr[x].r, tr[y].r, k - sum );
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        vec.clear(); cnt = 0;
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i ), vec.push_back( a[i] );
        sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        for( int i = 1; i <= n; ++i ) update( 1, n, root[i], root[i - 1], getid( a[i] ) );
        for( int i = 0, u, v, k; i < m; ++i ) {
            scanf( "%d%d%d", &u, &v, &k );
            printf( "%d\n", vec[query( 1, n, root[u - 1], root[v], k ) - 1] );
        }
    }
    return 0;
}
