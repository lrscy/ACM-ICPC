#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;

int n, m;

int main() {
    int ssum = 0;
    while( ~scanf( "%d%d", &n, &m ) ) {
        for( int i = 0; i <= n; ++i ) {
            int ti = i, tn = n, sum = 0, tsum = 0, tot = 0, limit = INF, cnt = 0;
            while( sum <= i && tsum < limit ) {
                tn >>= 1;
                if( tn == 0 ) tn = 1;
                if( sum + tn <= i ) { sum += tn; tsum += tn; }
                else { limit = tn - 1; tsum = 0; ++cnt; }
                ++tot;
            }
            if( i == n ) { --cnt; --tot; }
            if( i && cnt > m ) continue;
            else ssum += tot;
        }
        printf( "%.6f\n", 1.0 * ssum / ( n + 1 ) );
    }
    return 0;
}
