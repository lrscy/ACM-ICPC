#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;

int main() {
    char st[MAXN];
    scanf( "%s", st + 1 );
    st[0] = 'a';
    int len = strlen( st + 1 ), ans = 0;
    for( int i = 1; i <= len; ++i ) {
        int dis = abs( st[i] - st[i - 1] );
        ans += min( dis, 26 - dis );
    }
    printf( "%d\n", ans );
    return 0;
}
