#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1e3 + 10;

vector<int> vec[30];
char st[MAXN];
int dis[30];
int len;

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( dis, 0x3F, sizeof dis );
        for( int i = 0; i < 30; ++i ) vec[i].clear();
        scanf( "%s", st );
        len = strlen( st );
        for( int i = 0; i < len; ++i ) {
            int tmp = st[i] - 'a', tn;
            tn = vec[tmp].size();
            if( tn ) dis[tmp] = min( dis[tmp], i - vec[tmp][tn - 1] );
            vec[tmp].push_back( i );
        }
        int ans = INF;
        for( int i = 0; i < 26; ++i ) {
            ans = min( ans, dis[i] );
        }
        if( ans == INF ) puts( "-1" );
        else printf( "%d\n", ans );
    }
    return 0;
}
