#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 10;
const int MAXM = 1e3 + 10;

struct Tri {
    int a, b, c;
    LL cnt;
    Tri() {}
    Tri( int _a, int _b, int _c, LL _cnt ) : a( _a ), b( _b ), c( _c ), cnt( _cnt ) {}
    bool operator < ( const Tri &tri ) const {
        if( a != tri.a ) return a > tri.a;
        if( b != tri.b ) return b > tri.b;
        return c > tri.c;
    }
    bool operator != ( const Tri & tri ) const {
        return !( a == tri.a && b == tri.b && c == tri.c );
    }
}ans[MAXN];
PII pii[MAXN];
int bit[MAXM][MAXM];
int n, m, tn;

void add( int x, int y ) {
    for( int i = x; i < MAXM; i += i & -i ) {
        for( int j = y; j < MAXM; j += j & -j )
            ++bit[i][j];
    }
    return ;
}

int sum( int x, int y ) {
    int ret = 0;
    for( int i = x; i > 0; i -= i & -i ) {
        for( int j = y; j > 0; j -= j & -j )
            ret += bit[i][j];
    }
    return ret;
}

int main() {
    int t;
    scanf( "%d", &t );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        memset( pii, 0, sizeof( pii ) );
        memset( bit, 0, sizeof( bit ) );
        tn = 0;
        scanf( "%d%d", &n, &m );
        for( int i = 0, a, b; i < n; ++i ) {
            scanf( "%d%d", &a, &b );
            if( pii[b].first == 0 || pii[b].first < a ) pii[b] = PII( a, 1 );
            else if( pii[b].first == a ) ++pii[b].second;
        }
        for( int i = 0, a, b, c; i < m; ++i ) {
            scanf( "%d%d%d", &a, &b, &c );
            if( pii[c].first ) ans[tn++] = Tri( pii[c].first, a, b, pii[c].second );
        }
        sort( ans, ans + tn );
        int t = 0;
        for( int i = 1; i < tn; ++i ) {
            if( ans[i] != ans[t] ) ans[++t] = ans[i];
            else ans[t].cnt += ans[i].cnt;
        }
        tn = t + 1;
        LL tot = 0;
        for( int i = 0, s1, s2, s3, s4; i < tn; ++i ) {
            s1 = sum( ans[i].b - 1, ans[i].c - 1 );
            s2 = sum( ans[i].b - 1, MAXM - 1 );
            s3 = sum( MAXM - 1, ans[i].c - 1 );
            s4 = sum( MAXM - 1, MAXM - 1 );
            if( s4 - s2 - s3 + s1 == 0 ) tot += ans[i].cnt;
            add( ans[i].b, ans[i].c );
        }
        printf( "%I64d\n", tot );
    }
    return 0;
}
