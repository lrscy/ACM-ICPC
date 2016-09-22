#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;
const int N = 115000;

double dnum[MAXN];
char str[MAXN];

void init() {
    dnum[0] = 0;
    for( int i = 1; i < N; ++i ) dnum[i] = dnum[i - 1] + 1. / ( 1. * i * i );
    return ;
}

int main() {
    init();
    while( ~scanf( "%s", str ) ) {
        int i, len = strlen( str ), tn = 0, n = 0;
        for( int i = 0; i < len && tn < 7; ++i ) {
            if( n == 0 && str[i] == '0' ) continue;
            n = n * 10 + str[i] - '0';
            ++tn;
        }
        if( tn >= 7 || n >= N ) { puts( "1.64493" ); continue; }
        printf( "%.5f\n", dnum[n] );
    }
    return 0;
}
