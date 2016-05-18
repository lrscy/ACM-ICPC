#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 10;
#define w( i ) node[i].w
#define ls( i ) node[i].ls
#define rs( i ) node[i].rs

struct Node { int ls, rs, w; };
Node node[MAXN << 5];
int a[MAXN], b[MAXN], p[MAXN], root[MAXN];
int n, m, cnt;

bool cmp( const int &i, const int &j ) {
	return a[i] < a[j];
}

void insert( int &i, int left, int right, int w ) {
	node[++cnt] = node[i]; i = cnt;
	++w( i );
	if( left == right ) return ;
	int mid = ( left + right ) >> 1;
	if( w <= mid ) insert( ls( i ), left, mid, w );
	else insert( rs( i ), mid + 1, right, w );
	return ;
}

int query( int i, int j, int left, int right, int k ) {
	if( left == right ) return left;
	int t = w( ls( j ) ) - w( ls( i ) );
	int mid = ( left + right ) >> 1;
	if( t >= k ) return query( ls( i ), ls( j ), left, mid, k );
	else query( rs( i ), rs( j ), mid + 1, right, k - t );
}

int main() {
	int s, t, k;
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; ++i ) scanf( "%d", a + i ), p[i] = i;
	sort( p + 1, p + 1 + n, cmp );
	for( int i = 1; i <= n; ++i ) b[p[i]] = i;
	cnt = 0; root[0] = 0;
	for( int i = 1; i <= n; ++i ) {
		root[i] = root[i - 1];
		insert( root[i], 1, n, b[i] );
	}
	while( m-- ) {
		scanf( "%d%d%d", &s, &t, &k );
		int pos = query( root[s - 1], root[t], 1, n, k );
		printf( "%d\n", a[p[pos]] );
	}
	return 0;
}
