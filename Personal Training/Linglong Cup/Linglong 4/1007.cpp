#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

set<PII> s;
int n, a, b;

int gcd( int x, int y ) { return y == 0 ? x : gcd( y, x % y ); }

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        s.clear();
        scanf( "%d%d%d", &a, &b, &n );
        for( int i = 0, x, y; i < n; ++i ) {
            scanf( "%d%d", &x, &y );
            int tx = x - a, ty = y - b;
            int tg = gcd( tx, ty );
            tx /= tg; ty /= tg;
            s.insert( PII( tx, ty ) );
        }
        printf( "%d\n", ( int )s.size() );
    }
    return 0;
}
