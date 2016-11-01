#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN];

int main() {
    int n, ans1 = 0, ans2 = 0, nmax1 = 0, nmax2 = 0;
    scanf( "%d", &n );
    int flag = 0;
    int c1, c2; c1 = c2 = 0;
    for( int i = 0, l, r; i < n; ++i ) {
        scanf( "%d%d", a + i, b + i );
        c1 += a[i]; c2 += b[i];
    }
    int nmax = abs( c1 - c2 );
    for( int i = 0; i < n; ++i ) {
        int t1 = c1 - a[i] + b[i];
        int t2 = c2 - b[i] + a[i];
        if( abs( t1 - t2 ) > nmax ) {
            nmax = abs( t1 - t2 );
            flag = i + 1;
        }
    }
    printf( "%d\n", flag );
    return 0;
}
