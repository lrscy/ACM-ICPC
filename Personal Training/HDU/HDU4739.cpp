#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 5e3 + 10;
const int MAXM = 1 << 21;

PII pii[MAXN];
set<int> st;
int mask[MAXN], m1[MAXN], m2[MAXN];
int dp[MAXM];
int n;

int main() {
    while( ~scanf( "%d", &n ) && n != -1 ) {
        memset( dp, 0, sizeof dp );
        st.clear();
        for( int i = 0; i < n; ++i ) scanf( "%d%d", &pii[i].first, &pii[i].second );;
        int tot = 0;
        for( int i = 0; i < n; ++i ) {
            for( int j = i + 1; j < n; ++j ) {
                int x1 = pii[i].first, y1 = pii[i].second;
                int x2 = pii[j].first, y2 = pii[j].second;
                if( x1 == x2 || y1 == y2 ) continue;
                if( abs( x1 - x2 ) != abs( y2 - y1 ) ) continue;
                int c1 = 0, c2 = 0;
                for( int k = 0; k < n; ++k ) {
                    if( k == i || k == j ) continue;
                    if( pii[k].first == x1 && pii[k].second == y2 ) m1[c1++] = k;
                    if( pii[k].first == x2 && pii[k].second == y1 ) m2[c2++] = k;
                }
                if( c1 && c2 ) {
                    for( int x = 0; x < c1; ++x ) {
                        for( int y = 0; y < c2; ++y ) {
                            int msk = ( 1 << i ) | ( 1 << j ) | ( 1 << m1[x] ) | ( 1 << m2[y] );
//                            if( st.find( msk ) != st.end() ) continue;
                            mask[tot] = msk;
                            dp[msk] = 4;
                            ++tot;
                        }
                    }
                }
            }
        }
        for( int s = 0; s < ( 1 << n ); ++s ) {
            for( int i = 0; i < tot; ++i ) {
                int msk = mask[i];
                if( s & msk ) continue;
                dp[s | msk] = max( dp[s | msk], dp[s] + dp[msk] );
            }
        }
        printf( "%d\n", dp[( 1 << n ) - 1] );
    }
    return 0;
}
