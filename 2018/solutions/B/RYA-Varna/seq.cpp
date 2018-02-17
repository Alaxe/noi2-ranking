#include <iostream>
using namespace std;
long long dp[300],n,m,a[300];
int main( )
{
    int i,j,k;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        a[i]=m-i+1;
    }
    for(i=1;i<=m;i++)
    {
        for(j=n-a[i];j>=1;j--)
        {
            for(k=1;j+k*a[i]<=n;k++)
            {
                dp[j+k*a[i]]+=dp[j];
            }
        }
        for(j=a[i];j<=n;j+=a[i])dp[j]++;
    }
    cout<<dp[n]<<endl;
    return 0;
}
