/*
    定义P-position和N-position，其中P代表Previous，N代表Next。直观的说，上一次move的人有必胜策略的局面是P-position，也就是“后手可保证必胜”或者“先手必败”，现在轮到move的人有必胜策略的局面是N-position，也就是“先手可保证必胜”。更严谨的定义是：1.无法进行任何移动的局面（也就是terminal position）是P-position；2.可以移动到P-position的局面是N-position；3.所有移动都导致N-position的局面是P-position。 按照这个定义，如果局面不可能重现，或者说positions的集合可以进行拓扑排序，那么每个position或者是P-position或者是N-position，而且可以通过定义计算出来。
    !!! 对于一个Nim游戏的局面(a1,a2,...,an)，它是P-position当且仅当a1^a2^...^an=0，其中^表示异或(xor)运算。
    如果Nim游戏中的规则稍微变动一下,每次最多只能取K个,怎么处理? 方法是将每堆石子数mod (k+1).
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int sg[MAXN], a[MAXN];
int n, m;

int gao( int x ) {
    if( ~sg[x] ) return sg[x];
    int i, vis[100];
    memset( vis, 0, sizeof( vis ) );
    for( i = 0; i < n; ++i ) {
        if( x < a[i] ) break;
        vis[gao( x - a[i] )] = 1;
    }
    for( i = 0; vis[i]; ++i );
    return sg[x] = i;
}

int main() {
    int th, ta, ans;
    while( ~scanf( "%d", &n ) && n ) {
        memset( sg, -1, sizeof( sg ) );
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        sort( a, a + n );
        scanf( "%d", &m );
        while( m-- ) {
            ans = 0;
            scanf( "%d", &th );
            while( th-- ) {
                scanf( "%d", &ta );
                ans ^= gao( ta );
            }
            putchar( ans ? 'W' : 'L' );
        }
        puts( "" );
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n;

int main() {
    int t, ta;
    scanf( "%d", &t );
    while( t-- ) {
        int ans = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%d", &ta );
            if( ta % 4 == 0 ) ans ^= ( ta - 1 );
            else if( ta % 4 == 1 || ta % 4 == 2 ) ans ^= ta;
            else ans ^= ( ta + 1 );
        }
        if( ans ) puts( "Alice" );
        else puts( "Bob" );
    }
    return 0;
}
*/
