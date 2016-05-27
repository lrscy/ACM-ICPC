#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 10;

int table[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int dp[MAXN][2][2][2], vis[MAXN][2][2][2];
int n, mod, ncas;

void add( int &a, LL b ) {
    a = ( a + b ) % mod;
    return ;
}

int gao( int res, int a, int b, int c ) { ;
    if( !b && !c ) {
        if( res == 0 && !a ) return 1;
        else if( a && table[1] == res ) return 1;
        return 0;
    }
    int &ret = dp[res][a][b][c];
    if( vis[res][a][b][c] == ncas ) return ret;
    vis[res][a][b][c] = ncas;
    ret = 0;
    if( b && c ) {
        for( int i = 0; i < 10; ++i ) {
            for( int j = 0; j < 10; ++j ) {
                int sum = table[i] + table[j] + table[( i + j + a ) % 10];
                if( sum > res ) continue;
                bool nxt = ( i + j + a ) >= 10;
                add( ret, gao( res - sum, nxt, 1, 1 ) );
                if( i ) add( ret, gao( res - sum, nxt, 0, 1 ) );
                if( j ) add( ret, gao( res - sum, nxt, 1, 0 ) );
                if( i && j ) add( ret, gao( res - sum, nxt, 0, 0 ) );
            }
        }
    } else if( b ) {
        for( int i = 0; i < 10; ++i ) {
            int sum = table[i] + table[( i + a ) % 10];
            if( sum > res ) continue;
            bool nxt = ( i + a ) >= 10;
            add( ret, gao( res - sum, nxt, 1, 0 ) );
            if( i ) add( ret, gao( res - sum, nxt, 0, 0 ) );
        }
    } else if( c ) {
        for( int i = 0; i < 10; ++i ) {
            int sum = table[i] + table[( i + a ) % 10];
            if( sum > res ) continue;
            bool nxt = ( i + a ) >= 10;
            add( ret, gao( res - sum, nxt, 0, 1 ) );
            if( i ) add( ret, gao( res - sum, nxt, 0, 0 ) );
        }
    }
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    for( ncas = 1; ncas <= t; ++ncas ) {
        scanf( "%d%d", &n, &mod );
        int ans = gao( n - 3, 0, 1, 1 );
        printf( "Case #%d: %d\n", ncas, ans );
    }
    return 0;
}
