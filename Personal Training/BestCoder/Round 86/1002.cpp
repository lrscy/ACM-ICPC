#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN], c[MAXN];
int n, cnt;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        LL sum = 0;
        int nmax = 0, tmax = 0, ttmax = 0, ta = -1, tb = -1;
        cnt = 0;
        scanf( "%d", &n );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d", a + i );
            b[i] = abs( a[i] - a[i - 1] );
            if( i > 1 && b[i] >= nmax ) {
                ttmax = tmax; tmax = nmax; nmax = b[i];
                tb = ta; ta = i;
            } else if( i > 1 && b[i] >= tmax ) {
                ttmax = tmax; tmax = b[i];
                tb = i;
            }
        }
        if( ta == 2 ) sum += tmax;
        else sum += nmax;
        for( int i = 2; i < n; ++i ) {
            if( i == ta - 1 ) {
                if( i == tb ) sum += max( abs( a[i + 1] - a[i - 1] ) , ttmax );
                else sum += max( abs( a[i + 1] - a[i - 1] ), tmax );
            } else if( i == ta ) {
                if( i + 1 == tb ) sum += max( abs( a[i + 1] - a[i - 1] ) , ttmax );
                else sum += max( abs( a[i + 1] - a[i - 1] ), tmax );
            } else {
                sum += max( abs( a[i + 1] - a[i - 1] ) , nmax );
            }
        }
        if( ta == n ) sum += tmax;
        else sum += nmax;
        cout << sum << endl;
    }
    return 0;
}
