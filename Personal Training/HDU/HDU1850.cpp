#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int a[MAXN];
int n;

int main() {
    while( ~scanf( "%d", &n ) && n ) {
        int sum = 0, tot = 0;
        for( int i = 0; i < n; ++i ) {
            scanf( "%d", a + i );
            sum ^= a[i];
        }
        for( int i = 0; i < n; ++i ) {
            int tmp = sum ^ a[i];
            if( tmp < a[i] ) ++tot;
        }
        printf( "%d\n", tot );
    }
    return 0;
}
