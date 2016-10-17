/*
    在实际问题中，2-SAT问题在大多数时候表现成以下形式：有N对物品，每对物品中必须选取一个，也只能选取一个，并且它们之间存在某些限制关系（如某两个物品不能都选，某两个物品不能都不选，某两个物品必须且只能选一个，某个物品必选）等，这时，可以将每对物品当成一个布尔值（选取第一个物品相当于0，选取第二个相当于1），如果所有的限制关系最多只对两个物品进行限制，则它们都可以转化成9种基本限制关系，从而转化为2-SAT模型。
    其实2-SAT问题的建模是和实际问题非常相似的。
    建立一个2N阶的有向图，其中的点分为N对，每对点表示布尔序列A的一个元素的0、1取值（以下将代表A[i]的0取值的点称为i，代表A[i]的1取值的点称为i'）。显然每对点必须且只能选取一个。然后，图中的边具有特定含义。若图中存在边<i, j>，则表示若选了i必须选j。可以发现，上面的9种限制关系中，后7种二元限制关系都可以用连边实现，比如NOT(A[x] AND A[y])需要连两条边<x, y'>和<y, x'>，A[x] OR A[y]需要连两条边<x', y>和<y', x>。而前两种一元关系，对于A[x]（即x必选），可以通过连边<x', x>来实现，而NOT A[x]（即x不能选），可以通过连边<x, x'>来实现。
    【O(NM)算法：求字典序最小的解】
    根据2-SAT建成的图中边的定义可以发现，若图中i到j有路径，则若i选，则j也要选；或者说，若j不选，则i也不能选；
    因此得到一个很直观的算法：
    （1）给每个点设置一个状态V，V=0表示未确定，V=1表示确定选取，V=2表示确定不选取。称一个点是已确定的当且仅当其V值非0。设立两个队列Q1和Q2，分别存放本次尝试选取的点的编号和尝试不选的点的编号。
    （2）若图中所有的点均已确定，则找到一组解，结束，否则，将Q1、Q2清空，并任选一个未确定的点i，将i加入队列Q1，将i'加入队列Q2；
    （3）找到i的所有后继。对于后继j，若j未确定，则将j加入队列Q1；若j'（这里的j'是指与j在同一对的另一个点）未确定，则将j'加入队列Q2；
    （4）遍历Q2中的每个点，找到该点的所有前趋（这里需要先建一个补图），若该前趋未确定，则将其加入队列Q2；
    （5）在（3）（4）步操作中，出现以下情况之一，则本次尝试失败，否则本次尝试成功：
        <1>某个已被加入队列Q1的点被加入队列Q2；
        <2>某个已被加入队列Q2的点被加入队列Q1;
        <3>某个j的状态为2；
        <4>某个i'或j'的状态为1或某个i'或j'的前趋的状态为1；
    （6）若本次尝试成功，则将Q1中的所有点的状态改为1，将Q2中所有点的状态改为2，转（2），否则尝试点i'，若仍失败则问题无解。
    该算法的时间复杂度为O(NM)（最坏情况下要尝试所有的点，每次尝试要遍历所有的边），但是在多数情况下，远远达不到这个上界。
    具体实现时，可以用一个数组vst来表示队列Q1和Q2。设立两个标志变量i1和i2（要求对于不同的i，i1和i2均不同，这样可以避免每次尝试都要初始化一次，节省时间），若vst[i]=i1则表示i已被加入Q1，若vst[i]=i2则表示i已被加入Q2。不过Q1和Q2仍然是要设立的，因为遍历（BFS）的时候需要队列，为了防止重复遍历，加入Q1（或Q2）中的点的vst值必然不等于i1（或i2）。中间一旦发生矛盾，立即中止尝试，宣告失败。
    该算法虽然在多数情况下时间复杂度到不了O(NM)，但是综合性能仍然不如下面的O(M)算法。不过，该算法有一个很重要的用处：求字典序最小的解！
    如果原图中的同一对点编号都是连续的（01、23、45……）则可以依次尝试第0对、第1对……点，每对点中先尝试编号小的，若失败再尝试编号大的。这样一定能求出字典序最小的解（如果有解的话），因为一个点一旦被确定，则不可更改。
    如果原图中的同一对点编号不连续（比如03、25、14……）则按照该对点中编号小的点的编号递增顺序将每对点排序，然后依次扫描排序后的每对点，先尝试其编号小的点，若成功则将这个点选上，否则尝试编号大的点，若成功则选上，否则（都失败）无解。
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1000 + 10;
const int MAXM = 1000000 + 10;

struct Edge{ int to, next; };
Edge es[MAXM];
int head[MAXN], low[MAXN], dfn[MAXN], belong[MAXN], a[MAXN], b[MAXN];
bool insta[MAXN];
int n, m, cnt, index;
stack<int> sta;

void add( int u, int v ) {
    es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
    return ;
}

void tarjan( int u ) {
    int v;
    dfn[u] = low[u] = index++;
    sta.push( u );
    insta[u] = true;
    for( int i = head[u]; ~i; i = es[i].next ) {
        v = es[i].to;
        if( dfn[v] == -1 ) {
            tarjan( v );
            low[u] = min( low[u], low[v] );
        } else if( insta[v] ) {
            low[u] = min( low[u], dfn[v] );
        }
    }
    if( dfn[u] == low[u] ) {
        do {
            v = sta.top(); sta.pop();
            insta[v] = false;
            belong[v] = cnt;
        } while( u != v );
        ++cnt;
    }
    return ;
}

int main() {
    scanf( "%d%d", &n, &m );
    memset( head, -1, sizeof( head ) );
    memset( dfn, -1, sizeof( dfn ) );
    memset( low, -1, sizeof( low ) );
    memset( insta, false, sizeof( insta ) );
    memset( belong, -1, sizeof( belong ) );
    cnt = 0;
    for( int i = 0; i < m; ++i ) {
        scanf( "%d%d", a + i, b + i );
        if( a[i] > b[i] ) swap( a[i], b[i] );
    }
    for( int i = 0; i < m; ++i ) {
        for( int j = i + 1; j < m; ++j ) {
            if( ( a[i] < a[j] && b[i] < b[j] && a[j] < b[i] ) ||
               ( a[i] > a[j] && b[i] > b[j] && b[j] > a[i] ) ) {
                add( i * 2, j * 2 + 1 );
                add( j * 2, i * 2 + 1 );
                add( i * 2 + 1, j * 2 );
                add( j * 2 + 1, i * 2 );
            }
        }
    }
    index = 1; cnt = 1;
    for( int i = 0; i < m * 2; ++i ) {
        if( dfn[i] == -1 ) tarjan( i );
    }
    bool flag = true;
    for( int i = 0; i < m * 2; ++i ) {
        if( belong[i] == belong[i ^ 1] ) {
            flag = false;
            break;
        }
    }
    if( flag ) printf( "panda is telling the truth...\n" );
    else printf( "the evil panda is lying again\n" );
    return 0;
}
