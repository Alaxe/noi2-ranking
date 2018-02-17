#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
long long dp[128][128];
int mod=1e9+7;
int n;
string s;
int main()
{
	cin>>s;
	n=s.size();
	int i;
	int j;
	int k;
	for(i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    long long m;
    for(i=1;i<n;i++)
    {
        for(j=0;j+i<n;j++)
        {
            if(s[j]==s[j+i])
            {
                dp[j][i+j]=(dp[j+1][i+j-1]+1)%mod;
            }
            dp[j][i+j]=(dp[j][i+j]+dp[j][i+j-1]+dp[j+1][i+j]-dp[j+1][i+j-1])%mod;
        }
    }
    cout<<dp[0][n-1]<<endl;
	return 0;
}
