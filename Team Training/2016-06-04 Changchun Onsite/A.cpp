#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[20], b[20] = { 1, 5, 10, 50, 100, 500, 1000 };
int c[20], d[20];
int p;

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        memset( c, 0, sizeof( c ) );
        scanf( "%d", &p );
        int cnt = 0;
        for( int i = 0; i < 10; ++i ) {
            scanf( "%d", a + i );
            if( i == 3 || i == 6 || i == 9 ) c[cnt - 1] += 2 * a[i];
            else c[cnt++] = a[i];
        }
        for( int i = 0; i < cnt; ++i ) d[i]= c[i];
        int n = p;
        for( int i = 6; i >= 0; --i ) {
            int tn = n / b[i];
            if( tn > c[i] ) tn = c[i];
            n -= tn * b[i];
            c[i] -= tn;
        }
        if( n ) { puts( "-1" ); continue; }
//        for( int i = 0; i < 7; ++i ) cout << d[i] << "\t"; cout << endl;
//        for( int i = 0; i < 7; ++i ) cout << c[i] << "\t"; cout << endl;
//        for( int i = 0; i < 7; ++i ) cout << d[i] - c[i] << "\t"; cout << endl;
        while( true ) {
            bool flag = false;
            for( int i = 0; i < 6; ++i ) {
                for( int j = i + 1; j < 7; ++j ) {
                    int ti = b[j] / b[i];
                    int tn = c[i] / ti;
                    if( d[j] - c[j] && tn ) flag = true;
                    if( tn > ( d[j] - c[j] ) ) tn = d[j] - c[j];
                    c[i] -= tn * ti;
                    c[j] += tn;
                }
            }
            if( !flag ) break;
        }
//        for( int i = 0; i < 7; ++i ) cout << d[i] << "\t"; cout << endl;
//        for( int i = 0; i < 7; ++i ) cout << c[i] << "\t"; cout << endl;
//        for( int i = 0; i < 7; ++i ) cout << d[i] - c[i] << "\t"; cout << endl;
        for( int i = 0; i < 7; ++i ) c[i] = d[i] - c[i];
        a[0] = c[0]; a[1] = c[1];
        if( c[2] - a[2] > 0 ) {
            int t = c[2] - a[2];
            a[3] = t / 2;
            if( t % 2 ) { ++a[3]; --a[2]; }
        } else { a[2] = c[2]; a[3] = 0; }
        if( a[2] < 0 && a[2] % 2 ) --a[2];
        a[4] = c[3];
        if( c[4] - a[5] > 0 ) {
            int t = c[4] - a[5];
            a[6] = t / 2;
            if( t % 2 ) { ++a[6]; --a[5]; }
        } else { a[5] = c[4]; a[6] = 0; }
        if( a[5] < 0 && a[5] % 2 ) --a[5];
        a[7] = c[5];
        if( c[6] - a[8] > 0 ) {
            int t = c[6] - a[8];
            a[9] = t / 2;
            if( t % 2 ) { ++a[9]; --a[8]; }
        } else { a[8] = c[6]; a[9] = 0; }
        if( a[8] < 0 && a[8] % 2 ) --a[8];
        int ans = 0;
//        for( int i = 0; i < 10; ++i ) cout << a[i] << " "; cout << endl;
        for( int i = 0; i < 10; ++i ) ans += a[i];
        printf( "%d\n", ans );
    }
    return 0;
}
