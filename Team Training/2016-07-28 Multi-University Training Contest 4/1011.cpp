#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

string name[MAXN] = {
    "Baltimore Bullets",
    "Boston Celtics",
    "Chicago Bulls",
    "Cleveland Cavaliers",
    "Dallas Mavericks",
    "Detroit Pistons",
    "Golden State Warriors",
    "Houston Rockets",
    "L.A. Lakers",
    "Miami Heat",
    "Milwaukee Bucks",
    "Minneapolis Lakers",
    "New York Knicks",
    "Philadelphia 76ers",
    "Philadelphia Warriors",
    "Portland Trail Blazers",
    "Rochester Royals",
    "San Antonio Spurs",
    "Seattle Sonics",
    "St. Louis Hawks",
    "Syracuse Nats",
    "Washington Bullets"
};
int num[MAXN] = { 1, 17, 6, 1, 1, 3, 2, 2, 11, 3, 1, 5, 2, 2, 2, 1, 1, 5, 1, 1, 1, 1 };

int main() {
    int t;
    char str[MAXN];
    scanf( "%d", &t ); fgets( str, MAXN, stdin );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        fgets( str, MAXN, stdin );
        int len = strlen( str );
        str[len - 1] = 0;
        string s = str;
        bool flag = false;
        for( int i = 0; i < 23; ++i ) {
            if( name[i] == s ) {
                flag = true;
                printf( "%d\n", num[i] );
            }
        }
        if( !flag ) puts( "0" );
    }
    return 0;
}
