#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<double, double> PDD;
typedef pair<bool, PDD> PBP;
const int MAXN = 1e3 + 10;

double dis[MAXN][MAXN];
double x[MAXN], y[MAXN];
double w;
int fa[MAXN];
int n;

int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }

PBP gao( double mid ) {
    for( int i = 0; i <= n + 1; ++i ) fa[i] = i;
    for( int i = 1; i <= n; ++i ) {
        for( int j = i + 1; j <= n; ++j )
            if( dis[i][j] <= mid )
                if( mfind( i ) != mfind( j ) ) fa[mfind( i )] = mfind( j );
    }
    for( int i = 1; i <= n; ++i ) if( x[i] <= mid && mfind( 0 ) != mfind( i ) ) fa[mfind( 0 )] = mfind( i );
    for( int i = 1; i <= n; ++i ) if( w - x[i] <= mid && mfind( n + 1 ) != mfind( i ) ) fa[mfind( n + 1 )] = mfind( i );
    if( mfind( 0 ) == mfind( n + 1 ) ) return make_pair( true, make_pair( 0, 0 ) );
    for( int i = 1; i <= n; ++i ) {
        for( int j = 1; j <= n; ++j )
            if( mfind( 0 ) == mfind( i ) && mfind( j ) == mfind( n + 1 ) )
                if( dis[i][j] <= 2 * mid )
                    return make_pair( true, make_pair( ( x[i] + x[j] ) / 2, ( y[i] + y[j] ) / 2 ) );
    }
    for( int i = 1; i <= n; ++i ) if( w - x[i] <= 2 * mid && mfind( 0 ) == mfind( i ) ) return make_pair( true, make_pair( ( x[i] + w ) / 2, y[i] ) );
    for( int i = 1; i <= n; ++i ) if( x[i] <= 2 * mid && mfind( n + 1 ) == mfind( i ) ) return make_pair( true, make_pair( x[i] / 2, y[i] ) );
    return make_pair( false, make_pair( -1, -1 ) );
}

int main() {
//    freopen( "froggy.in", "r", stdin );
//    freopen( "froggy.out", "w+", stdout );
    scanf( "%lf%d", &w, &n );
    for( int i = 1; i <= n; ++i ) scanf( "%lf%lf", x + i, y + i );
    if( n == 0 ) { printf( "%.10f 0\n", w / 2 ); return 0; }
    for( int i = 1; i <= n; ++i ) {
        for( int j = 1; j <= n; ++j )
            dis[i][j] = dis[j][i] = sqrt( 1. * ( x[j] - x[i] ) * ( x[j] - x[i] ) + 1. * ( y[j] - y[i] ) * ( y[j] - y[i] ) );
    }
    double low = 0, high = w;
    PDD ans;
    for( int i = 0; i < 50; ++i ) {
        double mid = ( low + high ) / 2;
        PBP tmp = gao( mid );
        if( tmp.first ) high = mid;
        else low = mid;
    }
    ans = gao( high ).second;
    printf( "%.10f %.10f\n", ans.first, ans.second );
    return 0;
}
