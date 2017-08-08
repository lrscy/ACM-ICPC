#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x3F3F3F3F;
const int MAXN = 100 + 10;
const int MAXM = 1e4 + 10;

struct Edge { int to, next, cost, flag; };
Edge es[MAXM];
int head[MAXN], d[MAXN];
int n, m, cnt;

void add( int u, int v, int c ) {
    es[cnt].to = v; es[cnt].cost = c; es[cnt].next = head[u];
    es[cnt].flag = true; head[u] = cnt++;
}

int dij() {
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    for( int i = 1; i <= n; ++i ) d[i] = INF;
    d[1] = 0;
    pq.push( PII( 0, 1 ) );
    while( !pq.empty() ) {
        PII p = pq.top(); pq.pop();
        int u = p.second;
        if( d[u] < p.first ) continue;
        for( int i = head[u]; ~i; i = es[i].next ) if( es[i].flag ) {
            int v = es[i].to;
            if( d[v] > d[u] + es[i].cost ) {
                d[v] = d[u] + es[i].cost;
                pq.push( PII( d[v], v ) );
            }
        }
    }
    return d[n];
}

int main() {
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        memset( head, -1, sizeof( head ) ); cnt = 0;
        for( int i = 0, a, b, c; i < m; ++i ) {
            scanf( "%d%d%d", &a, &b, &c );
            add( a, b, c );
            add( b, a, c );
        }
        int ans = 0;
        for( int i = 2; i < n; ++i ) {
            for( int j = head[i]; ~j; j = es[j].next ) es[j].flag = es[j ^ 1].flag = false;
            ans = max( ans, dij() );
            for( int j = head[i]; ~j; j = es[j].next ) es[j].flag = es[j ^ 1].flag = true;
        }
        if( ans == INF ) puts( "Inf" );
        else printf( "%d\n", ans );
    }
    return 0;
}
