#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 10;

struct Node { bool flag; int st, ed; };
Node node[MAXN];
int n, a, b, len, cnt;

int main() {
    int t, ta, tb;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        int nmin, st, cur;
        nmin = cur = cnt = 0;
        scanf( "%d%d%d%d", &n, &a, &b, &len );
        node[cnt].flag = false;
        node[cnt].st = 0;
        for( int i = 0; i < n; ++i ) {
            scanf( "%d%d", &ta, &tb );
            node[cnt].ed = ta; ++cnt;
            node[cnt].flag = true;
            node[cnt].st = ta; node[cnt].ed = tb; ++cnt;
            node[cnt].flag = false;
            node[cnt].st = tb;
        }
        node[cnt].ed = len; ++cnt;
        for( int i = cnt - 1; i >= 0; --i ) {
            if( node[i].flag ) {
                cur += ( node[i].ed - node[i].st ) * a;
                nmin = min( nmin, cur );
            } else {
                cur -= ( node[i].ed - node[i].st ) * b;
                nmin = min( nmin, cur );
            }
        }
        printf( "Case #%d: %d\n", ncas, cur - nmin );
    }
    return 0;
}
