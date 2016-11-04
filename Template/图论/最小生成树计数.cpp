#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
const int MAXE = 100000 + 10;

struct Edge { int u, v, w; };
Edge es[MAXE];
int fa[MAXN], ka[MAXN];
LL g[MAXN][MAXN], c[MAXN][MAXN];
bool vis[MAXN];
int n, m, mod;
vector<int> vec[MAXN];

int mfind( int x, int *f ) {
    return x == f[x] ? x : f[x] = mfind( f[x], f );
}

LL det( LL a[][MAXN], int n ) {
    for( int i = 0; i < n; ++i ) {
        for( int j = 0; j < n; ++j )
            a[i][j] %= mod;
    }
    int ret = 1;
    for( int i = 1; i < n; ++i ) {
        for( int j = i + 1; j < n; ++j ) {
            while( a[j][i] ) {
                LL t = a[i][i] / a[j][i];
                for( int k = i; k < n; ++k )
                    a[i][k] = ( a[i][k] - a[j][k] * t ) % mod;
                for( int k = i; k < n; ++k )
                    swap( a[i][k], a[j][k] );
                ret = -ret;
            }
        }
        if( a[i][i] == 0 ) return 0;
        ret = ( ret * a[i][i] ) % mod;
    }
    return ( ret + mod ) % mod;
}

bool cmp( const Edge &a, const Edge &b ) {
    return a.w < b.w;
}

void gao() {
    sort( es, es + m, cmp );
    for( int i = 1; i <= n; ++i ) { fa[i] = i; vis[i] = false; }
    LL pre = -1, ans = 1;
    for( int k = 0; k <= m; ++k ) {
        if( es[k].w != pre || k == m ) {
            for( int i = 1; i <= n; ++i ) {
                if( vis[i] ) {
                    LL u = mfind( i, ka );
                    vec[u].push_back( i );
                    vis[i] = false;
                }
            }
            for( int i = 1; i <= n; ++i ) {
                if( vec[i].size() > 1 ) {
                    memset( c, 0, sizeof( c ) );
                    int len = vec[i].size();
                    for( int j = 0; j < len; ++j ) {
                        for( int k = j + 1; k < len; ++k ) {
                            int a1 = vec[i][j], b1 = vec[i][k];
                            c[j][k] = ( c[k][j] -= g[a1][b1] );
                            c[j][j] += g[a1][b1]; c[k][k] += g[a1][b1];
                        }
                    }
                    LL ret = det( c, len );
                    ans = ( ans * ret ) % mod;
                    for( int j = 0; j < len; ++j ) fa[vec[i][j]] = i;
                }
            }
            for( int i = 1; i <= n; ++i ) {
                ka[i] = fa[i] = mfind( i, fa );
                vec[i].clear();
            }
            if( k == m ) break;
            pre = es[k].w;
        }
        int u = es[k].u, v = es[k].v;
        int a1 = mfind( u, fa ), b1 = mfind( v, fa );
        if( a1 == b1 ) continue;
        vis[a1] = vis[b1] = true;
        ka[mfind( a1, ka )] = mfind( b1, ka );
        ++g[a1][b1]; ++g[b1][a1];
    }
    bool flag = false;
    for( int i = 2; i <= n && !flag; ++i ) {
        if( ka[i] != ka[i - 1] ) flag = true;
    }
    if( !m ) flag =  true;
    printf( "%I64d\n", flag ? 0 : ans % mod );
    return ;
}

int main() {
    while( ~scanf( "%d%d%d", &n, &m, &mod ) && n + m + mod ) {
        memset( g, 0, sizeof( g ) );
        for( int i = 1; i <= n; ++i ) vec[i].clear();
        for( int i = 0; i < m; ++i ) scanf( "%d%d%d", &es[i].u, &es[i].v, &es[i].w );
        gao();
    }
    return 0;
}
