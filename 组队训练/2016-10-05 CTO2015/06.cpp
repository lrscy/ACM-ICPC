#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 1e4 + 10;

int a[5][MAXN];
vector<LL> tv[2];
int n, n1, n2, n3, n4;

int main() {
    while( ~scanf( "%d%d%d%d%d", &n, &n1, &n2, &n3, &n4 ) && n && n1 && n2 && n3 && n4 ) {
        tv[0].clear(); tv[1].clear();
        for( int i = 0, t; i < n1; ++i ) scanf( "%d", &a[0][i] );
        for( int i = 0, t; i < n2; ++i ) scanf( "%d", &a[1][i] );
        for( int i = 0, t; i < n3; ++i ) scanf( "%d", &a[2][i] );
        for( int i = 0, t; i < n4; ++i ) scanf( "%d", &a[3][i] );
        for( int i = 0; i < n1; ++i ) {
            for( int j = 0; j < n2; ++j )
                if( a[0][i] + a[1][j] <= n ) tv[0].push_back( a[0][i] + a[1][j] );
        }
        for( int i = 0; i < n3; ++i ) {
            for( int j = 0; j < n4; ++j )
                if( a[2][i] + a[3][j] <= n ) tv[1].push_back( a[2][i] + a[3][j] );
        }
        sort( tv[1].begin(), tv[1].end() );
        LL ans = 0;
        for( int i = 0; i < tv[0].size(); ++i ) {
            int tmp = upper_bound( tv[1].begin(), tv[1].end(), n - tv[0][i] ) - tv[1].begin();
            ans += tmp;
        }
        printf( "%lld\n", ans );
    }
    return 0;
}
