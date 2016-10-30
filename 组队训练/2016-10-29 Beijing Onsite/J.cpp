#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    char s[2];
    int x;
    while( ~scanf( "%d", &n ) ) {
        int cnt = 0, cur = 0, flag = -1;
        for( int i = 0; i < n; ++i ) {
            scanf( "%s", s );
            if( s[0] == 'S' ) { 
                if( cur ) ++cnt;
                ++cnt; cur = 0; flag = -1;
                continue;
            }
            scanf( "%d", &x );
            if( s[0] == 'C' ) { // flag = 0
                if( cur && ( flag != 0 || x <= cur ) ) { cur = 0; ++cnt; }
                if( x == 1 ) { 
                    cur = 1;
                    flag = 0;
                    continue;
                }
                if( cur + 1 == x && flag == 0 ) cur = x;
                else cur = 0;
                flag = 0;
            } else {
                if( cur && ( flag != 1 || x <= cur ) ) { cur = 0; ++cnt; }
                if( x == 1 ) {
                    cur = 1;
                    flag = 1;
                    continue;
                }
                if( cur + 1 == x && flag == 1 ) cur = x;
                else cur = 0;
                flag = 1;
            }
        }
        if( cur ) ++cnt;
        printf( "%d\n", cnt );
    }
    return 0;
}
