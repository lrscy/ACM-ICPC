#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Edge { int to, next; };
Edge es[MAXN << 2];
map<int, int> mp;
int head[MAXN], dep[MAXN], fa[MAXN], a[MAXN], du[MAXN];
bool vis[MAXN];
int n, m, cnt, ans;

void add( int u, int v ) { es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++; }

void dfs( int u, int fu, int d ) {
    fa[u] = fu; dep[u] = d;
    for( int i = head[u]; ~i; i = es[i].next ) {
        int v = es[i].to;
        if( v == fu ) continue;
        dfs( v, u, d + 1 );
    }
}

bool cmp( const int &a, const int &b ) { return dep[a] > dep[b]; }

int main() {
    int t, tn;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        memset( head, -1, sizeof head ); cnt = 0;
        printf( "Case #%d:\n", ncas );
        scanf( "%d%d", &n, &m );
        for( int i = 1, u, v; i < n; ++i ) {
            scanf( "%d%d", &u, &v );
            add( u, v ); add( v, u );
        }
        dfs( 1, 0, 0 );
        while( m-- ) {
            mp.clear(); ans = 0;
            scanf( "%d", &tn );
            for( int i = 0, tm; i < tn; ++i ) scanf( "%d", a + i ), mp[a[i]] = 1;
            sort( a, a + tn, cmp );
            for( int i = 0; i < tn; ++i ) {
                du[a[i]] = 0;
                for( int j = head[a[i]]; ~j; j = es[j].next ) {
                    int v = es[j].to;
                    if( v == fa[a[i]] ) continue;
                    if( mp[v] == 0 ) ++du[a[i]];
                    else if( du[v] > 0 ) ++du[a[i]];
                    if( du[a[i]] > 1 ) break;
                }
                if( du[a[i]] <= 1 ) ++ans;
                else mp[a[i]] = 0;
            }
            printf( "%d\n", n - ans );
        }
    }
    return 0;
}
