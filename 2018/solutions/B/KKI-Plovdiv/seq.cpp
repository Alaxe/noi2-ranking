#include<iostream>
using namespace std;
long long  dp[300][300];
long long  sums[300];
int main()
{
    int n,m;
    int result=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        dp[0][i]=1;
        sums[i]=1;
    }
    for(int i=1;i<m;i++)
    {
        dp[i][i]=1;
        sums[i]++;
        for(int j=i+1;j<n;j++)
        {
            /*int sum=0;
            for(int c=0;c<=j;c++)
            {
                sum+=dp[c][j-i-1];
            }
            dp[i][j]=sum;
            sums[j]+=sum;*/

            //cout<<sums[i]<<" ";
            dp[i][j]=sums[j-i-1];
            sums[j]+=dp[i][j];
            //cout<<dp[i][j]<<" ";

        }
        //cout<<endl;
       // cout<<endl;
    }
    for(int i=0;i<m;i++)
    {
        result+=dp[i][n-1];
    }
    cout<<result<<endl;
    return 0;
}
