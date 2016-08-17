#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include <deque>
#include <list>
#include <ctime>
#include <stack>
#include <vector>
#include<iomanip>
#include<set>
#include <bitset>
#include <cassert>
using namespace std;
#define Maxn 100100
#define mod 1000000007
typedef long long LL;
typedef pair<int, int> PII;
#define FOR(i,j,n) for(int i=j;i<=n;i++)
#define DFR(i,j,k) for(int i=j;i>=k;--i)
#define lowbit(a) a&-a
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mem(a) memset(a,0,sizeof(a))
#define eps 1e-9
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define max3(a,b,c) (max(a,b)>c?max(a,b):c)
#define min3(a,b,c) (min(a,b)<c?min(a,b):c)
const int inf = 0x7f7f7f7f;
const double pi = acos(-1.0);

char P[100100],str[100100];
int T,next_[100100],is[Maxn], str_len, P_len, f[Maxn];

void getnext_(char T[], int LT, int next_[])
{
    int i, j;
    next_[0]=-1;
    next_[1] = 0;
    for (i = 1, j = 0; i < LT; )
    {
        while (j != -1 && T[i] != T[j]) j = next_[j];
        i++;
        j++;
        next_[i] = j;
    }
}
void KMP (char S[], int LS, char T[], int LT, int next_[])
{
    int i, j;
    for(i = 0; i < LS; i++) is[i] = 0;
    for (i = 0, j = 0; i < LS; i++)
    {
        while (j != -1 && S[i] != T[j]) j = next_[j];
        j++;
        if (j == LT)
        {
            is[i - LT + 1] = 1;
            j = next_[j];
        }
    }
}
LL multi(LL a,LL b,LL m)
{
    LL ans=0;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%m;
            b--;
        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}
LL quick_mod(LL a,LL b,LL m)
{
    LL ans=1;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}

void gao( int tt ) {
    int tn = P_len / tt, tm = str_len / tt;
    for( int i = 0; i < tn; ++i ) f[i] = 0;
    f[tn] = 1;
    for( int i = tn + 1; i <= tm; ++i ) {
        f[i] = ( 1LL + f[i - 1] + f[i - tn] ) % mod;
    }
    return ;
}

int a[Maxn];
int main()
{
    scanf("%d",&T);
    FOR(cases,1,T)
    {
        scanf("%s",str);
        scanf("%s",P);
        str_len=strlen(str),P_len=strlen(P);
        mem(a);
        mem(is);
        getnext_(P,P_len,next_);
        KMP(str,str_len,P,P_len,next_);
        printf("Case #%d: ",cases);
        int tol=0,j=1,sum2=0;
        LL sum1=1;
        int n=0,m=1;
        LL sum=1;
        f[0] = 0;
        FOR(i,0,P_len - 1) f[i] = is[i];
        FOR(i,m,str_len-1) {
            if( is[i] ) f[i] = ( f[i - 1] + 1 + f[i - P_len] ) % mod;
            else f[i] = f[i - 1];
        }
        printf("%d\n", ( f[str_len - 1] + 1 ) % mod);
    }
    return 0;
}
