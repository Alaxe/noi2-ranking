#include <iostream>
#include <string>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
ll n,nk;
int N[100],mxdif,inf=1000000,mxdig;
string maxn;

void calc(ll p,int k)
{
    ll nk=1;
    for(int i=1; i<=k; i++)
    {
       // cout<<nk<<" "<<p<< endl;
        if(p/n<nk) return;
        nk*=n;
    }
    ::nk=nk;
}


ll div(ll p,int k)
{
    ll nk=1;
    for(int i=1; i<=k; i++)
    {
       // cout<<nk<<" "<<p<< endl;
        if(p/n<nk) return 0;
        nk*=n;
    }
    return p/nk;
}

ll ost(ll p,int k)
{
    ll nk=1;
    for(int i=1; i<=k; i++)
    {
        if(p/n<nk) return p;
        nk*=n;
        //cout<<nk<<" "<<p<<endl;
    }
    return p%nk;
}
/*
ll fmns(int k,ll a,ll b);

ll vikfmns(ll k,ll p,ll l,ll r)
{
    if(p%2==0)
        return fmns(k-1,l,r);
    else
        return fmns(k-1,nk-1-r,nk-1-l);
}


ll fmns(int k,ll a,ll b)
{
    ll p1,p2,o1,o2,l,r,p,add;
    if(k==1)
    {
        int mn=10;
        for(int i=a; i<=b; i++) mn=min(mn,N[i]);
        return mn;
    }
    p1 = div(a,k-1); p2 = div(b,k-1);
    o1 = ost(a,k-1); o2 = ost(b,k-1);
   // cout<<p1<<" "<<p2<<" "<<o1<<" "<<o2<< endl;
    if(p1==p2)
    {
        add=N[p1];
        return add + vikfmns(k,p1,o1,o2);
    }
    else
    {
        int mn=10,mni,ans1=inf,ans2=inf,tans=inf,l1,r1,ans;
        l1 = (o1==0?p1:p1+1);
        r1 = (o2==nk?p2:p2-1);
        for(int i=l1; i<=r1; i++)
            if(N[i]<mn) mn=N[i];
        if(r1-l1>0)
            if(mn <= N[p1] && mn<=N[p2]) return mndig*(k-1)+mn;
            else tans=mndig*(k-1)+mn;
        if(l1!=p1)
            ans1 = N[p1] + vikfmns(k,p1,o1,nk-1);
        if(r1!=p2)
            ans2 = N[p2] + vikfmns(k,p2,0,o2);
        ans=min(ans1,ans2);
        return min(ans,tans);

    }
}
*/

ll fmxs(int k,ll a,ll b);

inline ll vikfmxs(ll k,ll p,ll l,ll r)
{
    if(p%2==0)
        return fmxs(k-1,l,r);
    else
        return fmxs(k-1,nk-1-r,nk-1-l);
}


ll fmxs(int k,ll a,ll b)
{
    ll p1,p2,o1,o2,l,r,p,add;
    if(k==1)
    {
        int mx=0;
        for(int i=a; i<b; i++) mx=max(mx,int(abs(N[i]-N[i+1])));
        return mx;
    }
    calc(b,k-1);
    p1 = div(a,k-1); p2 = div(b,k-1);
    o1 = ost(a,k-1); o2 = ost(b,k-1);
   // cout<<p1<<" "<<p2<<" "<<o1<<" "<<o2<< endl;
    if(p1==p2)
    {
        return vikfmxs(k,p1,o1,o2);
    }
    else
    {
       // cout<<"Im here"<< endl;
        int mx=0,ans1=0,ans2=0,tans=0,l1,r1,ans;
        l1 = (o1==0?p1:p1+1);
        r1 = (o2==nk-1?p2:p2-1);
        if(r1-l1>=0)
            return mxdif;
        ans1 = vikfmxs(k,p1,o1,nk-1);
        ans2 = vikfmxs(k,p2,0,o2);
        ans=max(ans1,ans2);
        return max(ans,int(abs(N[p1]-N[p2])));
    }
}

void fmaxn(int k,ll a,ll b)
{
    ll p1,p2,o1,o2,l,r,p;
    if(k==1)
    {
        int mx=0;
        for(int i=a; i<=b; i++) mx=max(mx,N[i]);
        maxn+=(mx+'0');
        return;
    }
    calc(b,k-1);
    p1 = div(a,k-1); p2 = div(b,k-1);
    o1 = ost(a,k-1); o2 = ost(b,k-1);
    //if(k<2000)cout<<k<<" "<<p1<<" "<<p2<<" "<<o1<<" "<<o2<< endl;
    if(p1==p2)
    {
        maxn+=(N[p1]+'0');
        l=o1; r=o2; p=p1;
    }
    else
    {
        int mx=0,mxi;
        for(int i=p1; i<=p2; i++)
            if(N[i]>mx) mxi=i, mx=N[i];
        maxn+=(mx+'0');
        p=mxi;
        if(mxi==p1)
            l=o1, r=nk-1;
        else if(mxi==p2)
            l=0, r=o1;
        else
        {
            for(int i=1; i<k; i++) maxn+=(mxdig + '0');
            return;
        }
    }
     if(p%2==0)
        fmaxn(k-1,l,r);
    else
        fmaxn(k-1,nk-1-r,nk-1-l);
}

int main()
{
    ll a,b,k,i;
    cin>>n>>k>>a>>b;
    a--; b--; if(a>b) swap(a,b);
    for(i=0; i<n; i++)
    {
        cin>>N[i];
        mxdig=max(mxdig,N[i]);
        if(i!=0) mxdif=max(mxdif,int(abs(N[i]-N[i-1])));
    }
    fmaxn(k,a,b);
    cout<<maxn<<" "<<fmxs(k,a,b)<< endl;
    return 0;
}
/*
3 2 3 5
7 1 5

3 3 10 16
7 1 5

10 100 123467789 123456789456456
5 5 5 5 5 5 5 5 5 5
*/
