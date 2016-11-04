#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
#define INF 0x3F3F3F3F

const int sta[]={ 0, 3, 12, 48, 192, 15, 51, 195, 60, 204, 240, 63, 207, 243, 252, 255 };
int dp[300][35], dis[35][35], info[10];
map<string, int> nmap;

int lowbit( int x ) {
    return ( x & ( -x ) );
}

int bit( int x ) {
    x = lowbit( x );
    int res;
    for( res = 0; x; x >>= 1, ++res );
    return res - 1;
}

int main() {
    int n, m, ans;
    int ta, tb, c;
    string s, t;
    while( ~scanf( "%d%d", &n, &m ) && ( n || m ) ) {
        memset( dis, 0x3F, sizeof( dis ) );
        memset( dp, 0x3F, sizeof( dp ) );
        nmap.clear();
        for( int i = 0; i < n; ++i ) {
            cin >> s;
            nmap[s] = i;
            dis[i][i] = 0;
        }
        for( int i = 0; i < m; ++i ) {
            cin >> s >> t >> c;
            ta = nmap[s]; tb = nmap[t];
            dis[ta][tb] = dis[tb][ta] = min( dis[ta][tb], c );
        }
        for( int k = 0; k < n; ++k ) {
            for( int i = 0; i < n; ++i )
                for( int j = 0; j < n; ++j )
                    dis[i][j] = min( dis[i][j], dis[i][k] + dis[k][j] );
        }
        for( int i = 0; i < 8; ++i ) {
            cin >> s;
            info[i] = nmap[s];
            for( int j = 0; j < n; ++j ) {
                dp[1 << i][j] = dis[info[i]][j];
            }
        }
        for( int i = 0; i < 256; ++i ) {
            if( i & ( i - 1 ) == 0 ) continue;
            c = 0;
            for( int j = 0; j < n; ++j ) {
                for( int sub = i; sub; sub = ( sub - 1 ) & i ) {
                    dp[i][j] = min( dp[i][j], dp[sub][j] + dp[i - sub][j] );
                }
                if( dp[i][j] < dp[i][c] ) c = j;
            }
            for( int j = 0; j < n; ++j ) {
                for( int k = 0; k < n; ++k ) {
                    dp[i][k] = min( dp[i][k], dp[i][j] + dis[j][k] );
                }
            }
        }
        ans = INF;
        for( int p1 = 0; p1 < 16; ++p1 ) {
            for( int p2 = 0; p2 < 16; ++p2 ) {
                for( int p3 = 0; p3 < 16; ++p3 ) {
                    for ( int p4 = 0; p4 < 16; ++p4 ) {
                        if( sta[p1] + sta[p2] + sta[p3] + sta[p4] == 255 ) {
                            for( int i = 0; i < n; ++i ) {
                                int tmp = 0;
                                if( sta[p1] ) tmp += dp[sta[p1]][info[bit( sta[p1] )]];
                                if( sta[p2] ) tmp += dp[sta[p2]][info[bit( sta[p2] )]];
                                if( sta[p3] ) tmp += dp[sta[p3]][info[bit( sta[p3] )]];
                                if( sta[p4] ) tmp += dp[sta[p4]][info[bit( sta[p4] )]];
                                ans = min( ans, tmp );
                            }
                        }
                    }
                }
            }
        }
        printf( "%d\n", ans );
    }
    return 0;
}
