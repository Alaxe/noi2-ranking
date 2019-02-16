#include <iostream>
using namespace std;
int n,k,l,a[5002],sum[5002],minsum,maxl;
void read_solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>l;
        if(l>maxl)maxl=l;
        for(int j=1;j<=l;j++)
        {
            cin>>a[j];
            sum[j]=sum[j]+a[j]*k;
            if(a[j]==a[l])sum[j]=sum[j]+a[l]*k;
            if(l==maxl)minsum=sum[j];
        }
    }
    cout<<minsum<<endl;
}
int main()
{
read_solve();
return 0;
}
