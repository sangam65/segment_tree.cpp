int bit[N],a[N],n;
void update(int i,int pre,int cur)
{
    for(;i<=n;i+=(i&(-i)))
    {
        bit[i]-=pre;
        bit[i]+=cur;
    }

}
int sum(int i)
{
    int s=0;
    for(;i>0;i-=(i&(-i)))
        s+=bit[i];
    return s;

}