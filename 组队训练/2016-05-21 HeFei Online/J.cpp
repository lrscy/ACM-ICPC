#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

PII p[MAXN];
int cnt[MAXN << 2], ans[MAXN];
int n;

void push_up( int rt ) {
    cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
    return ;
}

void build( int rt, int left, int right ) {
    if( left == right ) { cnt[rt] = 1; return ; }
    int mid = ( left + right ) >> 1;
    build( lson ); build( rson );
    push_up( rt );
    return ;
}

int findk( int rt, int left, int right, int k ) {
    if( left == right ) { cnt[rt] = 0; return left; }
    int mid = ( left + right ) >> 1, ret = 0;
    if( k <= cnt[rt << 1] ) ret = findk( lson, k );
    else ret = findk( rson, k - cnt[rt << 1] );
    push_up( rt );
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d:", ncas );
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) scanf( "%d%d", &p[i].first, &p[i].second );
        sort( p, p + n );
        build( 1, 1, n );
        bool flag = true;
        for( int i = 0; i < n; ++i ) {
            if( p[i].second + 1 > cnt[1] ) { flag = false; break; }
            int tk = min( p[i].second + 1, cnt[1] - p[i].second );
            int pos = findk( 1, 1, n, tk );
            ans[pos] = p[i].first;
        }
        if( !flag ) puts( " impossible" );
        else {
            for( int i = 1; i <= n; ++i ) printf( " %d", ans[i] );
            puts( "" );
        }
    }
    return 0;
}
