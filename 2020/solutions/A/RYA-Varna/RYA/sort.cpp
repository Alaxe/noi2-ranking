#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 2,MAXK = 1e4 + 2;
int n,a[MAXN];
long long dp[MAXK][1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,j;
    cin >> n;
    int minc = 10001,maxc = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        minc = min(minc,a[i]);
        maxc = max(maxc,a[i]);
    }
    int minp = 10001,maxi,prev;
    for(i = minc; i <= maxc; i++)
    {
        int t = i - a[0];
        if(t < 0)t = -t;
        dp[i][0] = t;
        if(minp >= dp[i][0])
        {
            minp = dp[i][0];
            maxi = i;
        }
        else break;
    }
    for(j = 1; j < n; j++)
    {
        long long mino = dp[minc][j - 1];
        prev = maxi;
        for(i = minc; i <= maxc; i++)
        {
            if(i <= prev)mino = min(mino,dp[i][j - 1]);
            int t = i - a[j];
            if(t < 0)t = -t;
            dp[i][j] = mino + t;
            if(i!=minc && dp[i][j] > dp[i-1][j])break;
            maxi = i;
        }
    }
    long long ans = 1e10;
    for(i = minc; i <= maxi; i++)
    {
        ans = min(ans,dp[i][n-1]);
    }
    cout << ans << endl;
}
/**
5
2 6 4 3 2
*/
