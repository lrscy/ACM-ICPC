#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e3 + 10;

int cost[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];
int n;

void spfa( int s ) {
    queue<int> q;
    for( int i = 0; i < n; ++i ) { d[i] = INF; used[i] = false; }
    d[s] = 0; used[s] = true;
    q.push( s );
    while( !q.empty() ) {
        int u = q.front(); q.pop();
        used[u] = false;
        for( int i = 0; i < n; ++i ) {
            if( d[u] + cost[u][i] < d[i] ) {
                d[i] = d[u] + cost[u][i];
                if( !used[i] ) {
                    used[i] = true;
                    q.push( i );
                }
            }
        }
    }
    return ;
}

int main() {
    return 0;
}
