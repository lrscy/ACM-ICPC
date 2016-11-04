#include <bits/stdc++.h>
using namespace std;

int num[110];
int d, s, t, pos;

int gao() {
    int tn = d, cnt = 0;
    while( tn ) {
        num[pos++] = ( tn & 1 );
        if( tn & 1 ) ++cnt;
        tn >>= 1;
    }
    num[pos] = 0;
    return cnt;
}

int gao2() {
    int n = 0;
    for( int i = pos - 1; i >= 0; --i ) {
        n = ( n << 1 ) + num[i];
    }
    return n;
}

int main() {
    int tt;
    scanf( "%d", &tt );
    for( int ncas = 1; ncas <= tt; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( num, 0, sizeof( num ) );
        pos = 0;
        scanf( "%d%d%d", &d, &s, &t );
        ++d;
        int tmp = gao();
        if( s <= tmp && tmp <= t ) {
            printf( "%d\n", d );
        } else if( tmp > t ) {
            int cnt = -1;
            for( int i = 0; i < pos; ++i ) if( num[i] == 0 ) { cnt = i; break; }
            if( cnt == -1 ) cnt = pos++;
            for( int i = cnt - 1; i >= 0 && tmp >= t; --i ) {
                if( num[i] == 1 ) { num[i] = 0; --tmp; }
            }
            num[cnt] = 1; ++tmp;
            printf( "%d\n", gao2() );
        } else if( tmp < s ) {
            for( int i = 0; i < pos && tmp < s; ++i ) {
                if( num[i] == 0 ) { num[i] = 1; ++tmp; }
            }
            printf( "%d\n", gao2() );
        }
    }
    return 0;
}
