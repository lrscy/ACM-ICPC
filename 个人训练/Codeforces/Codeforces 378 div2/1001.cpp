#include <bits/stdc++.h>
using namespace std;

char st[110];
int len;

bool chk( char c ) { return ( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' ); }

int main() {
    scanf( "%s", st + 1 );
    len = strlen( st + 1 ); st[++len] = 'A';
    int cur = 0, nmax = 1;
    for( int i = 1; i <= len; ++i ) if( chk( st[i] ) ) nmax = max( nmax, i - cur ), cur = i;
    printf( "%d\n", nmax );
    return 0;
}
