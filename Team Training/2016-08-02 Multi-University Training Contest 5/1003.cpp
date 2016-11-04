#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;

int a[MAXN];
int n;

int main() {
    while( ~scanf( "%d", &n ) ) {
        int tot = 0;
        LL sum = 0;
        bool flag = false;
        for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
        for( int i = n - 1; i >= 0; --i ) {
            if( !flag ) {
                if( a[i] >= 0 ) ++tot;
                else {
                    sum = a[i];
                    flag = true;
                }
            } else {
                sum += a[i];
                if( sum >= 0 ) { ++tot; flag = false; }
            }
        }
        printf( "%d\n", tot );
    }
    return 0;
}
