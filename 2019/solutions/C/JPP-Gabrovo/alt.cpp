#include<iostream>
using namespace std;

const int MAXN=55;

long long dp[MAXN][MAXN]; // i - value of last element, j - number of elements

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k,m,n;
    cin >> k >> m >> n;

    for(int i=1; i<m; i++)
        dp[i][1]=1;

    for(int j=2; j<=n; j++)
    {
        for(int i=1; i<m; i++)
        {
            if(i-k>0) dp[i][j]+=dp[i-k][j-1];
            if(i+k<m) dp[i][j]+=dp[i+k][j-1];
        }
    }

    long long ans=0;
    for(int i=1; i<m; i++)
        ans+=dp[i][n];

    cout << ans << endl;

    return 0;
}
