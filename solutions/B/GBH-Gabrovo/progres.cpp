#include<iostream>
using namespace std;
long long a[1005],n,MOD=123456789012345;
long long dp[1005][1005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<i;j++)
        {
            int d=a[i]-a[j];
            if(d>0) dp[i][d]=((dp[i][d]+dp[j][d])+1)%MOD;
        }
    }
    long long sum=0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            sum+=dp[i][j];
        }
    }
    cout<<sum<<endl;
    return 0;
}
