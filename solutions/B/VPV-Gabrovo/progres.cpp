#include<iostream>
using namespace std;
long long a[1005],d[1005][1005];
long long n,ans=0;
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        for(long long j=i-1;j>0;j--)
        {
            if(a[j]<a[i])
            {
                d[i][a[i]-a[j]]+=d[j][a[i]-a[j]]+1;
                ans=(ans+d[j][a[i]-a[j]]+1)%123456789012345;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
