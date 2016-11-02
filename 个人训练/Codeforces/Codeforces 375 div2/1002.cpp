#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300;

char st[MAXN];
int n;

bool chk( char c ) { return ( 'a' <= c && c <= 'z' ) || ( 'A' <= c && c <= 'Z' ); } 

int main() {
    int cnt = 0, len = 0, flag = 0, pos = 0, pre = 0;
    scanf( "%d%s", &n, st );
    while( !chk( st[pos] ) && pos < n ) {
        if( st[pos] == '(' ) flag = 1;
        if( st[pos] == ')' ) flag = 0;
        ++pos;
    }
    pre = pos;
    while( pos < n ) {
        while( chk( st[pos] ) && pos < n ) ++pos;
        if( flag && pos != pre ) ++cnt;
        if( !flag ) len = max( len, pos - pre );
        while( !chk( st[pos] ) && pos < n ) {
            if( st[pos] == '(' ) flag = 1;
            if( st[pos] == ')' ) flag = 0;
            ++pos;
        }
        pre = pos;
    }
    printf( "%d %d\n", len, cnt );
    return 0;
}
