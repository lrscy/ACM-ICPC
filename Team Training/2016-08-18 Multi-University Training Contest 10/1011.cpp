#include <bits/stdc++.h>
using namespace std;

int a[1010], b[1010];
int n;

void init() {
    a[1] = 3;a[2] = 3;a[3] = 5;a[4] = 4;a[5] = 4;a[6] = 3;a[7] = 5;a[8] = 5;a[9] = 4;a[10] = 3;
    a[11] = 6;a[12] = 6;a[13] = 8;a[14] = 8;a[15] = 7;a[16] = 7;a[17] = 9;a[18] = 8;a[19] = 8;a[20] = 6;
    a[21] = 9;a[22] = 9;a[23] = 11;a[24] = 10;a[25] = 10;a[26] = 9;a[27] = 11;a[28] = 11;a[29] = 10;a[30] = 6;
    a[31] = 9;a[32] = 9;a[33] = 11;a[34] = 10;a[35] = 10;a[36] = 9;a[37] = 11;a[38] = 11;a[39] = 10;a[40] = 5;
    a[41] = 8;a[42] = 8;a[43] = 10;a[44] = 9;a[45] = 9;a[46] = 8;a[47] = 10;a[48] = 10;a[49] = 9;a[50] = 5;
    a[51] = 8;a[52] = 8;a[53] = 10;a[54] = 9;a[55] = 9;a[56] = 8;a[57] = 10;a[58] = 10;a[59] = 9;a[60] = 5;
    a[61] = 8;a[62] = 8;a[63] = 10;a[64] = 9;a[65] = 9;a[66] = 8;a[67] = 10;a[68] = 10;a[69] = 9;a[70] = 7;
    a[71] = 10;a[72] = 10;a[73] = 12;a[74] = 11;a[75] = 11;a[76] = 10;a[77] = 12;a[78] = 12;a[79] = 11;a[80] = 6;
    a[81] = 9;a[82] = 9;a[83] = 11;a[84] = 10;a[85] = 10;a[86] = 9;a[87] = 11;a[88] = 11;a[89] = 10;a[90] = 6;
    a[91] = 9;a[92] = 9;a[93] = 11;a[94] = 10;a[95] = 10;a[96] = 9;a[97] = 11;a[98] = 11;a[99] = 10;
    for( int i = 100; i < 1000; ++i ) {
        int ta, tb;
        ta = i / 100; tb = i % 100;
        if( tb == 0 ) a[i] = a[ta] + 7;
        else a[i] = a[ta] + 10 + a[tb];
    }
    a[1000] = 11;
    return ;
}

int main() {
    int t;
    init();
    b[0] = 0;
    for( int i = 1; i <= 1000; ++i ) b[i] = b[i - 1] + a[i];
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d", &n );
        printf( "%d\n", b[n] );
    }
    return 0; 
}