#include <bits/stdc++.h>
using namespace std;
const int INF = 0x1F1F1F;
const int MAXN = 1e3 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXN << 2];
int head[MAXN], dp[MAXN];
int n, m, cnt;

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u, int fa, int upper ) {
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fa ) continue;
        dfs( v, u, upper );
        if( es[i].cost > upper ) dp[u] += dp[v];
        else dp[u] += min( dp[v], es[i].cost );
    }
    if( dp[u] == 0 ) dp[u] = INF;
    return ;
}

int main() {
    int ta, tb, tc;
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        memset( head, -1, sizeof( head ) );
        cnt = 0;
        for( int i = 1; i < n; ++i ) {
            scanf( "%d%d%d", &ta, &tb, &tc );
            add( ta, tb, tc ); add( tb, ta, tc );
        }
        int low = 1, high = MAXN;
        while( low < high ) {
            memset( dp, 0, sizeof( dp ) );
            int mid = ( low + high ) >> 1;
            dfs( 1, -1, mid );
            if( dp[1] <= m ) high = mid;
            else low = mid + 1;
        }
        if( low >= MAXN ) puts( "-1" );
        else printf( "%d\n", low );
    }
    return 0;
}
