#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN];
int n, m;

int main() {
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
    int cnt = 1;
    for( int i = 1; i < n; ++i ) {
        if( a[i] - a[i - 1] > m ) cnt = 1;
        else cnt++;
    }
    printf( "%d\n", cnt );
    return 0;
}
