#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1e4 + 10;

char s[MAXN], str[MAXN];
int a[MAXN];
int n;

int main() {
    int ok = 1, cur;
    scanf( "%d%s", &n, s );
    int len = strlen( s );
    int flag = 0;
    for( int i = len - 1; i >= 0; --i ) {
        if( s[i] == '>' ) {
            if( !flag ) str[i + 1] = 'a';
            str[i] = str[i + 1] + 1;
            flag = 1;
        } else if( s[i] == '=' ) {
            if( !flag ) continue;
            str[i] = str[i + 1];
        } else flag = 0;
        if( str[i] >= 'a' + n ) { ok = 0; break; }
    }
    if( !ok ) { puts( "-1" ); return 0; }
    cur = 0;
    if( s[0] == '<' || ( !str[0] && s[0] == '=' ) ) str[0] = 'a';
    for( int i = 1; i <= len; ++i ) if( !str[i] ) {
        if( s[i - 1] == '<' ) str[i] = str[i - 1] + 1;
        if( s[i - 1] == '=' ) str[i] = str[i - 1];
        if( str[i] >= 'a' + n ) { ok = 0; break; }
    }
    if( !ok ) { puts( "-1" ); return 0; }
    printf( "%s\n", str );
    return 0;
}
