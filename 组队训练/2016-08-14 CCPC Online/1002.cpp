#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxp = 310;
const int maxn = 2010;
bool vis[maxn + 10];
int prime[maxp], pcnt = 0;

void Init()
{
    int m = sqrt(maxn + 0.5);
    for(int i = 2; i <= m; i++) if(!vis[i])
        for(int j = i*i; j <= maxn; j += i) vis[j] = true;
    for(int i = 2; i <= maxn; i++) if(!vis[i]) prime[pcnt++] = i;
}

typedef long long Matrix[maxn][6];

Matrix A;

int rnk(Matrix A, int m, int n)
{//求系数矩阵A的秩，m个方程，n个未知数
    int i = 0, j = 0, len = n / 64;
    while(i < m && j < n)
    {
        int r = i, k;
        for(k = r; k < m; k++) if(A[k][j/64] & (1LL<<(j%64))) { r = k; break; }
        if(k < m)
        {
            if(r != i) for(int k = 0; k <= len; k++) swap(A[r][k], A[i][k]);
            for(int k = i+1; k < m; k++) if(A[k][j/64] & (1LL<<(j%64)))
                for(int l = 0; l <= len; l++) A[k][l] ^= A[i][l];
            i++;
        }
        j++;
    }
    return i;
}
long long multi(long long a,long long b,long long m)
{
    long long ans=0;
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

long long quick_mod(long long a,long long b,long long m)
{
    long long ans=1;
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
int main()
{
    //freopen("in.txt", "r", stdin);

    Init();
    int T,cases=1;
    scanf("%d", &T);
    while(T--)
    {
        memset(A, 0, sizeof(A));
        int n, M = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            long long x;
            scanf("%I64d", &x);
            for(int j = 0; j < pcnt; j++) while(x % prime[j] == 0)
            {
                M = max(M, j);
                x /= prime[j];
                A[j][i/64] ^= (1LL << (i%64) );
            }
        }
        int r = rnk(A, M+1, n);
        printf("Case #%d:\n",cases++);
        printf("%I64d\n", (quick_mod(2,n-r,1000000007) - 1+1000000007)%1000000007);
    }

    return 0;
}
