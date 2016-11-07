#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

char st[MAXN];
set<char> s;
int cnt[30];
int len;

int main() {
    int tot = 0;
    memset( cnt, 0, sizeof cnt );
    scanf( "%s", st );
    len = strlen( st );
    if( len < 26 ) { puts( "-1" ); return 0; }
    for( int i = 0; i < 26; ++i ) {
        if( st[i] != '?' ) ++cnt[st[i] - 'A'];
        else ++tot;
    }
    for( int i = 0; i < 26; ++i ) if( cnt[i] == 0 ) s.insert( i + 'A' );
    int pos = 26;
    while( pos < len && tot != s.size() ) {
        char c = st[pos - 26];
        if( c != '?' ) {
            --cnt[c - 'A'];
            if( cnt[c - 'A'] == 0 ) s.insert( c );
        } else {
            st[pos - 26] = 'A';
            --tot;
        }
        if( st[pos] != '?' ) {
            ++cnt[st[pos] - 'A'];
            if( s.find( st[pos] ) != s.end() ) s.erase( st[pos] );
        } else ++tot;
        ++pos;
    }
    bool flag = false;
    if( tot == s.size() ) {
        flag = true;
        auto it = s.begin();
        for( int i = pos - 26; i < pos; ++i ) {
            if( st[i] == '?' ) {
                st[i] = *it;
                ++it;
            }
        }
    }
    for( int i = pos; i < len; ++i ) if( st[i] == '?' ) st[i] = 'A';
    if( flag ) printf( "%s\n", st );
    else puts( "-1" );
    return 0;
}
