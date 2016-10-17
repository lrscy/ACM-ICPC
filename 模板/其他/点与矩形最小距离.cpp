#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double PI = acos( -1.0 );

int sig( double x ) {
    if( fabs( x ) < eps ) return 0;
    return x > 0 ? 1 : -1;
}

struct Point {
    double x, y;
    Point() {}
    Point( const double xx, const double yy ) { x = xx; y = yy; }
    Point operator + ( const Point &tp ) const { return Point( x + tp.x, y + tp.y ); }
    Point operator - ( const Point &tp ) const { return Point( x - tp.x, y - tp.y ); }
    double operator * ( const Point &tp ) const { return x * tp.x + y * tp.y; }
    double operator ^ ( const Point &tp ) const { return x * tp.y - y * tp.x; }
    bool operator < ( const Point &tp ) const {
        if( sig( x - tp.x ) ) return sig( x - tp.x ) < 0;
        else return sig( y - tp.y ) < 0;
    }
};
Point poi[5], cir, src;
double r;

double dist( const Point &a, const Point &b ) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt( dx * dx + dy * dy );
}

double dptol( const Point &a, const Point &b, const Point &c ) {
    double ret = 0;
    if( sig( ( c - b ) * ( a - b ) ) > 0 && sig( ( b - c ) * ( a - c ) ) > 0 )
        ret = fabs( ( b - a ) ^ ( c - a ) ) / dist( b, c );
    else ret = min( dist( a, b ), dist( a, c ) );
    return ret;
}

double dptor( const Point &a ) {
    double d1 = min( dptol( a, poi[0], poi[1] ), dptol( a, poi[0], poi[2] ) );
    double d2 = min( dptol( a, poi[1], poi[3] ), dptol( a, poi[2], poi[3] ) );
    return min( d1, d2 );
}

int main() {
    return 0;
}
