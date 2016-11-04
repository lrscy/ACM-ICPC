// Paste me into the FileEdit configuration dialog

#include <bits/stdc++.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
const int MAXN = 500 + 10;

class GroupSRMDiv2 {
public:
    int s[MAXN];
    int FindGroups( vector <int> t ) {
        int ret = 0;
        memset( s, 0, sizeof( s ) );
        for( int i = 0; i < t.size(); ++i ) {
            ++s[t[i]];
        }
        bool flag = true;
        for( int i = 1; i <= 500; ++i ) {
            if( s[i] % i ) { flag = false; break; }
            ret += s[i] / i;
        }
        if( !flag ) return -1;
        return ret;
    }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
