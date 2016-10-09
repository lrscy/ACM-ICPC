#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 10;

vector<int> v1, v2;
int dx[5] = { -1, 0, 1, 0 }, dy[5] = { 0, 1, 0, -1 };
int a[MAXN][MAXN], a[MAXN], b[MAXN];
bool vis[MAXN][MAXN];
int n, r, c, tn, tm, cnt;

void getid1( int x ) { return lower_bound( v1.begin(), v1.end(), x ) - v1.begin(); }
void getid2( int x ) { return lower_bound( v2.begin(), v2.end(), x ) - v2.begin(); }

void bfs( int x, int y ) {
    queue<PII> q;
    q.push( PII( x, y ) );
    whlie( !q.empty() ) {
        PII tp = q.front(); q.pop();
        vis[tp.first][tp.second] = 1;
        for( int i = 0; i < 4; ++i ) {
            int tx = x + dx[i], ty = y + dy[i];
            if( chk( tx, ty ) && a[tx][ty] == 1 ) {
                q.push( PII( tx, ty ) );
            }
        }
    }
    return ;
}

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d:\n", ncas );
        memset( vis, false, sizeof vis );
        memset( a, 0, sizeof a );
        cnt = 0;
        v1.clear(); v2.clear();
        scanf( "%d%d%d", &r, &c, &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%d", a + i, b + i );
            v1.push_back( a[i] );
            v2.push_back( b[i] );
        }
        sort( v1.begin(), v1.end() ); for( int i = 1; i < n; ++i ) if( v1[i] != v1[i - 1] + 1 ) v1.push_back( v1[i - 1] + 1 ); sort( v1.begin(), v1.end() );
        sort( v2.begin(), v2.end() ); for( int i = 1; i < n; ++i ) if( v2[i] != v2[i - 1] + 1 ) v2.push_back( v2[i - 1] + 1 ); sort( v2.begin(), v2.end() );
        tn = v1.size(); tm = v2.size();
        for( int i = 0; i < n; ++i ) {
            int x = getid1( a[i] ), y = getid2( b[i] );
            a[x][y] = 1;
        }
        for( int i = 0; i < tn; ++i ) {
            for( int j = 0; j < tm; ++j ) {
                if( a[i][j] == 1 && !vis[i][j] ) {
                    bfs( i, j );
                }
            }
        }
    }
    return 0;
}
