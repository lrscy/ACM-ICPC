#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> PIS;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 10;

PIS pis[MAXN];
map<string, PII> mp;
int n, m;

bool cmp( const PIS &a, const PIS &b ) {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

int main() {
    char s[60];
    while( ~scanf( "%d", &n ) && n ) {
        mp.clear();
        for( int i = 0; i < n; ++i ) {
            scanf( "%s%d", s, &pis[i].first );
            pis[i].second = s;
        }
        sort( pis, pis + n, cmp );
        int cnt = 1;
        for( int i = 0; i < n; ++i ) {
            printf( "%s %d\n", pis[i].second.c_str(), pis[i].first );
            mp[pis[i].second].first = i + 1;
            mp[pis[i].second].second = cnt;
            if( i ) {
                if( pis[i].first == pis[i - 1].first ) {
                    ++cnt;
                    mp[pis[i].second].first = mp[pis[i - 1].second].first;
                } else cnt = 1;
                mp[pis[i].second].second = cnt;
            }
        }
        scanf( "%d", &m );
        while( m-- ) {
            scanf( "%s", s );
            PII tmp = mp[s];
            if( tmp.second == 1 ) printf( "%d\n", tmp.first );
            else printf( "%d %d\n", tmp.first, tmp.second );
        }
    }
    return 0;
}
