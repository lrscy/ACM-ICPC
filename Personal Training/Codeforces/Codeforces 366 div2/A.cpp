#include <bits/stdc++.h>
using namespace std;

char s1[100] = "that I hate ", s2[100] = "that I love ";

int main() {
    int n;
    scanf( "%d", &n );
    if( n == 1 ) { puts( "I hate it" ); return 0; }
    printf( "I hate " );
    for( int i = 2; i <= n; ++i ) {
        if( i & 1 ) printf( "%s", s1 );
        else printf( "%s", s2 );
    }
    puts( "it" );
    return 0;
}
