#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2000;

vector<LL> vec;
map<LL, int> mp;
map<LL, int>::iterator it;
int a[MAXN];
int n;

int main() {
    freopen( "out.txt", "w+", stdout );
    vec.clear();
    mp.clear();
    for( int i = 1; i <= MAXN; ++i ) {
        for( int j = 1; j <= 10000; ++j ) if( mp.count( j ) == 0 ) {
            bool flag = true;
            for( int k = 0; k < vec.size(); ++k ) {
                if( j == vec[k] ) { flag = false; break; }
            }
            int len = vec.size();
            for( int k = len - i + 1; k < len; ++k ) {
                if( mp.count( j + vec[k] ) ) { flag = false; break; }
            }
            if( flag ) {
//            cout << "num: " << j << endl;
//            for( int k = 1; k < i; ++k ) cout << a[k] << " "; cout << endl;
//            for( int k = 0; k < vec.size(); ++k ) cout << vec[k] << " "; cout << endl;
//            for( it = mp.begin(); it != mp.end(); ++it ) if( it->second ) cout << it->first << " "; cout << endl;
//            puts( "--" );
                for( int k = len - i + 1; k < len; ++k ) {
                    vec.push_back( j + vec[k] );
                    mp[j + vec[k]] = 1;
                }
                mp[j] = 1;
                vec.push_back( j );
//            for( int k = 1; k < i; ++k ) cout << a[k] << " "; cout << endl;
//            for( int k = 0; k < vec.size(); ++k ) cout << vec[k] << " "; cout << endl;
//            for( it = mp.begin(); it != mp.end(); ++it ) cout << it->first << " "; cout << endl;
                a[i] = j;
                break;
            }
        }
    }
//    cout << vec.size() << " " << mp.size() << endl;
    for( int i = 1; i <= MAXN; ++i ) cout << a[i] << ","; cout << endl;
    return 0;
}
