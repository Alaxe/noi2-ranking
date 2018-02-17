#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool>s2b;
vector<bool>t2b;
int calc(int a, int b)
{
    double ans=1.0, zn=1.0;
    double i, j;
    for(i=a, j=b;i>=a-b+1 && j>=1;i--, j--)
    {
        ans*=i;
        ans/=j;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i, brs=0, brt=0, br0=0;
    unsigned long long s, t, z, ans=0;
    cin>>s>>t>>z;
    for(int s1=s;s1!=0;s1/=2, brs++)
    {
        if(!(s1%2))
        {
            s2b.push_back(0);
            br0++;
        }
        else
        {
            s2b.push_back(1);
        }
    }
    brs--;
    if(br0==z) ans++;
    ///sz=brs;
    br0=0;
    for(i=brs;i>=0 && br0<=z;i--)
    {
        if(!s2b[i])
        {
            ans+=calc(i, z-br0);
            ///cout<<"i="<<i<<" z-br0="<<z-br0<<" calc="<<calc(i, z-br0)<<"\n";
            br0++;
        }
    }
    br0=0;
    for(int t1=t;t1!=0;t1/=2, brt++)
    {
        if(!(t1%2))
        {
            t2b.push_back(0);
            br0++;
        }
        else
        {
            t2b.push_back(1);
        }
    }
    brt--;
    if(br0==z) ans++;
    ///sz=brt;
    br0=0;
    for(i=brt-1;i>=0 && br0<z;i--)
    {
        if(t2b[i])
        {
            ans+=calc(i, z-br0-1);
            ///cout<<"i="<<i<<" z-br0-1="<<z-br0-1<<" calc="<<calc(i, z-br0-1)<<"\n";
        }
        else
        {
            br0++;
        }
    }
    for(i=brs+1;i<=brt-1;i++)
    {
        if(i>=z) ans+=calc(i, z);
    }
    cout<<ans<<"\n";
    return 0;
}