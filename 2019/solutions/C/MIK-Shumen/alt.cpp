#include <bits/stdc++.h>

using namespace std;

const int MAXN=50;
long long int dp[MAXN][MAXN];

int main()
{
    int k, m, n, i, j;
    cin>>k>>m>>n;
    long long int cnt=0;
    for(i=1; i<m; ++i) dp[i][1]=1;
    for(j=2; j<=n; ++j)
    {
        for(i=1; i<m; ++i)
        {
            if(i-k>0) dp[i][j]+=dp[i-k][j-1];
            if(i+k<m) dp[i][j]+=dp[i+k][j-1];
        }
    }
    for(i=1; i<m; ++i) cnt+=dp[i][n];
    cout<<cnt<<endl;
    return 0;
}
