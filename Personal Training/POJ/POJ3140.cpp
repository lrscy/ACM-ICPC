#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const LL LINF = 0x3F3F3F3F3F3F3F3F;
const int MAXN = 1e5 + 10;
const int MAXM = 1e6 + 10;

struct Edge { int to, next; };
Edge es[MAXM << 2];
int head[MAXN];
bool vis[MAXN];
LL son[MAXN];
LL ans, sum;
int n, m, cnt;

LL mabs( LL a ) { return a < 0 ? -a : a; }

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void dfs( int u ) {
    vis[u] = true;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( vis[v] ) continue;
        dfs( v );
        son[u] += son[v];
    }
    ans = min( ans, mabs( son[u] - ( sum - son[u] ) ) );
    return ;
}

int main() {
    int ncas = 1, ta, tb;
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        memset( vis, false, sizeof( vis ) );
        memset( head, -1, sizeof( head ) );
        sum = 0; cnt = 0; ans = LINF;
        for( int i = 1; i <= n; ++i ) {
            scanf( "%lld", son + i );
            sum += son[i];
        }
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d", &ta, &tb );
            add( ta, tb ); add( tb, ta );
        }
        dfs( 1 );
        printf( "Case %d: %lld\n", ncas++, ans );
    }
    return 0;
}
