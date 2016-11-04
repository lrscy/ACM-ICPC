#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 10;

struct Node { int x, y, sum; };
Node node[MAXN * MAXN];
int dx[5] = { -1, 0, 1, 0 }, dy[5] = { 0, 1, 0, -1 };
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, k, tot;

bool cmp( const Node &a, const Node &b ) { return a.sum < b.sum; }

bool chk( int x, int y ) { return ( 0 <= x && x < n && 0 <= y && y < m ); }

int gao( int x, int y, bool flag ) {
    int ret = 0;
    bool tflag = true;
    queue<PII> que;
    que.push( PII( x, y ) );
    while( !que.empty() ) {
        PII tp = que.front(); que.pop();
        int cx = tp.first, cy = tp.second;
        vis[cx][cy] = true; ++ret;
        if( flag ) a[cx][cy] = '*';
        for( int i = 0; i < 4; ++i ) {
            int tx = cx + dx[i], ty = cy + dy[i];
            if( !chk( tx, ty ) ) tflag = false;
            else if( a[tx][ty] == '.' && !vis[tx][ty] ) {
                que.push( PII( tx, ty ) );
                vis[tx][ty] = true;
            }
        }
    }
    return ( tflag ? ret : 0 );
}

int main() {
    memset( vis, false, sizeof vis ); tot = 0;
    scanf( "%d%d%d", &n, &m, &k );
    for( int i = 0; i < n; ++i ) scanf( "%s", a + i );
    for( int i = 0; i < n; ++i ) {
        for( int j = 0, tmp; j < m; ++j )
            if( a[i][j] == '.' && !vis[i][j] )
                if( tmp = gao( i, j, false ) )
                    node[tot++] = Node{ i, j, tmp };
    }
    sort( node, node + tot, cmp );
    memset( vis, false, sizeof vis );
    int sum = 0;
    k = tot - k;
    for( int i = 0; i < k; ++i ) sum += gao( node[i].x, node[i].y, true );
    printf( "%d\n", sum );
    for( int i = 0; i < n; ++i ) printf( "%s\n", a[i] );
    return 0;
}
