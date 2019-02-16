# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
using namespace std;
int dpl[100005],dpr[100005];
int ans1[100005],ans2[100005];
int l[100005],r[100005];
int a[100005];
int kl=0,kr=0;
int main()
{
int n;
scanf("%d",&n);
int i,j;
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    l[i]=1000000;
    r[i]=1000000;
}
int x;
int uk1,uk2,mid;
for(i=1;i<=n;i++)
{
    x=a[i];
    uk1=0;
    uk2=kl;
    while(uk1<uk2)
    {
        mid=(uk1+uk2)/2+1;
        if(l[mid]>=x){uk2=mid-1;}
        else
            uk1=mid;
    }
    if(uk1==kl)
    {
        kl++;
        l[kl]=x;
    }
    else
        l[uk1+1]=x;
    dpl[i]=kl;
    ans1[i]=l[kl];
}
for(i=n;i>0;i--)
{
    x=a[i];
    uk1=0;
    uk2=kr;
    while(uk1<uk2)
    {
        mid=(uk1+uk2)/2+1;
        if(r[mid]>=x){uk2=mid-1;}
        else
            uk1=mid;
    }
    if(uk1==kr)
    {
        kr++;
        r[kr]=x;
    }
    else
        r[uk1+1]=x;
    dpr[i]=kr;
   // cout<<i<<" "<<kr<<endl;
    ans2[i]=r[kr];
}
int ans=max(dpl[n],dpr[1]);
for(i=1;i<n;i++)
{
   // cout<<i<<" "<<ans<<" "<<dpl[i]<<" "<<dpr[i+1]<< endl;
    if(ans1[i]!=ans2[i+1])
    ans=max(ans,dpl[i]+dpr[i+1]);

}
printf("%d\n",ans);
}
