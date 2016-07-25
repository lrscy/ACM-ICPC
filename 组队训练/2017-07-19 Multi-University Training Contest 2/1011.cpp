#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN];
int n, na, nb;

int main() {
    int t, tmp;
    scanf( "%d", &t );
    while( t-- ) {
        priority_queue<int, vector<int>, greater<int> > pq;
        na = nb = 0;
        int sum = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%d", &tmp );
            if( tmp & 1 ) na++;
            sum += tmp;
        }
        sum -= na;
        if( na == 0 ) { printf( "%d\n", sum ); continue; }
        int ans = sum / 2 / na * 2 + 1;
        printf( "%d\n", ans );
    }
    return 0;
}
