#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int s[MAXN], vec[MAXN];
int n;

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        scanf( "%d", &n );
        int cnt = 0, tn = 0, a;
        bool flag = false;
        for( int i = 0; i < n; ++i ) {
            scanf( "%d", &a );
            if( a == 0 ) ++cnt;
            else { flag = true; s[tn++] = a - cnt; }
        }
        n = tn; tn = 0;
        vec[tn++] = s[0];
        for( int i = 1; i < n; ++i ) {
            int pos = lower_bound( vec, vec + tn, s[i] ) - vec; 
            vec[pos] = s[i];
            tn = max( tn, pos + 1 );
        }
        if( !flag ) tn = 0;
        printf( "%d\n", tn + cnt );
    }
    return 0;
}
