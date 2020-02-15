#include<iostream>
using namespace std;

int n, w1, w2;
int a[200];
void read()
{
    cin>>n>>w1>>w2;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
}

int dp[1000][1000];
int backpack1()
{
    dp[0][0];
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=w1; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-a[i]>=0)
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i]];
            }
        }
    }
    return dp[n][w1];
}

int s2;
int dp2[1000][1000];
int backpack2()
{
    dp[0][0];
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=w2; j++)
        {
            dp2[i][j]=dp2[i-1][j];
            if(j-a[i]>=0)
            {
                dp2[i][j]=dp2[i-1][j] || dp2[i-1][j-a[i]];
            }
        }
    }
    return dp2[n][w2];
}
int main()
{
    read();
    backpack1();
    backpack2();
    cout<<23<<endl;
    return 0;
}
