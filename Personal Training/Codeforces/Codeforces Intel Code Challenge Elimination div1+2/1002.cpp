#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;

char str[MAXN];
int a[MAXN];
int n;

bool is( char c ) {
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' );
}

int main() {
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
    bool flag = true;
    fgets( str, MAXN, stdin );
    for( int i = 0; i < n; ++i ) {
        fgets( str, MAXN, stdin );
        if( !flag ) continue;
        int len = strlen( str ); str[--len] = 0;
        int cnt = 0;
        for( int j = 0; j < len; ++j ) if( is( str[j] ) ) ++cnt;
        if( cnt != a[i] ) flag = false;
    }
    puts( flag ? "YES" : "NO" );
    return 0;
}
