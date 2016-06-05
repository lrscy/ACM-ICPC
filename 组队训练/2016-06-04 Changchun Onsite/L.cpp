#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100 + 10;

int a[MAXN][MAXN];
int n, m;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( a, 0, sizeof( a ) );
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) {
            for( int j = 1; j <= m; ++j )
                scanf( "%d", &a[i][j] );
        }
        int ans = 0;
        for( int i = 1; i <= n; ++i ) {
            for( int j = 1; j <= m; ++j ) {
                int tmp = a[i][j] > 0;
                int t1 = a[i][j] - a[i - 1][j];
                int t2 = a[i][j] - a[i + 1][j];
                int t3 = a[i][j] - a[i][j - 1];
                int t4 = a[i][j] - a[i][j + 1];
                t1 = t1 >= 0 ? t1 : 0;
                t2 = t2 >= 0 ? t2 : 0;
                t3 = t3 >= 0 ? t3 : 0;
                t4 = t4 >= 0 ? t4 : 0;
                tmp += t1 + t2 + t3 + t4;
                ans += tmp;
            }
        }
        printf( "%d\n", ans );
    }
    return 0;
}
