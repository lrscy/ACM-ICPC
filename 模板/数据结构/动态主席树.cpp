/* 没法验 ZOJ不开了
    对于修改操作，只是修改M次，每次改变俩个值（减去原先的，加上现在的）
    也就是说如果把所有初值都插入到树状数组里是不值得的，
    所以我们分两部分来做，所有初值按照静态来建，内存O(nlogn)，
    而修改部分保存在树状数组中，每次修改logn棵树，每次插入增加logn个节点
    O(M*logn*logn+nlogn)
    1. 一定要全部离线后再做其他操作！！包括修改的数据！！
    2. 空间需要计算下
    3. 树状数组前n项为修改位置对应数据；后n项为建树初始状态数据
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 1e4 + 10;

struct Node { int ls, rs, sum; };
Node tr[MAXN << 4];
struct Opr { int flag, l, r, k; };
Opr op[MAXM];
vector<int> vec, q1, q2;
int a[MAXN], root[MAXN << 1];
int n, m, tn, tot;

int getid( int x ) { return upper_bound( vec.begin(), vec.end(), x ) - vec.begin(); }
inline int lowbit( int x ) { return x & -x; }

void build( int l, int r, int &x, int pos ) {
    tr[++tot] = tr[x]; x = tot; ++tr[x].sum;
    if( l == r ) return ;
    int m = ( l + r ) >> 1;
    if( pos <= m ) build( l, m, tr[x].ls, pos );
    else build( m + 1, r, tr[x].rs, pos );
}

void insrt( int l, int r, int &x, int pos, int val ) {
    if( x == 0 ) { tr[++tot] = tr[x]; x = tot; }
    tr[x].sum += val;
    if( l == r ) return ;
    int m = ( l + r ) >> 1;
    if( pos <= m ) insrt( l, m, tr[x].ls, pos, val );
    else insrt( m + 1, r, tr[x].rs, pos, val );
}

void bitinsrt( int pos, int x, int val ) {
    int t = getid( x );
    for( int i = pos; i <= n; i += lowbit( i ) ) insrt( 1, tn, root[i], t, val );
}

int qury( int l, int r, vector<int> &q1, vector<int> &q2, int k ) {
    if( l == r ) return l;
    int cnt = 0, m = ( l + r ) >> 1;
    for( int i = 0; i < q1.size(); ++i ) cnt -= tr[tr[q1[i]].ls].sum;
    for( int i = 0; i < q2.size(); ++i ) cnt += tr[tr[q2[i]].ls].sum;
    for( int i = 0; i < q1.size(); ++i ) q1[i] = ( cnt >= k ? tr[q1[i]].ls : tr[q1[i]].rs );
    for( int i = 0; i < q2.size(); ++i ) q2[i] = ( cnt >= k ? tr[q2[i]].ls : tr[q2[i]].rs );
    if( cnt >= k ) return qury( l, m, q1, q2, k );
    else return qury( m + 1, r, q1, q2, k - cnt );
}

int bitqury( int l, int r, int k ) {
    q1.clear(); q2.clear();
    q1.push_back( root[l == 1 ? 0 : l - 1 + n] );
    q2.push_back( root[r + n] );
    for( int i = l - 1; i > 0; i -= lowbit( i ) ) q1.push_back( root[i] );
    for( int i = r; i > 0; i -= lowbit( i ) ) q2.push_back( root[i] );
    return vec[qury( 1, tn, q1, q2, k ) - 1];
}

int main() {
    char s[2];
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        vec.clear(); tot = 0;
        memset( root, 0, sizeof root );
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) scanf( "%d", a + i ), vec.push_back( a[i] );
        for( int i = 0, x, y, z; i < m; ++i ) {
            scanf( "%s", s );
            if( s[0] == 'Q' ) {
                op[i].flag = 0;
                scanf( "%d%d%d", &op[i].l, &op[i].r, &op[i].k );
            } else {
                op[i].flag = 1;
                scanf( "%d%d", &op[i].l, &op[i].r );
                vec.push_back( op[i].r );
            }
        }
        sort( vec.begin(), vec.end() ); tn = unique( vec.begin(), vec.end() ) - vec.begin();
        for( int i = 1; i <= n; ++i ) {
            root[i + n] = root[i - 1 + n];
            build( 1, tn, root[i + n], getid( a[i] ) );
        }
        for( int i = 0; i < m; ++i ) {
            if( op[i].flag == 0 ) printf( "%d\n", bitqury( op[i].l, op[i].r, op[i].k ) );
            else {
                bitinsrt( op[i].l, a[op[i].l], -1 );
                bitinsrt( op[i].l, op[i].r, 1 );
                a[op[i].l] = op[i].r;
            }
        }
    }
    return 0;
}
