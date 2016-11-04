#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL a, b, c, t;
    scanf( "%I64d", &a );
    if( a == 1 || a == 2 ) { puts( "-1" ); return 0; }
    if( a & 1 ) {
        t = a * a / 2;
        b = t;
        c = t + 1;
    } else {
        t = a / 2;
        b = t * t - 1;
        c = t * t + 1;
    }
    printf( "%I64d %I64d\n", b, c );
    return 0;
}
