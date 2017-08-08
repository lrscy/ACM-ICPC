#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

vector<int> vec[MAXN];
queue<int> que;
int col[MAXN];
bool vis[MAXN];
int n, m, x, y;

bool bfs( int i ) {
    queue<int> q;
    q.push( i );
    vis[i] = true;
    while( !q.empty() ) {
        int u = q.front(); q.pop();
        int len = vec[u].size();
        for( int i = 0; i < len; ++i ) {
            int v = vec[u][i];
            if( vis[v] ) continue;
            if( col[v] == col[u] ) return false;
            if( col[v] == 2 ) col[v] = 1 - col[u];
            q.push( v );
            vis[v] = true;
        }
    }
    return true;
}

int main() {
    while( ~scanf( "%d%d%d%d", &n, &m, &x, &y ) ) {
        for( int i = 0; i < n; ++i ) vec[i].clear();
        memset( vis, false, sizeof vis );
        memset( col, -1, sizeof col );
        while( !que.empty() ) que.pop();
        for( int i = 0, a, b; i < m; ++i ) {
            scanf( "%d%d", &a, &b );
            vec[a].push_back( b );
            vec[b].push_back( a );
            col[a] = col[b] = 2;
        }
        for( int i = 0, tmp; i < x; ++i ) {
            scanf( "%d", &tmp );
            col[tmp] = 1;
            que.push( tmp );
        }
        for( int i = 0, tmp; i < y; ++i ) {
            scanf( "%d", &tmp );
            col[tmp] = 0;
            que.push( tmp );
        }
        bool flag = true;
        for( int i = 1; i <= n; ++i ) if( col[i] == -1 ) { flag = false; break; }
        if( !flag ) { puts( "NO" ); continue; }
        for( int i = 1; i <= n && flag; ++i ) {
            if( !vis[i] && col[i] != 2 && !bfs( i ) )
                flag = false;
        }
        for( int i = 1; i <= n && flag; ++i ) if( !vis[i] ) {
            if( col[i] == 2 ) {
                col[i] = 1;
                if( !bfs( i ) ) flag = false;
            }
        }
        if( !flag ) puts( "NO" );
        else puts( "YES" );
    }
    return 0;
}
