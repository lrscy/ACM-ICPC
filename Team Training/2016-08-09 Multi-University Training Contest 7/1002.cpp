#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, m;

LL gcd( LL a, LL b ) {
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

int main() {
    while( ~scanf( "%I64d%I64d", &n, &m ) && n + m ) {
        LL ta = n * ( m - 1 );
        LL tb = m * m;
        if( ta == 0 ) { puts( "0/1" ); continue; }
        LL tt = gcd( ta, tb );
        ta /= tt; tb /= tt;
        printf( "%I64d/%I64d\n", ta, tb );
    }
    return 0;
}
