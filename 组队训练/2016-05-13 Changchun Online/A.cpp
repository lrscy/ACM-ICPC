#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x7F7F7F7F;
const int MAXN = 200000 + 10;
const int MAXM = 200 + 10;

struct Node {
    string name;
    int val, id;
    bool operator < ( const Node &tmp ) const {
        return val == tmp.val ? id > tmp.id : val < tmp.val;
    }
};
Node nodes[MAXN];
PII pii[MAXN];
string ans[MAXN];
int query[MAXM];
int k, m, q;

int main() {
    char str[300];
    int t, val;
    Node tn;
    scanf( "%d", &t );
    while( t-- ) {
        priority_queue<Node> pq;
        scanf( "%d%d%d", &k, &m, &q );
        for( int i = 0; i < k; ++i ) {
            scanf( "%s%d", str, &val );
            nodes[i].name = str; nodes[i].val = val; nodes[i].id = i + 1;
        }
        for( int i = 0; i < m; ++i ) {
            scanf( "%d%d", &pii[i].first, &pii[i].second );
        }
        pii[m].first = pii[m].second = INF; ++m;
        sort( pii, pii + m );
        for( int i = 0; i < q; ++i ) {
            scanf( "%d", query + i );
        }
        query[q] = INF;
        int pos = 0, pos2 = 0, cnt = 0;
        for( int i = 0; i < m; ++i ) {
            while( pos < pii[i].first && pos < k ) {
                pq.push( nodes[pos++] );
            }
            for( int j = 0; j < pii[i].second && !pq.empty(); ++j ) {
                tn = pq.top(); pq.pop();
                ++cnt;
                ans[cnt] = tn.name;
            }
        }
        printf( "%s", ans[query[0]].c_str() );
        for( int i = 1; i < q; ++i ) {
            printf( " %s", ans[query[i]].c_str() );
        }
        puts( "" );
    }
    return 0;
}
