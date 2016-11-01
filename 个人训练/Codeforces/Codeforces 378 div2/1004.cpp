#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
typedef pair<int, int> PII;

struct Node {
    int a, b, x, y, sum;
    void init() { a = b = x = y = sum = 0; }
};
map<PII, Node> mp;
int a[5];
int n;

void gao( int pos, int x, int y, int z ) {
    PII tmp = make_pair( x, y );
    if( mp.count( tmp ) ) {
//        cout << pos << " " << x << " " << y << " " << z << " " << mp[tmp].a << " " << mp[tmp].b << " " << mp[tmp].x << " " << mp[tmp].y << " " << mp[tmp].sum << endl;
        if( z >= mp[tmp].a ) {
            if( pos == mp[tmp].x ) return ;
            mp[tmp].b = mp[tmp].a;
            mp[tmp].a = z;
            mp[tmp].y = mp[tmp].x;
            mp[tmp].x = pos;
            mp[tmp].sum = mp[tmp].a + mp[tmp].b;
        } else if( z >= mp[tmp].b ) {
            if( pos == mp[tmp].y ) return ;
            mp[tmp].b = z;
            mp[tmp].y = pos;
            mp[tmp].sum = mp[tmp].a + mp[tmp].b;
        }
    } else {
        Node tn = { z, 0, pos, 0, z };
        mp[tmp] = tn;
    }
}

int main() {
    mp.clear();
    int nmax = 0;
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d%d%d", a, a + 1, a + 2 );
        sort( a, a + 3 );
        gao( i, a[0], a[1], a[2] );
        gao( i, a[0], a[2], a[1] );
        gao( i, a[1], a[2], a[0] );
    }
    auto tt = mp.begin();
    for( auto it = mp.begin(); it != mp.end(); ++it ) {
//        cout << it->first.first << " " << it->first.second << " " << it->second.a << " " << it->second.b << " " << it->second.x << " " << it->second.y << " " << it->second.sum << endl;
        int tmax = min( ( it->second ).sum, min( ( it->first ).first, ( it->first ).second ) );
        if( nmax < tmax ) { nmax = tmax; tt = it; }
    }
    if( ( tt->second ).b == 0 ) printf( "1\n%d\n", ( tt->second ).x );
    else {
        int tx = tt->second.x, ty = tt->second.y;
        printf( "2\n%d %d\n", min( tx, ty ), max( tx, ty ) );
    }
    return 0;
}
