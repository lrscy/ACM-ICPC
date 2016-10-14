/* HDU 3473 已验
    求区间第K大
    cnt数组 区间内有多少 <= 中位数的数字
    num数组 30层划分树，存原始数组及排序后的数组
    sum数组 前缀和
    leftsum 区间小于中位数的数前缀和
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;

LL sum[MAXN], leftsum[30][MAXN];
int a[MAXN];
int num[30][MAXN], cnt[30][MAXN];
int n, q;
LL lsum, rsum, lcnt, rcnt;

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
            leftsum[dep][i] = leftsum[dep][i - 1] + num[dep][i];
        } else if( num[dep][i] > a[mid] ) {
            num[dep + 1][rp++] = num[dep][i];
            leftsum[dep][i] = leftsum[dep][i - 1];
        } else {
            if( ncnt ) {
                --ncnt; ++cnt[dep][i];
                num[dep + 1][lp++] = num[dep][i];
                leftsum[dep][i] = leftsum[dep][i - 1] + num[dep][i];
            } else {
                num[dep + 1][rp++] = num[dep][i];
                leftsum[dep][i] = leftsum[dep][i - 1];
            }
        }
    }
    build( left, mid, dep + 1 );
    build( mid + 1, right, dep + 1 );
    return ;
}

int query( int l, int r, int k, int left, int right, int dep ) {
    if( l == r ) return num[dep][l];
    int mid = ( left + right ) >> 1, s, ss, tmp;
    if( l == left ) { s = cnt[dep][r]; ss = 0; }
    else { s = cnt[dep][r] - cnt[dep][l - 1]; ss = cnt[dep][l - 1]; }
    if( s >= k ) {
        l = left + ss;
        r = left + ss + s - 1;
        tmp = query( l, r, k, left, mid, dep + 1 );
    } else {
        lcnt += s;
        lsum += leftsum[dep][r] - leftsum[dep][l - 1];
        l = mid + 1 + l - left - ss;
        r = mid + 1 + r - left - cnt[dep][r];
        tmp = query( l, r, k - s, mid + 1, right, dep + 1 );
    }
    return tmp;
}

int main() {
    int t, x, y, mid, tt = 0;
    LL k;
    scanf( "%d", &t );
    while( t-- ) {
        printf( "Case #%d:\n", ++tt );
        sum[0] = 0;
        scanf( "%d", &n );
        for( int i = 1; i <= n; ++i ) {
            scanf( "%d", a + i );
            num[0][i] = a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        sort( a + 1, a + 1 + n );
        build( 1, n, 0 );
        scanf( "%d", &q );
        while( q-- ) {
            scanf( "%d%d", &x, &y ); ++x; ++y;
            lsum = lcnt = 0;
            mid = query( x, y, ( y - x ) / 2 + 1, 1, n, 0 );
            rcnt = y - x + 1 - lcnt;
            rsum = sum[y] - sum[x - 1] - lsum;
            k = rsum - lsum + mid *  ( lcnt - rcnt );
            printf( "%I64d\n", k );
        }
        puts( "" );
    }
    return 0;
}
