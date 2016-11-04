#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Node {
    bool flag;
    int next[20];
    void init() { flag = false; memset( next, -1, sizeof( next ) ); }
};
Node node[MAXN];
char str[MAXN][20];
int n;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        int cnt = 0;
        bool flag = true;
        scanf( "%d", &n );
        node[cnt++].init();
        for( int i = 0; i < n; ++i ) {
            scanf( "%s", str + i );
            if( !flag ) continue;
            int len = strlen( str[i] ), pos = 0;
            for( int j = 0; j < len; ++j ) {
                if( node[pos].flag == true ) { flag = false; break; }
                int tmp = str[i][j] - '0';
                if( node[pos].next[tmp] == -1 ) {
                    node[pos].next[tmp] = cnt;
                    node[cnt++].init();
                } else if( j == len - 1 ) { flag = false; break; }
                pos = node[pos].next[tmp];
            }
            node[pos].flag = true;
        }
        if( flag ) puts( "YES" );
        else puts( "NO" );
    }
    return 0;
}
