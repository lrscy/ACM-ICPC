#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL gao(LL a,LL b,LL c) {
    if(a >= 2) return 3 * c + 2 * b + a;
    if(a == 1) {
        if( b >= 1 ) return 3 * c + 2 * b + a;
        if( b == 0 ) return 2 * c + a;
    }
    if( a == 0 ) {
        if( b >= 2 ) {
            if( c == 0) return b;
            else return 3 * c + 2 * b-2;
        }
        if( b == 1 ) return 2 * c + b;
        if( b == 0 ) return c;
    }
}

int main() {
    int a, b, c;
    scanf( "%d%d%d", &a, &b, &c);
    printf( "%lld\n", gao( a, b, c ) );
}
