/* HYSBZ 2038 已验
    这是离线算法，有时需要离散化数据
    1. update函数要求O(1)转移
    2. update的第二个参数依据具体情况定
    3. 间隔dm一般取sqrt(n)，特殊情况卡空间可以改成n^(2/3)
    4. 下标从1开始
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;

struct Node { int l, r, id; LL a, b; };
Node node[MAXN];
LL cnt[MAXN], ans;
int c[MAXN], pos[MAXN];
int n, m;

LL gcd( LL a, LL b ) { return b ? gcd( b, a % b ) : a; }

bool cmp( const Node &a, const Node &b ) {
    return pos[a.l] == pos[b.l] ? a.r < b.r : a.l < b.l;
}

bool cmp_id( const Node &a, const Node &b ) {
    return a.id < b.id;
}

// O(1)
void update( int x, int d ) {
    ans -= cnt[c[x]] * cnt[c[x]];
    cnt[c[x]] += d;
    ans += cnt[c[x]] * cnt[c[x]];
    return ;
}

void solve() {
    ans = 0;
    for( int i = 0, l = 1, r = 0; i < m; ++i ) {
        while( r < node[i].r ) update( ++r, 1 );
        while( r > node[i].r ) update( r--, -1 );
        while( l < node[i].l ) update( l++, -1 );
        while( l > node[i].l ) update( --l, 1 );
        // solve
        node[i].a = ans - ( r - l + 1 );
        node[i].b = 1LL * ( r - l + 1 ) * ( r - l );
        LL k = gcd( node[i].a, node[i].b );
        node[i].a /= k; node[i].b /= k;
    }
    return ;
}

int main() {
    scanf( "%d%d", &n, &m );
    int dm = ( int )sqrt( n );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", c + i );
        pos[i] = ( i - 1 ) / dm + 1;
    }
    for( int i = 0; i < m; ++i ) {
        scanf( "%d%d", &node[i].l, &node[i].r );
        node[i].id = i;
    }
    sort( node, node + m, cmp );
    solve();
    sort( node, node + m, cmp_id );
    for( int i = 0; i < m; ++i ) printf( "%lld/%lld\n", node[i].a, node[i].b );
    return 0;
}
