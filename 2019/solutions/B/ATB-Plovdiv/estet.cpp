#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
ll maxel=-1,n,a[101000],i,st[401000],ans[101000],st1[401000],ans1[101000],otg=-1;
void build(ll l,ll r,ll pos,ll q)
{
    if(l==r)
        st[pos]=ans[i];
    else
    {
        ll m=(l+r)/2;
        if(m>=q)
            build(l,m,pos*2+1,q);
        else
            build(m+1,r,pos*2+2,q);
        st[pos]=max(st[pos*2+1],st[pos*2+2]);
    }
}
ll query(ll l,ll r,ll pos,ll l1,ll r1)
{
    if(r1<l||l1>r||l1>r1||l>r)
        return 0;
    if(l==r)
        return st[pos];
    else
    {
        ll m=(l+r)/2;
        ll br1=query(l,m,pos*2+1,l1,r1);
        ll br2=query(m+1,r,pos*2+2,l1,r1);
        return max(br1,br2);
    }
}
void build1(ll l,ll r,ll pos,ll q)
{
    if(l==r)
        st1[pos]=ans1[i];
    else
    {
        ll m=(l+r)/2;
        if(m>=q)
            build1(l,m,pos*2+1,q);
        else
            build1(m+1,r,pos*2+2,q);
        st1[pos]=max(st1[pos*2+1],st1[pos*2+2]);
    }
}
ll query1(ll l,ll r,ll pos,ll l1,ll r1)
{
    if(r1<l||l1>r||l1>r1||l>r)
        return 0;
    if(l==r)
        return st1[pos];
    else
    {
        ll m=(l+r)/2;
        ll br1=query1(l,m,pos*2+1,l1,r1);
        ll br2=query1(m+1,r,pos*2+2,l1,r1);
        return max(br1,br2);
    }
}
int main()
{
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        maxel=max(maxel,a[i]);
    }
    for(i=0; i<n; i++)
    {
        ans[i]=query(1,maxel,0,1,a[i]-1)+1;
        build(1,maxel,0,a[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        ans1[i]=query1(1,maxel,0,1,a[i]-1)+1;
        build1(1,maxel,0,a[i]);
    }
    for(i=0; i<n; i++)
    {
        otg=max(otg,ans[i]);
        otg=max(otg,ans1[i]);
        otg=max(otg,ans[i]+ans1[i]-1);
//cout<<ans[i]<<" "<<ans1[i]<<endl;
    }
    cout<<otg<<endl;
    return 0;
}
