#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;

int nmap[305][305];
int lx[305],ly[305];
bool x[305],y[305];
int link[305];
int n;  // n可能要改成n, m

bool dfs( int u ) {
    int i;
    x[u] = true;
    for( i = 1; i <= n; ++i ) {
        if( lx[u] + ly[i] == nmap[u][i] && !y[i] ) {
            y[i] = true;
            if( link[i] == -1 || dfs( link[i] ) ) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}

void KM() {
    int i, j, k;
    memset( x, 0, sizeof( x ) );
    memset( y, 0, sizeof( y ) );
    memset( link, -1, sizeof( link ) );
    for( i = 1; i <= n; ++i ) lx[i] = INF;
    memset( ly, 0, sizeof( ly ) );
    for( k = 1; k <= n; ++k ) {
        while( true ) {
            memset( x, 0, sizeof( x ) );
            memset( y, 0, sizeof( y ) );
            if( dfs( k ) ) break;
            int d = INF;
            for( i = 1; i <= n; ++i ) {
                if( x[i] )
                    for( j = 1; j <= n; ++j )
                        if( !y[j] && lx[i] + ly[j] - nmap[i][j] < d )
                            d = lx[i] + ly[j] - nmap[i][j];
            }
            for( i = 1; i <= n; ++i ) if( x[i] ) lx[i] = lx[i] - d;
            for( i = 1; i <= n; ++i ) if( y[i] ) ly[i] = ly[i] + d;
        }
    }
    return ;
}

int main() {
    int i, j, k;
    while( ~scanf( "%d", &n ) ) {
        // nmap可能要初始化，求最小值时清成-INF即0x80808080
        for( i = 1; i <= n; ++i )
            for( j = 1; j <= n; ++j )
                scanf( "%d", &nmap[i][j] );
        KM();
        int ans = 0;
        for( i = 1; i <= n; ++i ) ans = ans + nmap[link[i]][i];
        printf( "%d\n", ans );
    }
    return 0;
}
