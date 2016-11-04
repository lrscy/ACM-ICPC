#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 100 + 10;
const int MAXM = 1e9 + 10;

struct Node {
    int t, g;
    bool operator < ( const Node &tmp ) const {
        if( g == tmp.g ) return t > tmp.t;
        return g < tmp.g;
    }
} nodes[MAXN], cur, nxt;
vector<int> g[MAXN], gr[MAXN];
priority_queue<Node> pq1, pq2;
bool vis[MAXN];
int n, m, t, gn;

void dfs( int u ) {
    vis[u] = true;
    gr[gn].push_back( u );
    for( int i = 0; i < g[u].size(); ++i ) {
        if( !vis[g[u][i]] ) dfs( g[u][i] );
    }
    return ;
}

void init() {
    memset( vis, false, sizeof( vis ) );
    gn = 1;
    for( int i = 1; i <= n; ++i ) if( !vis[i] ) {
        dfs( i );
        ++gn;
    }
    return ;
}

int gao() {
    int nmin = INF;
    for( int i = 1; i <= gn; ++i ) {
        while( !pq1.empty() ) pq1.pop();
        while( !pq2.empty() ) pq2.pop();
        cur.t = cur.g = 0;
        pq1.push( cur );
        for( int j = 0; j < gr[i].size(); ++j ) {
            int tmp = gr[i][j];
            while( !pq1.empty() ) {
                cur = pq1.top(); pq1.pop();
                pq2.push( cur );
                nxt.t = cur.t + nodes[tmp].t;
                nxt.g = cur.g + nodes[tmp].g;
                if( nxt.g >= m ) { nmin = min( nmin, nxt.t ); continue; }
                if( nxt.t >= nmin ) continue;
                pq2.push( nxt );
            }
            tmp = INF;
            while( !pq2.empty() ) {
                cur = pq2.top(); pq2.pop();
                if( tmp >= cur.t ) { pq1.push( cur ); tmp = cur.t; }
            }
        }
    }
    return nmin == INF ? -1 : nmin;
}

int main() {
    int tt, tmp, cnt;
    scanf( "%d", &tt );
    for( int ncas = 1; ncas <= tt; ++ncas ) {
        for( int i = 0; i < MAXN; ++i ) { g[i].clear(); gr[i].clear(); }
        printf( "Case %d: ", ncas );
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d%d%d", &nodes[i].t, &nodes[i].g, &cnt );
            for( int j = 0; j < cnt; ++j ) {
                scanf( "%d", &tmp );
                g[i].push_back( tmp );
                g[tmp].push_back( i );
            }
        }
        init();
        int ans = gao();
        if( ~ans ) printf( "%d\n", ans );
        else puts( "Poor Magina, you can't save the world all the time!" );
    }
    return 0;
}
