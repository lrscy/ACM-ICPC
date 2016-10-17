#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000010

int prime[N];
bool vis[N];
int num;

void _prime() {
    int i, j;
    memset( vis, true, sizeof( vis ) );
    vis[0] = vis[1] = 0;
    for( i = 2, num = 0; i < N; ++i ) {
        if( vis[i] )
            prime[num++] = i;
        for( j = 0; j < num && i * prime[j] < N; ++j ) {
            vis[i * prime[j]] = 0;
            if( !( i % prime[j] ) )
               break;
        }
    }
    return ;
}

int main() {
    _prime();
    return 0;
}
