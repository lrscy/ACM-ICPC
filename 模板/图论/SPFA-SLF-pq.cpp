#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e3 + 10;

int cost[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];
int num[MAXN];
int n;
struct cmp {
    bool operator() ( int x, int y ) {
        return d[x] > d[y];
    }
};

bool spfa_slf_pq( int s ) {
    priority_queue<int, vector<int>, cmp > pq;
    for( int i = 0; i < n; ++i ) { d[i] = INF; used[i] = false; num[i] = 0; }
    d[s] = 0; used[s] = true; ++num[s];
    pq.push( s );
    while( !pq.empty() ) {
        int u = pq.top(); pq.pop();
        used[s] = false;
        for( int i = 0; i < n; ++i ) {
            if( d[u] + cost[u][i] < d[i] ) {
                d[i] = d[u] + cost[u][i];
                if( !used[i] ) {
                    ++num[i];
                    if( num[i] > n ) return false;
                    pq.push( i );
                    used[i] = true;
                }
            }
        }
    }
    return true;
}

int main() {
    return 0;
}
