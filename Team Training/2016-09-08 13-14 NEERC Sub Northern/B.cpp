//#include <bits/stdc++.h>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename "bad"
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 10 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, m, invalid = 0;
struct CAN {
    string name;
    int cnt;        
}can[MAX_N];
string ballots, s;

bool cmp(const CAN &a, const CAN &b) {
    return a.cnt > b.cnt;
}
int main(int argc, char const *argv[])
{
    setfile();
    char st[200];
    scanf( "%d%d", &n, &m );
//    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        char tst[110];
        scanf( "%s", tst );
        can[i].name = tst;
//        cin >> can[i].name;
        can[i].cnt = 0;
    }
    for (int i = 0; i < m; ++i) {
        char tst[11];
        scanf( "%s", tst );
//        cin >> ballots;
        bool flag = true;
        int p = -1;
        for (int j = 0; j < n; ++j) {
            if (tst[j] == 'X') {
                if (p != -1) {
                    flag = false;
                    break;
                } else {
                    p = j;
                }
            }
        }
        if (p == -1 || !flag) invalid++;
        else can[p].cnt++;
    }
    stable_sort(can, can + n, cmp);
    for (int i = 0; i < n; ++i) {
        printf( "%s %.2f%%\n", can[i].name.c_str(), 100. * can[i].cnt / m );
//        cout << can[i].name << " " << fixed << setprecision(2) << can[i].cnt * 100. / m << "%\n";
    }
    printf( "Invalid %.2f%%\n", 100. * invalid / m );
//    cout << "Invalid " << fixed << setprecision(2) << invalid * 100. / m << "%\n";
    return 0;
}
