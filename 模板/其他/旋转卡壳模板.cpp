//计算凸包直径，输入凸包ch，顶点个数为n，按逆时针排列，输出直径的平方
int rotating_calipers(Point *ch,int n)
{
    int q=1,ans=0;
    ch[n]=ch[0];
    for(int p=0;p<n;p++)
    {
        while(cross(ch[p+1],ch[q+1],ch[p])>cross(ch[p+1],ch[q],ch[p]))
            q=(q+1)%n;
        ans=max(ans,max(dist2(ch[p],ch[q]),dist2(ch[p+1],ch[q+1])));
    }
    return ans;
}
