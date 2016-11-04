#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 10;

struct Edge { int to, next, cost; };
Edge es[MAXN << 1];
struct Node { int u, pre, num, dis; };
queue<Node> que;
int head[MAXN], dp[MAXN][MAXN], pre[MAXN][MAXN], road[MAXN];
int n, m, t, cnt, tot;

void add( int u, int v, int w ) { es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++; }

void dfs( int u, int num, int ti, int fa ) {
    if( dp[u][num] <= ti ) return ;
    dp[u][num] = ti; pre[u][num] = fa;
    for( int i = head[u]; ~i; i = es[i].next ) {
        if( ti + es[i].cost <= t ) 
            dfs( es[i].to, num + 1, ti + es[i].cost, u );
    }
}

int main() {
    memset( head, -1, sizeof head ); cnt = 0;
    memset( dp, 0x3F, sizeof dp );
    memset( pre, -1, sizeof pre );
    scanf( "%d%d%d", &n, &m, &t );
    for( int i = 0, u, v, w; i < m; ++i ) { scanf( "%d%d%d", &u, &v, &w ); add( u, v, w ); }
    dfs( 1, 1, 0, -1 );
    int u = n, num = 0;
    for( int i = n; i; --i ) if( dp[n][i] <= t ) { num = i; break; }
    printf( "%d\n", num );
    while( ~u ) {
        road[tot++] = u;
        u = pre[u][num--];
    }
    for( int i = tot - 1; i >= 0; --i ) printf( "%d%c", road[i], i ? ' ' : '\n' );
    return 0;
}
