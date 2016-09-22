#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 15;
const int MAXQ = 100000;

int dx[5] = { -1, 0, 1, 0 }, dy[5] = { 0, 1, 0, -1 };
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<PII> vec;
PII que[MAXQ], lost[MAXQ];

bool gao( int flag, int x, int y ) {
    int mf, me, cnt = 0;
    mf = me = 0;
    que[me++] = make_pair( x, y );
    while( mf != me ) {
        PII tp = que[mf++];
        if( mf >= MAXQ ) mf -= MAXQ;
        int tx = tp.first, ty = tp.second;
        vis[tx][ty] = true;
        for( int i = 0; i < 4; ++i ) {
            int xx = tx + dx[i], yy = ty + dy[i];
            if( str[xx][yy] == 'o' ) {
                if( !vis[xx][yy] ) {
                    que[me++] = make_pair( xx, yy );
                    if( me >= MAXQ ) me -= MAXQ;
                }
            } else if( str[xx][yy] != 'x' && str[xx][yy] != flag ) {
                str[xx][yy] = flag;
                ++cnt;
            }
        }
    }
    return cnt > 1;
}

int main() {
    int t;
    char st[MAXN];
    scanf( "%d", &t );
    for( int i = 0; i <= 10; ++i ) {
        str[0][i] = str[10][i] = 'x';
        str[i][0] = str[i][10] = 'x';
    }
    for( int ncas = 1; ncas <= t; ++ncas ) {
        gets( st ); vec.clear();
        memset( vis, false, sizeof( vis ) );
        for( int i = 1; i < 10; ++i ) {
            scanf( "%s", str[i] + 1 );
            str[i][10] = 'x'; str[i][11] = 0;
            for( int j = 1; j < 10; ++j ) {
                if( str[i][j] == 'o' ) vec.push_back( make_pair( i, j ) );
            }
        }
        bool flag = false;
        for( int i = 0; i < vec.size(); ++i ) {
            int x = vec[i].first, y = vec[i].second;
            if( !vis[x][y] && !gao( i, x, y ) ) {
                flag = true;
                break;
            }
        }
        printf( "Case #%d: ", ncas );
        if( flag ) puts( "Can kill in one move!!!" );
        else puts( "Can not kill in one move!!!" );
    }
    return 0;
}
