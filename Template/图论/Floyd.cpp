#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e3 + 10;

int d[MAXN][MAXN];
int n;

void floyd() {
    for( int k = 0; k < n; ++k ) {
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
    }
    return ;
}

int main() {
    return 0;
}
