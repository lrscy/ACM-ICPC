#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;

vector<int> vec[MAXN];
int c[MAXN], fa[MAXN];
int n, m, k, tot;

int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }

void munion( int x, int y ) {
    int fx = mfind( x ), fy = mfind( y );
    fa[fx] = fy;
}

int main() {
    int l, r, ans = 0;
    tot = 0;
    scanf( "%d%d%d", &n, &m, &k );
    for( int i = 1; i <= n; ++i ) scanf( "%d", c + i ), fa[i] = i;
    for( int i = 1; i <= m; ++i ) scanf( "%d%d", &l, &r ), munion( l, r );
    for( int i = 1; i <= n; ++i ) vec[mfind( i )].push_back( c[i] );
    for( int i = 1; i <= n; ++i ) if( vec[i].size() > 1 ) {
        int sum = 0, len = vec[i].size(), nmax = 0;
        map<int, int> mp;
        for( int j = 0; j < len; ++j ) {
            ++mp[vec[i][j]];
            nmax = max( nmax, mp[vec[i][j]] );
            ++sum;
        }
        ans += sum - nmax;
    }
    printf( "%d\n", ans );
    return 0;
}
