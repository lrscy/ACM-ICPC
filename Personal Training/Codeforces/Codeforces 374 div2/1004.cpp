#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;

struct Node {
    LL val; int id;
    bool operator < ( const Node &tmp ) const { return abs( val ) > abs( tmp.val ); }
};
Node node[MAXN];
priority_queue<Node> pq;
int n, m, x, tot;

bool cmp( const Node &a, const Node &b ) { return a.id < b.id; }

int main() {
    Node tn;
    int op = 1;
    tot = 0;
    scanf( "%d%d%d", &n, &m, &x );
    for( int i = 0; i < n; ++i ) {
        scanf( "%lld", &tn.val );
        tn.id = i;
        pq.push( tn );
        if( tn.val < 0 ) op = -op;
    }
    while( m-- ) {
        tn = pq.top(); pq.pop();
        if( tn.val < 0 ) {
            if( op == -1 ) tn.val -= x;
            else tn.val += x;
            if( tn.val >= 0 ) op = -op;
            pq.push( tn );
        } else {
            if( op == -1 ) tn.val += x;
            else tn.val -= x;
            if( tn.val < 0 ) op = -op;
            pq.push( tn );
        }
    }
    while( !pq.empty() ) { node[tot++] = pq.top(); pq.pop(); }
    sort( node, node + n, cmp );
    for( int i = 0; i < n; ++i ) printf( "%lld%c", node[i].val, i == n - 1 ? '\n' : ' ' );
    return 0;
}
