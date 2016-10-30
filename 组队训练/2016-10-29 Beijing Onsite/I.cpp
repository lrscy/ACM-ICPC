#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
typedef pair<int, int> PII;

vector<PII> vec[MAXN];
int n, w, h;

int main() {
    while( ~scanf( "%d", &n ) ) {
        for( int i = 0; i <= n; ++i ) vec[i].clear();
        w = ( n + 1 ) / 2; h = n + !( n & 1 );
        for( int i = 1; i <= n; i += 2 ) {
            for( int j = 1; j <= i / 2; ++j ) vec[i].push_back( PII( i / 2 + 1, j ) );
            vec[i].push_back( PII( i / 2 + 1, i / 2 + 1 ) );
            for( int j = i / 2; j >= 1; --j ) vec[i].push_back( PII( j, i / 2 + 1 ) );
        }
        int x = w, y = h, flag = -1;
        if( w & 1 ) {
            for( int i = 2; i <= n; i += 2 ) {
                if( i % 4 ) {
                    for( int j = 0; j < i / 2; ++j ) vec[i].push_back( PII( x, y ) ), ++x;
                    if( x > w ) { x = w; --y; }
                    for( int j = 0; j < i / 2; ++j ) vec[i].push_back( PII( x, y ) ), --x;
                } else {
                    for( int j = 0; j < i / 2; ++j ) vec[i].push_back( PII( x, y ) ), ++y;
                    if( y > h ) { y = h; --x; }
                    for( int j = 0; j < i / 2; ++j ) vec[i].push_back( PII( x, y ) ), --y;
                }
            }
        } else {
            for( int i = 2; i <= n; i += 2 ) {
                if( i % 4 ) {
                    for( int j = 0; j < i / 2; ++j ) vec[i].push_back( PII( x, y ) ), ++y;
                    if( y > h ) { y = h; --x; }
                    for( int j = 0; j < i / 2; ++j ) vec[i].push_back( PII( x, y ) ), --y;
                } else {
                    for( int j = 0; j < i / 2; ++j ) vec[i].push_back( PII( x, y ) ), ++x;
                    if( x > w ) { x = w; --y; }
                    for( int j = 0; j < i / 2; ++j ) vec[i].push_back( PII( x, y ) ), --x;
                }
            }
        }
        printf( "%d %d\n", w, h );
        for( int i = 1; i <= n; ++i ) {
            int len = vec[i].size();
            printf( "%d %d", vec[i][0].first, vec[i][0].second );
            for( int j = 1; j < len; ++j ) printf( " %d %d", vec[i][j].first, vec[i][j].second );
            puts( "" );
        }
    }
    return 0;
}
