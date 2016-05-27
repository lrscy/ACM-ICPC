#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    int t;
    cin >> t;
    for( int ncas = 1; ncas <= t; ++ncas ) {
        cout << "Case #" << ncas << ": ";
        cin >> a;
        int pos = 0, cnt = 0;
        bool flag = true;
        for( int i = 0; i < a.length(); ++i ) if( a[i] != 'c' && a[i] != 'f' ) { flag = false; break; }
        if( !flag ) { cout << -1 << endl; continue; }
        while( a[pos] == 'f' ) ++pos;
        b = a.substr( pos, a.length() ) + a.substr( 0, pos );
        if( pos == b.length() ) {
            cout << ( b.length() + 1 ) / 2 << endl;
            continue;
        }
        flag = true;
        for( int i = 0; i < b.length(); ++i ) if( b[i] == 'c' ) {
            if( i + 2 >= b.length() || b[i + 1] != 'f' || b[i + 2] != 'f' ) { flag = false; break; }
            ++cnt;
        }
        if( flag ) cout << cnt << endl;
        else cout << -1 << endl;
    }
    return 0;
}
