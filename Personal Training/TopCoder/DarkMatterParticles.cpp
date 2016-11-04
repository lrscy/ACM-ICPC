// Paste me into the FileEdit configuration dialog

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

class DarkMatterParticles {
public:
    int fa[MAXN], ms[MAXN], dp[MAXN], w[MAXN];
    int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }
    void munion( int u, int v ) {
        int x = mfind( u ), y = mfind( v );
        if( x != y ) {
            fa[x] = y;
            ms[y] += ms[x];
        }
    }
    string SplitParticles( int n, int k, vector <int> x, vector <int> y ) {
        fill( ms, ms + MAXN, 1 );
        for( int i = 0; i < n; ++i ) fa[i] = i;
        for( int i = 0; i < x.size(); ++i ) {
            int a = x[i], b = y[i];
            munion( a, b );
        }
        int tn = 0;
        for( int i = 0; i < n; ++i ) {
            if( fa[i] == i ) w[tn++] = ms[i];
        }
        memset( dp, 0x80, sizeof( dp ) );
        dp[0] = 0;
        for( int i = 0; i < tn; ++i ) {
            for( int j = k; j >= w[i]; --j ) {
                dp[j] = max( dp[j], dp[j - w[i]] + w[i] );
            }
        }
        if( dp[k] == k ) return "Possible";
        return "Impossible";
    }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
