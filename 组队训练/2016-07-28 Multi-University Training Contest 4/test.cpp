#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int maxn=100010;  
int a[maxn],b[maxn];  
int ans[maxn];  
int cnt,zero,len;  
  
int main()  
{  
    int T,n,cas=1;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d",&n);  
        for(int i=1; i<=n; i++){  
            scanf("%d",&a[i]);  
        }  
        memset(b,0,sizeof(b));  
        memset(ans,0,sizeof(ans));  
        cnt=0;  
        zero=0;  
        bool flag=0;  
        for(int i=1; i<=n; i++){  
            if(a[i]==0) zero++;  
            else{  
                flag=1;  
                b[cnt++]=a[i]-zero;  
            }  
        }  
        ans[0]=b[0];  
        len=1;  
        for(int i=1; i<cnt; i++){  
            if(b[i]>ans[len-1]){  
                ans[len++]=b[i];  
            }  
            else{  
                int pos=lower_bound(ans,ans+len,b[i])-ans;  
                ans[pos]=b[i];  
            }  
        }  
        if(flag==0) len=0;  
        //cout<<len<<endl;  
        printf("Case #%d: %d\n",cas++,zero+len);  
    }  
}
