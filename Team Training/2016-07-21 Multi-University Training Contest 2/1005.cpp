#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int MAXN = 2e3 + 10;

PII poi[MAXN];
map<PII, int> mp;
map<PII, int>::iterator it;
LL two[MAXN];
LL sum;
int n;

int gcd( int a, int b ) {
    if( a < b ) return gcd( b, a );
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

void gao( int st ) {
    PII tp;
    int tmp = 0;
    mp.clear();
    for( int i = st + 1; i < n; ++i ) {
        int tx = poi[i].first - poi[st].first, ty = poi[i].second - poi[st].second;
        if( tx == 0 && ty == 0 ) { ++tmp; continue; }
        if( ty < 0 || ( tx < 0 && ty == 0 ) ) { tx *= -1; ty *= -1; }
        int tt = gcd( abs( tx ), abs( ty ) );
        tx /= tt; ty /= tt;
        tp = make_pair( tx, ty );
        ++mp[tp];
    }
    sum = ( sum + two[tmp] - 1 + MOD ) % MOD;
    for( it = mp.begin(); it != mp.end(); ++it ) {
        sum = ( sum + ( two[it->second] + MOD - 1 ) * two[tmp] % MOD ) % MOD;
    }
    return ;
}

int main() {
    int t;
    scanf( "%d", &t );
    two[0] = 1;
    for( int i = 1; i < MAXN; ++i ) two[i] = ( 2 * two[i - 1] ) % MOD;
    while( t-- ) {
        sum = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) scanf( "%d%d", &poi[i].first, &poi[i].second );
        for( int i = 0; i < n; ++i ) gao( i );
        printf( "%I64d\n", sum );
    }
    return 0;
}
