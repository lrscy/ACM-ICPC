/*
    关于次小生成树
    但有一种更简单的方法：先求最小生成树T，枚举添加不在T中的边，则添加后一定会形成环。找到环上边值第二大的边(即环中属于T中的最大边)，把它删掉，计算当前生成树的权值，取所有枚举修改的生成树的最小值，即为次小生成树。
    这种方法在实现时有更简单的方法：首先求最小生成树T，然后从每个结点u遍历最小生成树T，用一个二维数组max[u][v]记录结点u到结点v的路劲上边的最大值(即最大边的值)。然后枚举不在T中的边(u,v)，计算T- max[u][v] + w(u,v)的最小值，即为次小生成树的权值。显然，这种方法的时间复杂度为O(n^2 + e)。 
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e3 + 10;
const int MAXM = 1e6 + 10;

struct edge { int u, v, cost; };
edge es[MAX_V];
int V, E;
int father[MAX_V], mrank[MAX_V];

int mfind( int x ) {
    if( x != father[x] )
        father[x] = mfind( father[x] );
    return father[x];
}

void munion( int x, int y ) {
    if( mrank[x] > mrank[y] ) father[y] = x;
    else {
        if( mrank[x] == mrank[y] ) ++mrank[y];
        father[x] = y;
    }
    return ;
}

bool cmp( const edge& e1, const edge& e2 ) {
    return e1.cost > e2.cost;
}

int kruskal() {
    int res = 0;
    sort( es, es + E, cmp );
    for( int i = 0; i < V; ++i ) { father[i] = i; mrank[i] = 0; }
    for( int i = 0; i < E; ++i ) {
        int x = mfind( es[i].u );
        int y = mfind( es[i].v );
        if( x != y ) { munion( x, y ); res += es[i].cost; }
    }
    return res;
}

int main() {
    return 0;
}
