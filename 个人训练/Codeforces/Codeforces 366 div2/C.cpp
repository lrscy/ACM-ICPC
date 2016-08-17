#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
typedef pair<int, int> PII;

set<PII> sp;
set<int> s[MAXN];
set<PII>::iterator it;
int n, q;

int main() {
    int ta, tb, tot = 0;
    scanf( "%d%d", &n, &q );
    for( int i = 0; i < q; ++i ) {
        scanf( "%d%d", &ta, &tb );
        if( ta == 1 ) {
            sp.insert( make_pair( ++tot, tb ) );
            s[tb].insert( tot );
        }
        if( ta == 2 ) {
            while( s[tb].size() ) {
                int tt = *( s[tb].begin() );
                sp.erase( sp.find( make_pair( tt, tb ) ) );
                s[tb].erase( s[tb].begin() );
            }
        }
        if( ta == 3 ) {
            while( sp.size() ) {
                PII tp = *( sp.begin() );
                if( tp.first <= tb ) {
                    sp.erase( sp.begin() );
                    s[tp.second].erase( s[tp.second].find( tp.first ) );
                } else break;
            }
        }
        printf( "%d\n", sp.size() );
    }
    return 0;
}
