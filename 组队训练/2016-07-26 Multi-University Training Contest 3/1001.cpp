#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;

char str[MAXN];
string tstr, cstr = "4294967295";
unsigned long long n1, n2 = 4294967295;

int main() {
    int t;
    while( ~scanf( "%s", str ) ) {
        int len = strlen( str );
        if( strcmp( str, "0" ) == 0 || len > 10 ) {
            puts( "TAT" );
            continue;
        }
        sscanf( str, "%I64u", &n1 );
        if( n1 <= n2 ) {
            int tot = 0;
            while( n1 > 1 ) {
                n1 = ( unsigned long long )sqrt( 1.0 * n1 );
                ++tot;
            }
            printf( "%d\n", tot );
        } else puts( "TAT" );
    }
    return 0;
}
