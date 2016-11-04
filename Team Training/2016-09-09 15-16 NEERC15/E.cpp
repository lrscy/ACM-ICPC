#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;

int sc[MAXN][MAXN], p[MAXN];
int n, m;

int main() {
//    freopen( "easy.in", "r", stdin );
//    freopen( "easy.out", "w+", stdout );
    int nmax = 0;
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", p + i );
        nmax = max( nmax, p[i] );
        for( int j = 1; j <= p[i]; ++j ) {
            scanf( "%d", &sc[i][j] );
        }
    }
    int sum = 0, cnt = 0;
    bool flag = false;
    for( int j = 1; j <= nmax && !flag; ++j ) {
        for( int i = 1; i <= n && !flag; ++i ) {
            if( p[i] < j ) {
                sum += 50;
                ++cnt;
                if( cnt >= m ) flag = true;
                continue;
            }
            if( sc[i][j] >= sum ) {
                sum += sc[i][j];
                ++cnt;
                if( cnt >= m ) flag = true;
            }
        }
    }
    if( cnt < m ) sum += ( m - cnt ) * 50;
    printf( "%d\n", sum );
    return 0;
}
