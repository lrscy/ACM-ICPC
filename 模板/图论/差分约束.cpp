/*
    建图： 约束图
    在一个差分约束系统Ax≤b中，m X n的线性规划矩阵A可被看做是n顶点，m条边的图的关联矩阵。对于i=1,2,…,n，图中的每一个顶点vi对应着n个未知量的一个xi。图中的每个有向边对应着关于两个未知量的m个不等式中的一个。
    给定一个差分约束系统Ax≤b，相应的约束图是一个带权有向图G=(V,E)，其中V={v0,v1,…,vn}，而且E={ (vi,vj) : xj-xi≤bk是一个约束}∪{ (v0,v1) , (v0,v2) , … , (v0,vn) }。引入附加顶点v0是为了保证其他每个顶点均从v0可达。因此，顶点集合V由对应于每个未知量xi的顶点vi和附加的顶点v0组成。边的集合E由对应于每个差分约束条件的边与对应于每个未知量xi的边(v0,vi)构成。如果xj-xi≤bk是一个差分约束，则边(vi,vj)的权w(vi,vj)=bk（注意i和j不能颠倒），从v0出发的每条边的权值均为0。
    定理：给定一差分约束系统Ax≤b，设G=(V,E)为其相应的约束图。如果G不包含负权回路，那么x=( d(v0,v1) , d(v0,v2) , … , d(v0,vn) )是此系统的一可行解，其中d(v0,vi)是约束图中v0到vi的最短路径(i=1,2,…,n)。如果G包含负权回路，那么此系统不存在可行解。

    差分约束问题的求解
    由上述定理可知，可以采用Bellman-Ford算法对差分约束问题求解。因为在约束图中，从源点v0到其他所有顶点间均存在边，因此约束图中任何负权回路均从v0可达。如果Bellman-Ford算法返回TRUE，则最短路径权给出了此系统的一个可行解；如果返回FALSE，则差分约束系统无可行解。
    关于n个未知量m个约束条件的一个差分约束系统产生出一个具有n+1个顶点和n+m条边的约束图。因此采用Bellman-Ford算法，可以再O((n+1)(n+m))=O(n^2+nm)时间内将系统解决。此外，可以用SPFA算法进行优化，复杂度为O(km)，其中k 为常数。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 100000 + 10;
const int MAXM = 1000000 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXM];
int head[MAXN], dis[MAXN], sta[MAXM];
bool vis[MAXN];
int n, m, cnt;

void add( int u, int v, int w ) {
    es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void spfa() {
    int top = 0;
    memset( dis, 0x7F, sizeof( dis ) );
    memset( vis, false, sizeof( vis ) );
    dis[1] = 0; vis[1] = true; sta[top++] = 1;
    while( top ) {
        int u = sta[--top];
        for( int i = head[u]; ~i; i = es[i].next ) {
            int v = es[i].to;
            if( dis[v] > dis[u] + es[i].cost ) {
                dis[v] = dis[u] + es[i].cost;
                if( !vis[v] ) {
                    vis[v] = true;
                    sta[top++] = v;
                }
            }
        }
        vis[u] = false;
    }
    return ;
}

int main() {
    int a, b, c;
    memset( head, -1, sizeof( head ) );
    cnt = 0;
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < m; ++i ) {
        scanf( "%d%d%d", &a, &b, &c );
        add( a, b, c );
    }
    spfa();
    printf( "%d\n", dis[n] );
    return 0;
}
