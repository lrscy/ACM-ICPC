#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int POW = 32;

struct Edge { int to, next; };
Edge es[MAXN << 1];
struct Node { int l, r, sum; };
Node tr[MAXN << 6];
vector<int> vec;
int seq[MAXN << 1], dep[MAXN << 1], fir[MAXN], fa[MAXN];
int lg2[MAXN << 1], dp[MAXN << 1][POW];
int head[MAXN], a[MAXN], rt[MAXN];
int n, m, cnt, cnt2, tot;

int getid( int x ) { return upper_bound( vec.begin(), vec.end(), x ) - vec.begin(); }

void add( int u, int v ) { es[cnt2].to = v; es[cnt2].next = head[u]; head[u] = cnt2++; }

void update( int l, int r, int &x, int y, int pos ) {
    x = ++cnt; tr[x] = tr[y]; ++tr[x].sum;
    if( l == r ) return ;
    int mid = ( l + r ) >> 1;
    if( pos <= mid ) update( l, mid, tr[x].l, tr[y].l, pos );
    else update( mid + 1, r, tr[x].r, tr[y].r, pos );
}

int query( int l, int r, int x, int y, int xx, int yy, int k ) {
    if( l == r ) return l;
    int mid = ( l + r ) >> 1;
    int sum = tr[tr[x].l].sum + tr[tr[y].l].sum - tr[tr[xx].l].sum - tr[tr[yy].l].sum;
    if( sum >= k ) return query( l, mid, tr[x].l, tr[y].l, tr[xx].l, tr[yy].l, k );
    else return query( mid + 1, r, tr[x].r, tr[y].r, tr[xx].r, tr[yy].r, k - sum );
}

void dfs( int u, int fu, int d ) {
    seq[++tot] = u; dep[tot] = d; fir[u] = tot; fa[u] = fu;
    update( 1, vec.size(), rt[u], rt[fa[u]], getid( a[u] ) );
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fu ) continue;
        dfs( v, u, d + 1 );
        seq[++tot] = u; dep[tot] = d;
    }
}

void init_lca() {
    int tn = 2 * n - 1;
    lg2[0] = -1; for( int i = 1; i < ( MAXN << 1 ); ++i ) lg2[i] = ( ( i & ( i - 1 ) ) == 0 ) ? lg2[i - 1] + 1 : lg2[i - 1];
    for( int i = 1; i <= tn; ++i ) dp[i][0] = i;
    for( int j = 1; j < 20; ++j ) {
        for( int i = 1; i + ( 1 << j ) - 1 <= tn; ++i ) {
            int a = dp[i][j - 1], b = dp[i + ( 1 << ( j - 1 ) )][j - 1];
            dp[i][j] = dep[a] < dep[b] ? a : b;
        }
    }
}

int lca( int x, int y ) {
    int k = lg2[y - x + 1];
    int a = dp[x][k], b = dp[y - ( 1 << k ) + 1][k];
    return ( dep[a] < dep[b] ? a : b );
}

int main() {
    memset( head, -1, sizeof head ); tot = cnt = cnt2 = 0;
    vec.clear();
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i ) scanf( "%d", a + i ), vec.push_back( a[i] );
    sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
    for( int i = 1, u, v; i < n; ++i ) { scanf( "%d%d", &u, &v ); add( u, v ); add( v, u ); }
    dfs( 1, 0, 1 );
    init_lca();
    for( int i = 0, u, v, k; i < m; ++i ) {
        scanf( "%d%d%d", &u, &v, &k );
        if( fir[u] > fir[v] ) swap( u, v );
        int z = seq[lca( fir[u], fir[v] )];
        int tt = query( 1, vec.size(), rt[u], rt[v], rt[z], rt[fa[z]], k ) - 1;
        printf( "%d\n", vec[tt] );
    }
    return 0;
}
