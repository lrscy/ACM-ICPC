#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int MAXM = 11;

char gc[MAXM][MAXM];
int dx[5] = { -1, 0, 1, 0 }, dy[5] = { 0, 1, 0, -1 };
int st[MAXM], mk[MAXM], rmk[MAXM], vis[MAXN][MAXN], vis2[MAXN], vis3[MAXN];
int g[MAXN][MAXN], state[MAXN], result[MAXN];
int n, m, tn, tnn, N, ans;

bool check( int x, int y ) { return ( 0 <= x && x < n && 0 <= y && y < m ); }

void mgao( int num ) {
    queue<int> q;
    q.push( num );
    memset( vis3, 0, sizeof vis3 );
    while( !q.empty() ) {
        int u = q.front(); q.pop();
        vis3[u] = 1;
        int x = u / m, y = u % m;
        for( int i = 0; i < 4; ++i ) {
            int tx = x + dx[i], ty = y + dy[i];
            if( check( tx, ty ) ) {
                if( gc[x][y] == gc[tx][ty] && !vis3[tx * m + ty] ) q.push( tx * m + ty );
                if( gc[tx][ty] == '.' ) vis2[tx * m + ty] = 1;
            }
        }
    }
    return ;
}

bool build( int mask ) {
    memset( vis2, 0, sizeof vis2 );
    memset( g, 0, sizeof g );
    tnn = 0;
    for( int i = 0; i < tn; ++i ) if( mask & ( 1 << i ) ) {
        for( int j = i + 1; j < tn; ++j ) if( mask & ( 1 << j ) )
            if( vis[i][j] ) return false;
    }
    for( int i = 0; i < tn; ++i ) {
        if( mask & ( 1 << i ) )
            mgao( st[rmk[i]] );
    }
    for( int i = 0; i < n; ++i ) {
        for( int j = 0; j < m; ++j ) {
            if( gc[i][j] == '.' && !vis2[i * m + j] ) {
                ++tnn;
                if( ( j & 1 ) == ( i & 1 ) ) {
                    for( int k = 0, x, y; k < 4; ++k ) {
                        x = i + dx[k]; y = j + dy[k];
                        if( check( x, y ) && gc[x][y] == '.' && !vis2[x * m + y] ) {
                            g[i * m + j][x * m + y] = 1;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool nfind( int u ) {
    for( int i = 0; i < N; ++i ) {
        if( g[u][i] == 1 && !state[i] ) {
            state[i] = 1;
            if( -1 == result[i] || nfind( result[i] ) ) {
                result[i] = u;
                return true;
            }
        }
    }
    return false;
}

int gao() {
    int tans = 0;
    memset( result, -1, sizeof result );
    for( int i = 0; i < N; ++i ) {
        memset( state, 0, sizeof state );
        if( nfind( i ) ) ++tans;
    }
    return tnn - tans;
}

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( vis, 0, sizeof vis );
        memset( rmk, 0, sizeof rmk );
        memset( mk, 0, sizeof mk );
        memset( st, -1, sizeof st );
        memset( g, 0, sizeof g );
        ans = 0;
        scanf( "%d%d", &n, &m );
        N = n * m;
        for( int i = 0; i < n; ++i ) {
            scanf( "%s", gc[i] );
            for( int j = 0; j < m; ++j ) {
                if( gc[i][j] != '.' )
                    st[gc[i][j] - '0'] = i * m + j;
            }
        }
        vector<int> vec;
        for( int i = 0; i < 10; ++i ) if( ~st[i] ) vec.push_back( i );
        for( int i = 0; i < vec.size(); ++i ) mk[vec[i]] = i, rmk[i] = vec[i];
        tn = vec.size();
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) if( gc[i][j] != '.' ) {
                for( int k = 0, x, y; k < 4; ++k ) {
                    x = i + dx[k]; y = j + dy[k];
                    if( check( x, y ) && gc[x][y] != '.' && gc[i][j] != gc[x][y] ) {
                        vis[mk[gc[x][y] - '0']][mk[gc[i][j] - '0']] = vis[mk[gc[i][j] - '0']][mk[gc[x][y] - '0']] = 1;
                    }
                }
            }
        }
        for( int s = 0; s < ( 1 << tn ); ++s ) {
            if( !build( s ) ) continue;
            int tans = gao() + __builtin_popcount( s );
            ans = max( ans, tans );
        }
        printf( "%d\n", ans );
    }
    return 0;
}
