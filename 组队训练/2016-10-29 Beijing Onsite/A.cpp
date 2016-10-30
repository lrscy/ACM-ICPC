#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e4 + 10;

struct Node { int x, y, w, h; };
Node node[MAXN];
LL tot;
int n, r;

LL area( int mid ) {
    LL ret = 0;
    for( int i = 0; i < n; ++i ) {
        if( mid >= node[i].x + node[i].w ) ret += 1LL * node[i].w * node[i].h;
        else if( mid > node[i].x ) ret += 1LL * ( mid - node[i].x ) * node[i].h;
    }
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        tot = 0;
        scanf( "%d%d", &r, &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%d%d%d%d", &node[i].x, &node[i].y, &node[i].w, &node[i].h );
            if( node[i].x + node[i].w > r ) node[i].w = r - node[i].x;
            if( node[i].y < node[i].h ) node[i].h = node[i].y;
            tot += 1LL * node[i].w * node[i].h;
        }
        int low = 0, high = r, ans = -1;
        while( low < high ) {
            int mid = ( low + high ) >> 1;
            if( area( mid ) * 2 >= tot ) high = mid;
            else low = mid + 1;
        }
        LL ar = area( high );
        ans = low = high; high = r;
        while( low <= high ) {
            int mid = ( low + high ) >> 1;
            if( area( mid ) <= ar ) ans = mid, low = mid + 1;
            else high = mid - 1;
        }
        printf( "%d\n", ans );
    }
    return 0;
}
