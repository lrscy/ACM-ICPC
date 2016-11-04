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
typedef Point pVector;
typedef vector<Point> Polygon;

bool OnSegment( Point p, Point a, Point b ) {
    if( sig( ( p - a ) * ( p - b ) ) ) return 0;
    return sig( a.x - p.x ) * sig( b.x - p.x ) <= 0 && sig( a.y - p.y ) * sig( b.y - p.y ) <= 0;
}

int isPointInPolygon( Point p, Polygon poly ) {
    int wn = 0;
    int n = poly.size();
    for( int i = 0; i < n; ++i ) {
        if( OnSegment( p, poly[i], poly[( i + 1 ) % n] ) ) return 0;
        int k = sig( ( poly[( i + 1 ) % n] - poly[i] ) ^ ( p - poly[i] ) );
        int d1 = sig( poly[i].y - p.y );
        int d2 = sig( poly[( i + 1 ) % n].y - p.y );
        if( k > 0 && d1 <= 0 && d2 > 0 ) ++wn;
        if( k < 0 && d2 <= 0 && d1 > 0 ) --wn;
    }
    return wn;
}

int main() {
    return 0;
}
