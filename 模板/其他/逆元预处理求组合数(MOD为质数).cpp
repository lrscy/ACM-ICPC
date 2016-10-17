#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int INF = 0x7F7F7F7F;
const int MOD = 1e9 + 7;
const int MAXN = 100000 + 10;

LL fac[MAXN], inv[MAXN];

LL pmod( LL a, LL b ) {
    LL ans = 1;
    while( b ) {
        if( b & 1 ) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

LL _inv( LL x ) { return pmod( x, MOD - 2 ); }

int main() {
    fac[0] = inv[0] = 1;
    for( int i = 1; i < MAXN; ++i ) { fac[i] = fac[i - 1] * i; inv[i] = _inv( fac[i] ); }
    return 0;
}
