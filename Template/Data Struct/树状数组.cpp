/*
    1. 下标从1开始
    2. 注意x==0时的lowbit，有可能超时
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int c[MAXN], a[MAXN];
int n;

int lowbit( int x ) { return x & -x; }

void add( int i, int x ) {
    while( i <= n ) {
        add[i] += x;
        i += lowbit( i );
    }
}

int sum( int i ) {
    int ret = 0;
    while( i ) {
        sum += c[i];
        i -= lowbit( i );
    }
    return ret;
}

int main() {
    ;
    return 0;
}
