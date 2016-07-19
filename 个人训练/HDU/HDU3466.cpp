#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;

struct Node { int p, q, v; };
Node nodes[MAXN];
int dp[MAXN];
int n, m;

bool cmp( const Node &a, const Node &b ) {
    return a.q - a.p < b.q - b.p;
}

int main() {
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( dp, 0, sizeof( dp ) );
        for( int i = 0; i < n; ++i ) {
            scanf( "%d%d%d", &nodes[i].p, &nodes[i].q, &nodes[i].v );
        }
        sort( nodes, nodes + n, cmp );
        for( int i = 0; i < n; ++i ) {
            for( int j = m; j >= nodes[i].q; --j )
                dp[j] = max( dp[j], dp[j - nodes[i].p] + nodes[i].v );
        }
        printf( "%d\n", dp[m] );
    }
    return 0;
}
