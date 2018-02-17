#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int dp[105][105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int i, j, sz;
    cin>>s;
    sz=s.size();
    for(i=0;i<sz;i++)
    {
        dp[i][i]=1;
    }
    for(i=1;i<sz;i++)
    {
        for(j=0;j<sz-i;j++)
        {
            dp[j][j+i]=dp[j][j+i-1]+dp[j+1][j+i]-dp[j+1][j+i-1];
            if(s[j]==s[j+i])
            {
                dp[j][j+i]+=1+dp[j+1][j+i-1];
            }
        }
    }
    cout<<dp[0][sz-1]<<"\n";
    return 0;
}