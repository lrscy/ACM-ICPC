#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN];
int num[30][MAXN], cnt[30][MAXN];
int n, q;

void build( int left, int right, int dep ) {
	if( left == right ) return ;
	int mid = ( left + right ) >> 1, ncnt = mid - left + 1;
	for( int i = left; i <= right; ++i ) if( num[dep][i] < a[mid] ) --ncnt;
	int lp = left, rp = mid + 1;
	for( int i = left; i <= right; ++i ) {
		if( i == left ) cnt[dep][i] = 0;
		else cnt[dep][i] = cnt[dep][i - 1];
		if( num[dep][i] < a[mid] ) {
			++cnt[dep][i];
			num[dep + 1][lp++] = num[dep][i];
		} else if( num[dep][i] > a[mid] ) {
			num[dep + 1][rp++] = num[dep][i];
		} else {
			if( ncnt ) {
				--ncnt;
				++cnt[dep][i];
				num[dep + 1][lp++] = num[dep][i];
			} else num[dep + 1][rp++] = num[dep][i];
		}
	}
	build( left, mid, dep + 1 );
	build( mid + 1, right, dep + 1 );
	return ;
}

int query( int l, int r, int k, int left, int right, int dep ) {
	if( l == r ) return num[dep][l];
	int mid = ( left + right ) >> 1, tmp;
	int s, ss;
	if( l == left ) { s = cnt[dep][r]; ss = 0; }
	else { s = cnt[dep][r] - cnt[dep][l - 1]; ss = cnt[dep][l - 1]; }
	if( s >= k ) {
		l = left + ss;
		r = left + ss + s - 1;
		tmp = query( l, r, k, left, mid, dep + 1 );
	} else {
		l = mid + 1 + l - left - ss;
		r = mid + 1 + r - left - cnt[dep][r];
		tmp = query( l, r, k - s, mid + 1, right, dep + 1 );
	}
	return tmp;
}

int main() {
	int x, y, k;
	while( ~scanf( "%d%d", &n, &q ) ) {
		for( int i = 1; i <= n; ++i ) { scanf( "%d", a + i ); num[0][i] = a[i]; }
		sort( a + 1, a + n + 1 );
		build( 1, n, 0 );
		while( q-- ) {
			scanf( "%d%d%d", &x, &y, &k );
			printf( "%d\n", query( x, y, k, 1, n, 0 ) );
		}
	}
	return 0;
}
