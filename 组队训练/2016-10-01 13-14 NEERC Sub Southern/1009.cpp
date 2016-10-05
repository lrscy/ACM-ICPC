#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

priority_queue<PII> pq1, pq2;
vector<PII> v1, v2, v3, vans;
int n, a, b;

int main() {
    int ans = 0, c1, c2;
    scanf( "%d%d%d", &n, &a, &b );
    c1 = 0; c2 = a;
    for( int i = 0, t, w; i < n; ++i ) {
        scanf( "%d%d", &t, &w );
        if( t == 1 ) v1.push_back( PII( w, i + 1 ) );
        if( t == 2 ) v2.push_back( PII( w, i + 1 ) );
        if( t == 3 ) v3.push_back( PII( w, i + 1 ) );
    }
    sort( v1.begin(), v1.end() );
    sort( v2.begin(), v2.end() );
    sort( v3.begin(), v3.end() );
    for( int i = 0; i < a && i < v1.size(); ++i ) pq1.push( v1[i] );
    for( int i = 0; i < b && i < v2.size(); ++i ) pq2.push( v2[i] );
    for( int i = 0; i < v3.size(); ++i ) {
        if( pq1.size() < a ) { pq1.push( v3[i] ); continue; }
        if( pq2.size() < b ) { pq2.push( v3[i] ); continue; }
        int tp = -1, nmax = 0;
        if( !pq1.empty() && pq1.top().first > nmax ) { nmax = pq1.top().first; tp = 1; }
        if( !pq2.empty() && pq2.top().first > nmax ) { nmax = pq2.top().first; tp = 2; }
        if( tp == -1 || nmax <= v3[i].first ) break;
        if( tp == 1 ) { pq1.pop(); pq1.push( v3[i] ); }
        if( tp == 2 ) { pq2.pop(); pq2.push( v3[i] ); }
    }
    while( !pq1.empty() ) { PII tp = pq1.top(); pq1.pop(); vans.push_back( PII{ tp.second, ++c1 } ); ans += tp.first; }
    while( !pq2.empty() ) { PII tp = pq2.top(); pq2.pop(); vans.push_back( PII{ tp.second, ++c2 } ); ans += tp.first; }
    printf( "%d %d\n", vans.size(), ans );
    for( int i = 0; i < vans.size(); ++i ) printf( "%d %d\n", vans[i].first, vans[i].second );
    return 0;
}
