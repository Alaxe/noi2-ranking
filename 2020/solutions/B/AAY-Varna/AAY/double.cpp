#include<bits/stdc++.h>
using namespace std;
bool dp[200][200][200];
int maxi,tmp;
int n,w1,w2;
int a[201];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>w1>>w2;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    if(a[0] <= w1)
    {
        dp[0][a[0]][0] = true;
    }
    if(a[0] <= w2)
    {
        dp[0][0][a[0]] = true;
    }
    dp[0][0][0] = true;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=w1; j++)
        {
            for(int k=0; k<=w2; k++)
            {
                dp[i][j][k] = dp[i-1][j][k];
            }
        }
        for(int j=0; j<=w1-a[i]; j++)
        {
            for(int k=0; k<=w2; k++)
            {
                tmp =  dp[i-1][j][k];
                if(tmp==true)
                {
                    dp[i][j+a[i]][k] = true;
                }
            }
        }
        for(int j=0; j<=w1; j++)
        {
            for(int k=0; k<=w2-a[i]; k++)
            {
                tmp = dp[i-1][j][k];
                if(tmp==true)
                {
                    dp[i][j][k+a[i]] = true;
                }
            }
        }
    }
    for(int j=w1;j>=0;j--)
    {
        for(int k=w2;k>=0;k--)
        {
            if(dp[n-1][j][k]==true)
            {
                maxi = max(maxi,j+k);
                break;
            }
        }
    }
    cout<<maxi<<endl;
}
