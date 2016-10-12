/* POJ 2104 验过
    1. T大小需要计算，一般64倍足够
    2. 每颗树的含义需要明确，此题中每棵树存的是离散化后数据域，
        记录每个数据出现的次数，并非每个位置上是什么数。
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Node { int l, r, num; };
Node T[MAXN << 6];
vector<int> vec;
int root[MAXN], a[MAXN];
int n, m, cnt;

int getid( int x ) { return upper_bound( vec.begin(), vec.end(), x ) - vec.begin(); }

void update( int left, int right, int &x, int y, int pos ) {
    T[++cnt] = T[y]; ++T[cnt].num; x = cnt;
    if( left == right ) return ;
    int mid = ( left + right ) >> 1;
    if( mid >= pos ) update( left, mid, T[x].l, T[y].l, pos );
    else update( mid + 1, right, T[x].r, T[y].r, pos );
    return ;
}

int query( int left, int right, int x, int y, int k ) {
    if( left == right ) return left;
    int mid = ( left + right ) >> 1, ret = 0, sum = 0;
    sum = T[T[y].l].num - T[T[x].l].num;
    if( sum >= k ) ret = query( left, mid, T[x].l, T[y].l, k );
    else ret = query( mid + 1, right, T[x].r, T[y].r, k - sum );
    return ret;
}

int main() {
    cnt = 0;
    scanf( "%d%d", &n, &m );
    for( int i = 1, t; i <= n; ++i ) scanf( "%d", a + i ), vec.push_back( a[i] );
    sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
    for( int i = 1; i <= n; ++i ) update( 1, vec.size(), root[i], root[i - 1], getid( a[i] ) );
    for( int i = 0, x, y, z; i < m; ++i ) {
        scanf( "%d%d%d", &x, &y, &z );
        printf( "%d\n", vec[query( 1, vec.size(), root[x - 1], root[y], z ) - 1] );
    }
    return 0;
}
