#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;

string s[MAXN], pw;
int n, m;

int main() {
    cin >> n >> m;
    for( int i = 0; i < n; ++i ) cin >> s[i];
    cin >> pw;
    int len = pw.length(), p1, p2;
    p1 = p2 = 0;
    for( int i = 0; i < n; ++i ) {
        int tlen = s[i].length();
        if( tlen < len ) ++p1;
        if( tlen <= len ) ++p2;
    }
    ++p1;
    p1 = p1 + ( p1 - 1 ) / m * 5;
    p2 = p2 + ( p2 - 1 ) / m * 5;
    printf( "%d %d\n", p1, p2 );
    return 0;
}
