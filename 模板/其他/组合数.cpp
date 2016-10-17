#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int M = 1007;
const int MAXN = 1000;
long long C[MAXN+1][MAXN+1];
void Initial() {
    int i,j;
    for(i=0; i<=MAXN; ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for(i=1; i<=MAXN; ++i) {
        for(j=1; j<=MAXN; ++j)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]);
    }
}
long long Combination(int n, int m) { return C[n][m]; }
int main() {
    int T,i,m,n;
    Initial();
    while( ~scanf("%d%d",&n,&m) ){
        printf("C(%d£¬%d)=%I64d\n",n,m,Combination(n,m));
    }
    return 0;
}
