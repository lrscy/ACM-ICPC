/*
    h为当前代价
    spfa为逆向搜索，寻找每个节点的估值函数g的值
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 10000 + 10;
const int MAXE = 1000000 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXE];
struct Node { int u, f, g; };
int head[MAXN], h[MAXN];
bool vis[MAXN];
int n, m, k, cnt;
vector<int> path;

struct cmp {
    bool operator() ( const Node &a, const Node &b ) {
        return a.f > b.f;
    }
};

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void spfa() {
    queue<int> que;
    memset( vis, false, sizeof( vis ) );
    memset( h, 0x7F, sizeof( h ) );
    que.push( n ); h[n] = 0; vis[n] = true;
    while( !que.empty() ) {
        int u = que.front(); que.pop();
        for( int i = head[u]; ~i; i = es[i].next ) {
            int v = es[i].to;
            if( h[v] > h[u] + es[i].cost ) {
                h[v] = h[u] + es[i].cost;
                if( !vis[v] ) {
                    vis[v] = true;
                    que.push( v );
                }
            }
        }
        vis[u] = false;
    }
    return ;
}

void astar() {
    priority_queue<Node, vector<Node>, cmp> que;
    Node tmp = { 1, h[1], 0 };
    que.push( tmp );
    for( int cur = 0; cur < k && !que.empty(); ) {
        tmp = que.top(), que.pop();
        int u = tmp.u, g = tmp.g;
        if( u == n ) { ++cur; path.push_back( g ); }
        for( int j = head[u]; ~j; j = es[j].next ) {
            tmp.u = es[j].to;
            tmp.g = g + es[j].cost;
            tmp.f = tmp.g + h[tmp.u];
            que.push( tmp );
        }
    }
    return ;
}

int main() {
    int a, b, c;
    k = 2;
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( head, -1, sizeof( head ) );
        cnt = 0;
        for( int i = 1; i <= m; ++i ) {
            scanf( "%d%d%d", &a, &b, &c );
            add( a, b, c );
            add( b, a, c );
        }
        spfa();
        astar();
        printf( "%d\n", path[k - 1] );
    }
    return 0;
}
