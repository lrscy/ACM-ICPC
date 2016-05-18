#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1000 + 10;
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

bool matrix[MAXN << 2][MAXN << 2];
int n, m, ans;

void updatey( int rt, int left, int right, int t, int y1, int y2 ) {
	if( left == y1 && y2 == right ) { matrix[t][rt] ^= 1; return ; }
	int mid = ( left + right ) >> 1;
	if( y2 <= mid ) updatey( lson, t, y1, y2 );
	else if( y1 > mid ) updatey( rson, t, y1, y2 );
	else {
		updatey( lson, t, y1, mid );
		updatey( rson, t, mid + 1, y2 );
	}
	return ;
}

void updatex( int rt, int left, int right, int x1, int y1, int x2, int y2 ) {
	if( left == x1 && x2 == right ) { updatey( 1, 1, n, rt, y1, y2 ); return; }
	int mid = ( left + right ) >> 1;
	if( x2 <= mid ) updatex( lson, x1, y1, x2, y2 );
	else if( x1 > mid ) updatex( rson, x1, y1, x2, y2 );
	else {
		updatex( lson, x1, y1, mid, y2 );
		updatex( rson, mid + 1, y1, x2, y2 );
	}
	return ;
}

void queryy( int rt, int left, int right, int t, int y ) {
	ans ^= matrix[t][rt];
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	if( y <= mid ) queryy( lson, t, y );
	else queryy( rson, t, y );
	return ;
}

void queryx( int rt, int left, int right, int x, int y ) {
	queryy( 1, 1, n, rt, y );
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	if( x <= mid ) queryx( lson, x, y );
	else queryx( rson, x, y );
	return ;
}

int main() {
	int t, a, b, c, d;
	char st[2];
	scanf( "%d", &t );
	while( t-- ) {
		memset( matrix, 0, sizeof( matrix ) );
		scanf( "%d%d", &n, &m);
		while( m-- ) {
			scanf( "%s", st );
			if( st[0] == 'C' ) {
				scanf( "%d%d%d%d", &a, &b, &c, &d );
				updatex( 1, 1, n, a, b, c, d );
			} else {
				scanf( "%d%d", &a, &b );
				ans = 0;
				queryx( 1, 1, n, a, b );
				printf( "%d\n", ans );
			}
		}
		if( t ) puts( "" );
	}
	return 0;
}
