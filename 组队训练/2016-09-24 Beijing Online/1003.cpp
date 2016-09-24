#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

char line[MAXN];
int len;
map<string, int> mp;

bool chc( int p ) { return ( line[p] != ' ' && line[p] != ',' && line[p] != '.' ); }
bool chs( int p ) { return ( line[p] == ' ' || line[p] == ',' || line[p] == '.' ); }

string getnextword( int &p1, int &type ) {
    char str[MAXN];
    int p2 = p1;
    type = 0;
    while( chc( p2 ) && p2 < len ) ++p2;
    while( chs( p2 ) && p2 < len ) {
        if( line[p2] != ' ' ) type = 1;
        line[p2] = 0;
        ++p2;
    }
    sscanf( line + p1, "%s", str );
    p1 = p2;
    return str;
}

int main() {
    while( NULL != fgets( line, MAXN, stdin ) ) {
        if( !strcmp( line, "####\n" ) ) break;
        do {
            int type = 1, p1 = 0;
            string s1, s2, s;
            len = strlen( line );
            line[--len] = 0;
            while( chs( --len ) ) line[len] = 0;
            ++len;
            while( chs( p1 ) ) ++p1;
            while( type != 0 && p1 < len ) s1 = getnextword( p1, type );
            while( p1 < len ) {
                s2 = getnextword( p1, type );
                s = s1 + " " + s2;
                ++mp[s];
                while( type != 0 && p1 < len ) s2 = getnextword( p1, type );
                s1.swap( s2 );
            }
        } while( NULL != fgets( line, MAXN, stdin ) && strcmp( "####\n", line ) );
        int ans = -1;
        string anss;
        for( map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it ) {
            if( it->second > ans ) {
                ans = it->second;
                anss = it->first;
            }
        }
        printf( "%s:%d\n", anss.c_str(), ans );
        mp.clear();
    }
    return 0;
}
