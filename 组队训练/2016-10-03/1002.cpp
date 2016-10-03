#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x3F3F3F3F;
const int MAXN = 200 + 10;
const int MAXM = 1e3 + 10;

char g[MAXN][MAXN];
int dis[MAXN][MAXN], dx[5] = { -1, 0, 1, 0 }, dy[5] = { 0, 1, 0, -1 };
vector<int> vs;
int n, m, p, ed, nmin;

bool chk( int x, int y ) { return ( 0 <= x && x < n && 0 <= y && y < m ); }

void bfs( int st ) {
    int x, y, mf, me;
    queue<int> que;
    que.push( st );
    x = st / m; y = st % m;
    dis[x][y] = 0;
    while( !que.empty() ) {
        int u = que.front(); que.pop();
        x = u / m; y = u % m;
        if( g[x][y] == '$' ) nmin = min( nmin, dis[x][y] );
        if( g[x][y] == '@' ) p = min( p, dis[x][y] );
        for( int i = 0; i < 4; ++i ) {
            int tx = x + dx[i], ty = y + dy[i];
            if( chk( tx, ty ) && g[tx][ty] != '#' && dis[tx][ty] > dis[x][y] + 1 ) {
                dis[tx][ty] = dis[x][y] + 1;
                que.push( tx * m + ty );
            }
        }
    }
    return ;
}

int main() {
    p = nmin = INF;
    memset( dis, 0x3F, sizeof dis );
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < n; ++i ) {
        scanf( "%s", g + i );
        for( int j = 0; j < m; ++j ) {
            if( g[i][j] == '%' ) ed = i * m + j;
        }
    }
    bfs( ed );
    if( p < nmin ) puts( "Yes" );
    else puts( "No" );
    return 0;
}
