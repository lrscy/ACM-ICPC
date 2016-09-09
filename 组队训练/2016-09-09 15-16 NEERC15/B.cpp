#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

queue<string> que;

void gao( string str, LL num ) {
    string ts = "";
    LL tnum = num;
    while( num ) {
        ts += '0' + ( num & 1 );
        num >>= 1;
    }
    reverse( str.begin(), str.end() );
    for( int i = 0; i < str.length(); ++i ) {
        if( str[i] != ts[i] ) return ;
    }
    reverse( ts.begin(), ts.end() );
    printf( "%I64d %s\n", tnum, ts.c_str() );
    return ;
}

int main() {
    freopen( "out.txt", "w+", stdout );
    string st = "0";
    LL num;
    que.push( st );
    for( ; ; ) {
        string tst = que.front(); que.pop();
        sscanf( tst.c_str(), "%I64d", &num );
        gao( tst.substr( 1 ), num );
        if( tst.length() > 19 ) break;
        if( num != 0 ) que.push( tst + "0" );
        que.push( tst + "1" );
    }
    return 0;
}
