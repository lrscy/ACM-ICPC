#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf( "%d", &a );
    scanf( "%d:%d", &b, &c );
    if( c >= 60 ) c %= 10;
    if( a == 12 ) {
        if( b == 0 ) b = 10;
        else if( b > a ) {
            if( b / 10 == 1 ) b = 10;
            else if( b % 10 ) b %= 10;
            else b = 10;
        }
    }
    if( a == 24 ) {
        if( b >= a ) {
            if( b / 10 <= 2 ) b = b / 10 * 10;
            else b %= 10;
        }
    }
    printf( "%02d:%02d\n", b, c );
    return 0;
}
