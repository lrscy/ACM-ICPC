#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef pair<double, double> PDD;
const int MAXN = 1e3 + 10;

PDD pdd[MAXN];
double a[MAXN], b[MAXN];
int n, d;

bool cmp( const PDD &a, const PDD &b ) {
    return a.first < b.first;
}

int main() {
    int tt = 0, ta, tb;
    while( ~scanf( "%d%d", &n, &d ) && n + d ) {
        printf( "Case %d: ", ++tt );
        bool flag = true;
        int cnt = 0;
        for( int i = 0; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            if( !flag ) continue;
            if( tb > d ) { flag = false; continue; }
            double tmp = sqrt( 1.0 * d * d - tb * tb );
            pdd[i].first = ta - tmp;
            pdd[i].second = ta + tmp;
        }
        if( !flag ) { puts( "-1" ); continue; }
        sort( pdd, pdd + n, cmp );
        double l, r;
        l = pdd[0].first; r = pdd[0].second;
        for( int i = 1; i < n; ++i ) {
            if( pdd[i].first <= r ) {
                l = pdd[i].first;
                r = min( r, pdd[i].second );
            } else {
                ++cnt;
                l = pdd[i].first;
                r = pdd[i].second;
            }
        }
        printf( "%d\n", cnt + 1 );
    }
    return 0;
}
