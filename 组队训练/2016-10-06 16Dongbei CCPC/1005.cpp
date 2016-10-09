#include <bits/stdc++.h>
using namespace std;

int a[50][50];
int n, m;

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j )
                scanf( "%d", &a[i][j] );
        }
        bool flag = false;
        for( int i = 1; i < n && !flag; ++i ) {
            for( int j = 1; j < n && !flag; ++j )
                if( a[i][j] == a[i -1][j] || a[i][j] == a[i][j - 1] )
                    flag = true;
        }
        for( int i = 0; i < m && !flag; ++i ) {
            for( int j = i + 1; j < m && !flag; ++j )
                if( a[0][i] == a[0][j] || a[n - 1][i] == a[n - 1][j] )
                    flag = true;
        }
        for( int i = 0; i < n && !flag; ++i ) {
            for( int j = i + 1; j < n && !flag; ++j )
                if( a[i][0] == a[j][0] || a[i][m - 1] == a[j][m - 1] )
                    flag = true;
        }
        puts( flag ? "Yes" : "No" );
    }
    return 0;
}
