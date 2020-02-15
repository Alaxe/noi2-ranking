#include<bits/stdc++.h>
using namespace std;
int n,sum1,sum2;
int a[256];
int dp[256][256][256];
int answer;
int main()
{
    cin>>n>>sum1>>sum2;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    dp[0][0][0]=1;
    for (int i=0;i<n;i++)
    {
        int ii=i+1;

        for (int j1=0;j1<256;j1++)
        for (int j2=0;j2<256;j2++)
        {
            dp[ii][j1][j2]=dp[i][j1][j2];
            if (j1>=a[i])
            dp[ii][j1][j2]=max(dp[ii][j1][j2],dp[i][j1-a[i]][j2]);
            if (j2>=a[i])
            dp[ii][j1][j2]=max(dp[ii][j1][j2],dp[i][j1][j2-a[i]]);
        }
    }

    for (int j1=0;j1<256;j1++)
    for (int j2=0;j2<256;j2++)
    {
        if (dp[n][j1][j2])
        {
            if (j1<=sum1&&j2<=sum2)
            answer=max(answer,j1+j2);
        }
    }
    cout<<answer<<endl;
    return 0;
}
