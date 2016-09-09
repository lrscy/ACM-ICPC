#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

char str[MAXN];
bool vis[MAXN];
int n;

int main() {
    int ret;
    bool flag = false;
    srand( 98372849 );
    scanf( "%d", &n );
    memset( vis, false, sizeof( vis ) );
    while( true ) {
//    for( int i = 1; i < 500; ++i ) {
        for( int j = 0; j < n; ++j ) str[j] = ( rand() & 1 ) + '0';
        printf( "%s\n", str ); fflush( stdout ); scanf( "%d", &ret );
        if( ret == n ) return 0;
        if( ret * 2 == n ) { flag = true; break; }
    }
//    if( !flag ) return 0;
    vis[0] = true;
    for( int i = 1; i < n; ++i ) {
        str[0] = '0' + '1' - str[0];
        str[i] = '0' + '1' - str[i];
        printf( "%s\n", str ); fflush( stdout ); scanf( "%d", &ret );
        if( ret == n ) return 0;
        if( ret == 0 ) vis[i] = true;
        str[0] = '0' + '1' - str[0];
        str[i] = '0' + '1' - str[i];
    }
    for( int i = 1; i < n; ++i ) if( !vis[i] ) str[i] = '0' + '1' - str[i];
    printf( "%s\n", str ); fflush( stdout ); scanf( "%d", &ret );
    if( ret == n ) return 0;
    for( int i = 0; i < n; ++i ) str[i] = '0' + '1' - str[i];
    printf( "%s\n", str ); fflush( stdout ); scanf( "%d", &ret );
    return 0;
}
