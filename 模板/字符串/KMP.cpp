#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j;
    int p[100010], len1, len2;
    char A[100010], B[100010];
    scanf( "%s%s", A, B );
    len1 = strlen( A );
    len2 = strlen( B );
    p[0] = -1;
    for( i = 1, j = -1; i < len2; ++i ) {
        while( ( j >= 0 ) && ( B[j + 1] != B[i] ) ) j = p[j];
        if( B[j + 1] == B[i] ) ++j;
        p[i] = j;
    }
    for( i = 0, j = -1; i < len1; ++i ) {
        while( ( j >= 0 ) && ( B[j + 1] != A[i] ) ) j = p[j];
        if( B[j + 1] == A[i] ) ++j;
        if( j == len2 - 1 ) {
            cout << i + 1 - len2 << endl;
//            j = p[j]; //multiple matching
            break;
        }
    }
    return 0;
}
