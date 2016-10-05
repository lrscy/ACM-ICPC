#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 10;

LL st[MAXN];
char op[MAXN];
char g[10][MAXN];
int n, m, c1, c2;

LL _sim( char *s, int len ) {
    LL tst[MAXN];
    int tc1, tc2;
    char top[MAXN];
    tc1 = tc2 = 0;
    int p = 0;
    while( p < len ) {
        if( s[p] == ' ' ) { ++p; continue; }
        if( s[p] == '*' ) { ++p; top[tc2++] = '*'; }
        else if( s[p] == '+' || s[p] == '-' ) {
            while( tc2 ) {
                LL ta = tst[--tc1], tb = tst[--tc1];
                if( top[tc2 - 1] == '*' ) tst[tc1++] = ta * tb;
                else if( top[tc2 - 1] == '+' ) tst[tc1++] = ta + tb;
                else tst[tc1++] = tb - ta;
                --tc2;
            }
            top[tc2++] = s[p];
            ++p;
        } else {
            int j = p; while( s[j] != ' ' && j < len ) ++j;
            int tn;
            sscanf( s + p, "%d", &tn );
            tst[tc1++] = tn;
            p = j;
        }
    }
    while( tc2 ) {
        LL ta = tst[--tc1], tb = tst[--tc1];
        if( top[--tc2] == '+' ) tst[tc1++] = tb + ta;
        else if( top[tc2] == '-' ) tst[tc1++] = tb - ta;
        else tst[tc1++] = ta * tb;
    }
    return tst[0];
}

int main() {
    while( ~scanf( "%d%d", &n, &m ) && n + m ) {
        c1 = c2 = 0;
        fgets( g[0], MAXN, stdin );
        for( int i = 0; i < n; ++i ) fgets( g[i], MAXN, stdin ), g[i][strlen( g[i] ) - 1] = 0;
        int len = strlen( g[0] );
        if( n == 1 ) st[c1++] = _sim( g[0], len );
        else {
            for( int i = 0, j; i < len; ++i ) {
                if( g[1][i] == ' ' ) continue;
                if( g[1][i] == '\\' || g[1][i] == '/' ) continue;
                if( n == 3 && g[1][i] == '=' ) {
                    j = i; while( g[1][j] == '=' ) ++j;
                    LL ta = _sim( g[0] + i, j - i ), tb = _sim( g[2] + i, j - i );
                    st[c1++] = ta / tb;
                    i = j;
                } else if( g[0][i] == '_' ) {
                    j = i; while( g[0][j] == '_' ) ++j;
                    st[c1++] = ( LL )sqrt( 1. * _sim( g[1] + i, j - i ) );
                    i = j;
                } else {
                    if( g[1][i] == '+' || g[1][i] == '-' ) {
                        while( c2 ) {
                            LL ta = st[--c1], tb = st[--c1];
                            if( op[c2 - 1] == '*' ) st[c1++] = ta * tb;
                            else if( op[c2 - 1] == '+' ) st[c1++] = ta + tb;
                            else st[c1++] = tb - ta;
                            --c2;
                        }
                        op[c2++] = g[1][i];
                    } else if( g[1][i] == '*' ) {
                        op[c2++] = '*';
                    } else {
                        j = i; while( g[1][j] != ' ' && j < len ) ++j;
                        int tn;
                        sscanf( g[1] + i, "%d", &tn );
                        st[c1++] = tn;
                        i = j;
                    }
                }
            }
        }
        while( c2 ) {
            LL ta = st[--c1], tb = st[--c1];
            if( op[--c2] == '+' ) st[c1++] = ta + tb;
            else if( op[c2] == '-' ) st[c1++] = tb - ta;
            else st[c1++] = ta * tb;
        }
        printf( "%d\n", st[0] );
        fgets( g[0], MAXN, stdin );
    }
    return 0;
}
