#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[20];
    int n, m;
    scanf( "%d%d", &n, &m );
    bool flag = true;
    for( int i = 0; i < n; ++i ) {
        for( int j = 0; j < m; ++j ) {
            scanf( "%s", s );
            if( s[0] != 'B' && s[0] != 'W' && s[0] != 'G' ) flag = false;
        }
    }
    if( flag ) puts( "#Black&White" );
    else puts( "#Color" );
    return 0;
}
