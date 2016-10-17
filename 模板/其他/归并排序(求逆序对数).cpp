#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 500010
#define INF 0x3FFFFFFF

int L[MAXN], R[MAXN], a[MAXN];
long long cnt;

void _merge( int l, int m, int r ) {
    int i, j, k;
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    for( i = 0; i < n1; ++i )
        L[i] = a[l + i];
    for( i = 0; i < n2; ++i )
        R[i] = a[m + 1 + i];
    L[n1] = INF;
    R[n2] = INF;
    i = j = 0;
    for( k = l; k <= r; ++k ) {
        if( L[i] <= R[j] )
            a[k] = L[i++];
        else {
            a[k] = R[j++];
            cnt += n1 - i;
        }
    }
    return ;
}

void _merge_sort( int l, int r ) {
    if( l < r ) {
        int m = ( l + r ) / 2;
        _merge_sort( l, m );
        _merge_sort( m + 1, r );
        _merge( l, m, r );
    }
    return ;
}

int main() {
    int i;
    int n;
    while( ~scanf( "%d", &n ) && n ) {
        cnt = 0;
        for( i = 0; i < n; ++i )
            scanf( "%d", a + i );
        _merge_sort( 0, n - 1 );
        printf( "%lld\n", cnt );
    }
    return 0;
}
