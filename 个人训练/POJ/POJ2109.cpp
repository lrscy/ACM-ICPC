#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    double n,p;
    while( ~scanf( "%lf%lf", &n, &p ) ) {
        printf( "%.0f\n", pow( p, 1.0 / n ) );
    }
    return 0;
}
