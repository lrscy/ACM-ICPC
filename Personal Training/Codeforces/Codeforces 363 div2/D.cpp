#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int a[MAXN], b[MAXN], vis[MAXN];
int n, root;

void gao( int u ) {
    vis[u] = 1;
    if( !vis[b[u]] ) gao( b[u] );
    else if( vis[b[u]] == 1 ) {
        if( root == -1 ) { root = u; b[u] = root; }
        else b[u] = root;
        vis[u] = 2;
    }
    vis[u] = 2;
    return ;
}

int main() {
    int cnt = 0;
    memset( vis, 0, sizeof( vis ) );
    scanf( "%d", &n );
    root = -1;
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", a + i );
        b[i] = a[i];
        if( a[i] == i ) root = i;
    }
    for( int i = 1; i <= n; ++i ) if( !vis[i] ) gao( i );
    for( int i = 1; i <= n; ++i ) if( a[i] != b[i] ) ++cnt;
    printf( "%d\n", cnt );
    for( int i = 1; i < n; ++i ) printf( "%d ", b[i] );
    printf( "%d\n", b[n] );
    return 0;
}
