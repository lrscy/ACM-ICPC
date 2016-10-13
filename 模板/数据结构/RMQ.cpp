/* HDU 3183 已验
    1. init()
        i 从 1 开始
        dp[i][0] 装最原始数据
        min/max 比较具体情况具体分析，有时需要自己写，例如lca可能需要利用dep做比较
        ！！！特别需要注意小于号还是小于等于号！！！
    2. query()
        x < y
        min/max 同上
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int POW = 32;

int lg2[MAXN], dp[MAXN][POW], a[MAXN];
int n;

void init( int tn ) {
    lg2[0] = -1; for( int i = 1; i < MAXN; ++i ) lg2[i] = ( ( i & ( i - 1 ) ) == 0 ) ? lg2[i - 1] + 1 : lg2[i - 1];
    for( int i = 1; i <= tn; ++i ) dp[i][0] = i;
    for( int j = 1; j <= 20; ++j ) {
        for( int i = 1; i + ( 1 << j ) - 1 <= tn; ++i ) {
            dp[i][j] = min( dp[i][j - 1], dp[i + ( 1 << ( j - 1 ) )][j - 1] );
        }
    }
}

int query( int x, int y ) {
    int k = lg2[y - x + 1];
    return min( dp[x][k], dp[y - ( 1 << k ) + 1][k] );
}

int main() {
    ;
    return 0;
}
