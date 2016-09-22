#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

int a[MAXN];
int n, m;

LL gao( int mid ) {
    LL ret = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for( int i = 0; i < n; ++i ) pq.push( a[i] );
    int tmp = ( n - 1 ) % ( mid - 1 );
    for( int i = 0; i < tmp; ++i ) pq.push( 0 );
    while( pq.size() > 1 ) {
        LL tmp = 0;
        for( int i = 0; i < mid && !pq.empty(); ++i ) {
            tmp += pq.top();
            pq.pop();
        }
        ret += tmp;
        pq.push( tmp );
    }
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        int low = 1, high = n;
        while( low < high ) {
            int mid = ( low + high ) >> 1;
            if( gao( mid ) <= m ) high = mid;
            else low = mid + 1;
        }
        printf( "%d\n", high );
    }
    return 0;
}
