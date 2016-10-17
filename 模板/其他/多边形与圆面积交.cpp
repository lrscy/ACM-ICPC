#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const double INF = 1000000000000;
const double eps = 1e-12;
const double PI = acos( -1.0 );
const int MAXN = 100009;
const int MOD = 1000000007;

struct Point {
    double x,y;
    Point(){}
    Point( double xx, double yy ) { x = xx; y = yy; }
    Point operator - ( Point s ) { return Point( x - s.x, y - s.y ); }
    Point operator + ( Point s ) { return Point( x + s.x, y + s.y ); }
    double operator * ( Point s ) { return x * s.x + y * s.y; }
    double operator ^ ( Point s ) { return x * s.y - y * s.x; }
}poi[MAXN];

double mmax( double a, double b ) { return a > b ? a : b; }
double mmin( double a, double b ) { return a < b ? a : b; }

double len( Point a ) { return sqrt( a * a ); }
double dist( Point a, Point b ) { return len( b - a ); }

double cross( Point a, Point b, Point c ) { return ( b - a ) ^ ( c - a ); }
double dot( Point a, Point b, Point c ) { return ( b - a ) * ( c - a ); }

double area( Point b, Point c, double r ) {
    Point a( 0.0, 0.0 );
    if( dist( b, c ) < eps ) return 0.0;
    double h = fabs( cross( a, b, c ) ) / dist( b, c );
    //两个端点都在圆的外面则分为两种情况
    //两个端点都在圆内的情况
    //一个端点在圆上一个端点在圆内的情况
    if( dist( a, b ) > r - eps && dist( a, c ) > r - eps ) {
        double angle = acos( dot( a, b, c ) / dist( a, b ) / dist( a, c ) );
        if( h > r - eps ) return 0.5 * r * r * angle;
        else if( dot( b, a, c ) > 0 && dot( c, a, b ) > 0 ) {
            double angle1 = 2 * acos( h / r );
            return 0.5 * r * r * fabs( angle - angle1 ) + 0.5 * r * r * sin( angle1 );
        } else return 0.5 * r * r * angle;
    } else if( dist( a, b ) < r + eps && dist( a, c) < r + eps ) {
        return 0.5 * fabs( cross( a, b, c ) );
    } else {
        //默认b在圆内
        if( dist( a, b ) > dist( a, c ) ) swap(b,c);
        //ab距离为0直接返回0
        if( fabs( dist( a, b ) ) < eps ) return 0.0;
        if( dot( b, a, c ) < eps ) {
            double angle1 = acos( h / dist( a, b ) );
            double angle2 = acos( h / r ) - angle1;
            double angle3 = acos( h / dist( a, c ) ) - acos( h / r );
            return 0.5 * dist( a, b ) * r * sin( angle2 ) + 0.5 * r * r * angle3;
        } else {
            double angle1 = acos( h / dist( a, b ) );
            double angle2 = acos( h / r );
            double angle3 = acos( h / dist( a, c ) ) - angle2;
            return 0.5 * r * dist( a, b ) * sin( angle1 + angle2 ) + 0.5 * r * r * angle3;
        }
    }
    return 0.0;
}

int main() {
    int n;
    double x, y, v, ang, t, g, r;
    while( ~scanf( "%lf%lf%lf%lf%lf%lf%lf", &x, &y, &v, &ang, &t, &g, &r ) &&
           x + y + v + ang + t + g + r ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%lf%lf", &poi[i].x, &poi[i].y );
        }
        poi[n] = poi[0];
        Point O( x, y );
        double tmp = sin( ang / 180 * PI );
        O.x += v * t * cos( ang / 180 * PI );
        if( t * g <= v ) O.y += ( v * tmp + ( v * tmp - g * t ) ) / 2 * t;
        else {
            double tt = v * tmp / g;
            O.y += ( v * tmp / 2 ) * tt;
            tt = t - tt;
            O.y -= ( g * tt * tt ) / 2;
        }
        for( int i = 0; i <= n; ++i ) poi[i] = poi[i] - O;
        O = Point( 0, 0 );
        double sum = 0;
        for( int i = 0; i < n; ++i ) {
            int j = i + 1;
            double s = area( poi[i], poi[j], r );
            if( cross( O, poi[i], poi[j] ) > 0 ) sum += s;
            else sum -= s;
        }
        printf( "%.2lf\n", fabs( sum ) );
    }
    return 0;
}
