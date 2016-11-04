#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1000 + 10;

int mat[MAXN][MAXN], v[MAXN], dis[MAXN];
bool vis[MAXN];
int n, m;

int SW() {
    int ret = INF;
    for( int i = 0; i <= n; ++i ) v[i] = i;
    while( n > 1 ) {
        int pre = 0;
        memset( vis, false, sizeof( vis ) );
        memset( dis, 0, sizeof( dis ) );
        for( int i = 1; i < n; ++i ) {
            int k = -1;
            for( int j = 1; j < n; ++j ) {
                if( !vis[v[j]] ) {
                    dis[v[j]] += mat[v[pre]][v[j]];
                    if( k == -1 || dis[v[k]] < dis[v[j]] ) k = j;
                }
            }
            vis[v[k]] = true;
            if( i == n - 1 ) {
                ret = min( ret, dis[v[k]] );
                for( int j = 0; j < n; ++j ) {
                    mat[v[pre]][v[j]] = ( mat[v[j]][v[pre]] += mat[v[j]][v[k]] );
                }
                v[k] = v[--n];
            }
            pre = k;
        }
    }
    return ret;
}

int main() {
    int a, b, c;
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( mat, 0, sizeof( mat ) );
        while( m-- ) {
            scanf( "%d%d%d", &a, &b, &c );
            mat[a][b] = ( mat[b][a] += c );
        }
        printf( "%d\n", SW() );
    }
    return 0;
}
