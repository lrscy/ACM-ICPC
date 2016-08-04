#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 2e2 + 10;

struct Edge { int to, next; };
Edge es[MAXN << 2];
int head[MAXN], dp[MAXN][MAXN], val[MAXN], son[MAXN];
bool vis[MAXN];
map<string, int> mp;
int n, m, cnt, tot;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u ) {
    dp[u][0] = 0;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        dfs( v );
        son[u] += son[v];
        for( int j = son[u]; j >= 0; --j ) {
            for( int k = 0; k <= j && k <= son[v]; ++k )
                dp[u][j] = min( dp[u][j], dp[u][j - k] + dp[v][k] );
        }
    }
    ++son[u];
    dp[u][son[u]] = val[u];
    return ;
}

int main() {
    int ta;
    char sa[MAXN], sb[MAXN], str[MAXN * MAXN];
    while( NULL != fgets( str, MAXN, stdin ) && str[0] != '#' ) {
        memset( vis, false, sizeof( vis ) );
        memset( head, -1, sizeof( head ) );
        memset( dp, 0x3F, sizeof( dp ) );
        memset( son, 0, sizeof( son ) );
        cnt = 0; tot = 1; mp.clear();
        sscanf( str, "%d%d", &n, &m );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%s%d", sa, &ta );
            if( !mp[sa] ) mp[sa] = tot++;
            val[mp[sa]] = ta;
            while( getchar() != '\n' ) {
                scanf( "%s", sb );
                if( !mp[sb] ) mp[sb] = tot++;
                add( mp[sa], mp[sb] );
                vis[mp[sb]] = true;
            }
        }
        int ans = INF;
        for( int i = 1; i <= n; ++i ) if( !vis[i] ) add( 0, i );
        dfs( 0 );
        for( int i = m; i <= n; ++i ) ans = min( ans, dp[0][i] );
        printf( "%d\n", ans );
    }
    return 0;
}
