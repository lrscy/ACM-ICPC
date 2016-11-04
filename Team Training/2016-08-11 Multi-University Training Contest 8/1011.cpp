#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

char s[MAXN], st[MAXN];
int n, top;

int main() {
    int t, cnt;
    scanf( "%d", &t );
    while( t-- ) {
        top = cnt = 0;
        scanf( "%d%s", &n, s );
        for( int i = 0; i < n; ++i ) {
            if( ( top == 0 || st[top - 1] == ')' ) && s[i] == ')' ) st[top++] = ')';
            else if( st[top - 1] == '(' && s[i] == ')' ) {
                ++cnt;
                --top;
            } else st[top++] = '(';
        }
        st[top] = 0;
        if( top == 4 && !strcmp( st, "))((" ) ) puts( "Yes" );
        else if( top > 2 ) puts( "No" );
        else if( top == 0 ) {
            if( cnt > 1 ) puts( "Yes" );
            else puts( "No" );
        } else if( top == 1 ) {
            puts( "No" );
        } else {
            if( st[0] == ')' && st[1] == '(' ) puts( "Yes" );
            else puts( "No" );
        }
    }
    return 0;
}
