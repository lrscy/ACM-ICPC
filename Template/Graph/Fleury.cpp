/* 弗罗莱算法
   求欧拉路径
*/
#include <bits/stdc++.h>
using namespace std;

int stk[1005];
int top;
int N, M, ss, tt;
int mp[1005][1005];

void dfs(int x) {
    stk[top++] = x;
    for (int i = 1; i <= N; ++i) {
        if (mp[x][i]) {
            mp[x][i] = mp[i][x] = 0; // 删除此边
            dfs(i);
            break;
        }
    }
}

void fleury(int ss) {
    int brige;
    top = 0;
    stk[top++] = ss; // 将起点放入Euler路径中
    while (top > 0) {
        brige = 1;
        for (int i = 1; i <= N; ++i) { // 试图搜索一条边不是割边（桥）
            if (mp[stk[top-1]][i]) {
                brige = 0;
                break;
            }
        }
        if (brige) { // 如果没有点可以扩展，输出并出栈
            printf("%d ", stk[--top]);
        } else { // 否则继续搜索欧拉路径
            dfs(stk[--top]);
        }
    }
}

int main() {
    int x, y, deg, num;
    while (scanf("%d %d", &N, &M) != EOF) {
        memset(mp, 0, sizeof (mp));
        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &x, &y);
            mp[x][y] = mp[y][x] = 1;
        }
        for (int i = 1; i <= N; ++i) {
            deg = num = 0;
            for (int j = 1; j <= N; ++j) {
                deg += mp[i][j];
            }
            if (deg % 2 == 1) {
                ss = i, ++num;
                printf("%d\n", i);
            }
        }
        if (num == 0 || num == 2) {
            fleury(ss);
        } else {
            puts("No Euler path");
        }
    }
    return 0;
}
/*
12
5
9
3
4
8
3
4
6
7
8
8
9

path:
5 8 7 6 8 9 1 5 3 2 4 6
*/

