#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

char st[MAXN];
int num[MAXN], le[MAXN], ri[MAXN];
int len;

inline LL sqr( int x ) { return 1LL * x * x; }

int main() {
    LL ans, tans, tmp;
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        ans = tans = 0;
        scanf( "%s", st );
        len = strlen( st );
        int cur = 0; le[cur] = ri[cur] = 0; num[0] = cur;
        for( int i = 1; i < len; ++i ) {
            if( st[i] == st[i - 1] ) ri[cur] = i;
            else {
                ans += sqr( ri[cur] - le[cur] + 1 );
                ++cur; le[cur] = ri[cur] = i;
            }
            num[i] = cur;
        }
        ans += sqr( ri[cur] - le[cur] + 1 );
        for( int i = 0; i < len; ++i ) {
            cur = num[i];
            tmp = ans - sqr( ri[cur] - le[cur] + 1 ) + sqr( i - le[cur] ) + sqr( ri[cur] - i );
            int tlen = 1;
            if( i && st[i - 1] != st[i] ) {
                cur = num[i - 1];
                tlen += ri[cur] - le[cur] + 1;
                tmp -= sqr( ri[cur] - le[cur] + 1 );
            }
            if( i < len - 1 && st[i + 1] != st[i] ) {
                cur = num[i + 1];
                tlen += ri[cur] - le[cur] + 1;
                tmp -= sqr( ri[cur] - le[cur] + 1 );
            }
            tmp += sqr( tlen );
            tans = max( tans, tmp );
        }
        printf( "%lld\n", max( tans, ans ) );
    }
    return 0;
}
