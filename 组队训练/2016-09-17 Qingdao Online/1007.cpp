#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

LL a[MAXN];
int n, m;

LL gao( int mid ) {
    queue<LL> q, qs;
    LL ret = 0;
    int tmp = ( n - 1 ) % ( mid - 1 );
    if( tmp ) for( int i = 0; i < mid - 1 - tmp; ++i ) q.push( 0 );
    for( int i = 0; i < n; ++i ) q.push( a[i] );
    while( !q.empty() || !qs.empty() ) {
        LL sum = 0;
        for( int i = 0; i < mid; ++i ) {
            if( q.empty() && qs.empty() ) break;
            if( q.empty() ) { sum += qs.front(); qs.pop(); }
            else if( qs.empty() ) { sum += q.front(); q.pop(); }
            else {
                int u = q.front(), v = qs.front();
                if( u < v ) { sum += u; q.pop(); }
                else { sum += v; qs.pop(); }
            }
        }
        ret += sum;
        if( q.empty() && qs.empty() ) break;
        qs.push( sum );
    }
    return ret <= m;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < n; ++i ) scanf( "%I64d", a + i );
        sort( a, a + n );
        int low = 2, high = n;
        while( low < high ) {
            int mid = ( low + high ) >> 1;
            if( gao( mid ) ) high = mid;
            else low = mid + 1;
        }
        printf( "%d\n", high );
    }
    return 0;
}
