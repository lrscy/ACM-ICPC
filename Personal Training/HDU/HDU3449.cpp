#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 10;
const int MAXM = 1e5 + 10;

int dp1[MAXM], dp2[MAXM], box[MAXN], num[MAXN], a[MAXN][15], b[MAXN][15];
int n, m;

int main() {
    int tn;
    while( ~scanf( "%d%d", &n, &m ) ) {
        memset( dp1, 0, sizeof( dp1 ) );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d%d", box + i, num + i );
            for( int j = 1; j <= num[i]; ++j ) {
                scanf( "%d%d", &a[i][j], &b[i][j] );
            }
        }
        for( int i = 1; i <= n; ++i ) {
            for( int j = m; j >= box[i]; --j ) dp2[j] = dp1[j - box[i]];
            for( int j = 1; j <= num[i]; ++j ) {
                for( int k = m; k >= box[i] + a[i][j]; --k )
                    dp2[k] = max( dp2[k], dp2[k - a[i][j]] + b[i][j] );
            }
            for( int j = m; j >= box[i]; --j ) dp1[j] = max( dp1[j], dp2[j] );
        }
        printf( "%d\n", dp1[m] );
    }
    return 0;
}
