#include<bits/stdc++.h>
using namespace std;
int w,k,n,m,a[100000],b[100000],cnt1[100000],cnt2[100000],maxn=0,ans=0;
bool flag1=true,flag2=true;
void read()
{
    cin>>w>>k>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=0; i<m; i++) cin>>b[i];
}
void solve2()
{
    for(int i=0; i<max(n,m); i++)
    {
        if(a[i]>maxn) maxn=a[i];
        if(b[i]>maxn) maxn=b[i];
        for(int j=i; j<i+2; j++)
        {
            if(a[j]!=a[j+1]) flag1=false;
            if(b[j]!=b[j+1]) flag2=false;
        }
        if(flag1)
        {
            cnt1[a[i]]++;
        }
        if(flag2)
        {
            cnt2[b[i]]++;
        }
        flag1=true;
        flag2=true;
    }
    for(int i=1; i<=maxn; i++)
    {
        if(cnt1[i]!=0 && cnt2[i]!=0)
        {
            ans+=cnt1[i]+cnt2[i];
        }
    }
    cout<<ans<<endl;
}
int main()
{
    read();
    if(w==2) solve2();
    else cout<<max(n,m)/2<<endl;
	return 0;
}
