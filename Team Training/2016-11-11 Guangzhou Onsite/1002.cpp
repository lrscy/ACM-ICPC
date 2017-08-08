#include <bits/stdc++.h>
typedef std::pair<int, int> PII;
const int MAXN = 110;
const int MAXM = 3e4 + 10;

struct Rect { PII p1, p2; };
Rect rect[MAXM];
PII pii[MAXN];
int n;

inline bool chk( int a, int b, int c, int d ) {
    if( ( a < c && b < c ) || ( a > d && b > d ) ) return false;
    return true;
}

int judge( const Rect &a, const Rect &b ) {
    int x1 = a.p1.first, y1 = a.p1.second, x2 = a.p2.first, y2 = a.p2.second;
    int x3 = b.p1.first, y3 = b.p1.second, x4 = b.p2.first, y4 = b.p2.second;
    if( x1 < x3 && x4 < x2 && y1 < y3 && y4 < y2 ) return 2;
    if( x3 < x1 && x2 < x4 && y3 < y1 && y2 < y4 ) return 3;
    if( chk( x1, x2, x3, x4 ) && chk( y1, y2, y3, y4 ) ) return 0;
    return 1;
}

int area( const Rect &a ) {
    int x1 = a.p1.first, y1 = a.p1.second, x2 = a.p2.first, y2 = a.p2.second;
    return ( x2 - x1 ) * ( y2 - y1 );
}

int main() {
    while( ~scanf( "%d", &n ) && n ) {
        int tot = 0;
        for( int i = 0; i < n; ++i ) scanf( "%d%d", &pii[i].first, &pii[i].second );
        std::sort( pii, pii + n );
        for( int i = 0; i < n; ++i ) {
            for( int j = i + 1; j < n; ++j ) {
                int x1, x2, y1, y2;
                x1 = pii[i].first; y1 = pii[i].second;
                x2 = pii[j].first; y2 = pii[j].second;
                if( x1 == x2 || y1 == y2 ) continue;
                PII tpii[5];
                int cnt = 0;
                for( int k = 0; k < n; ++k ) {
                    if( k == i || k == j ) continue;
                    if( x1 == pii[k].first && y2 == pii[k].second ) tpii[cnt++] = pii[k];
                    if( x2 == pii[k].first && y1 == pii[k].second ) tpii[cnt++] = pii[k];
                }
                if( cnt == 2 ) {
                    tpii[cnt++] = pii[i]; tpii[cnt++] = pii[j];
                    std::sort( tpii, tpii + 4 );
                    rect[tot].p1 = tpii[0]; rect[tot].p2 = tpii[3];
                    ++tot;
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < tot; ++i ) {
            for( int j = i + 1; j < tot; ++j ) {
                int tmp = judge( rect[i], rect[j] );
                if( tmp == 1 ) ans = std::max( ans, area( rect[i] ) + area( rect[j] ) );
                else if( tmp == 2 ) ans = std::max( ans, area( rect[i] ) );
                else if( tmp == 3 ) ans = std::max( ans, area( rect[j] ) );
            }
        }
        if( ans == 0 ) puts( "imp" );
        else printf( "%d\n", ans );
    }
    return 0;
}
