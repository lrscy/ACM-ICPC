#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

struct ACAuto {
    const static int type = 26;
    int next[MAXN][type], fail[MAXN], len[MAXN];
    int root, tot;
    int newnode() {
        for( int i = 0; i < type; ++i ) next[tot][i] = -1;
        len[tot++] = 0;
        return tot - 1;
    }
    void init() {
        tot = 0;
        root = newnode();
    }
    void insert( char *s ) {
        int tlen = strlen( s ), u = root;
        for( int i = 0; i < tlen; ++i ) {
            int idx = s[i] - 'a';
            if( next[u][idx] == -1 ) next[u][idx] = newnode();
            u = next[u][idx];
        }
        len[u]++;
    }
    void build() {
        queue<int> que;
        fail[root] = root;
        for( int i = 0; i < type; ++i ) {
            if( next[root][i] == -1 ) next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                que.push( next[root][i] );
            }
        }
        while( !que.empty() ) {
            int u = que.front(); que.pop();
            for( int i = 0; i < type; ++i ) {
                if( next[u][i] == -1 ) next[u][i] = next[fail[u]][i];
                else {
                    fail[next[u][i]] = next[fail[u]][i];
                    que.push( next[u][i] );
                }
            }
        }
    }
    int query( char *s ) {
        int idx, tlen = strlen( s ), u = root, cnt = 0;
        for( int i = 0; i < tlen; ++i ) {
            idx = s[i] - 'a';
            u = next[u][idx];
            int tp = u;
            while( tp != root ) {
                cnt += len[tp];
                len[tp] = 0;
                tp = fail[tp];
            }
        }
        return cnt;
    }
}ac;
char s[MAXN];
int n;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        ac.init();
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%s", s );
            ac.insert( s );
        }
        ac.build();
        scanf( "%s", s );
        printf( "%d\n", ac.query( s ) );
    }
    return 0;
}
