#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL a, b, c, nmax = 0, ans = 0;
    scanf( "%I64d%I64d%I64d", &a, &b, &c );
    if( nmax < a ) nmax = a;
    if( nmax < b ) nmax = b;
    if( nmax < c ) nmax = c;
    --nmax;
    if( nmax > a ) ans += nmax - a;
    if( nmax > b ) ans += nmax - b;
    if( nmax > c ) ans += nmax - c;
    printf( "%I64d\n", ans );
    return 0;
}
