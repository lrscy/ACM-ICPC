#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e6 + 10;

char str[MAXN], out[MAXN];
int length;

bool check( char c ) {
    return ( ( '0' <= c && c <= '9' ) || ( 'A' <= c && c <= 'E' ) );
}

int main() {
    scanf( "%s", str );
    int len = strlen( str ), pos = 0;
    out[0] = '0'; out[1] = 'k';
    while( pos < len - 2 ) {
        if( str[pos++] != '0' ) continue;
        if( str[pos] != 'k' ) continue;
        ++pos; length = 2;
        while( pos < len && check( str[pos] ) ) {
            out[length++] = str[pos];
            ++pos;
            if( length == 3 && str[pos - 1] == '0' ) break;
        }
        out[length] = 0;
        if( length < 3 ) continue;
        puts( out );
    }
    return 0;
}
