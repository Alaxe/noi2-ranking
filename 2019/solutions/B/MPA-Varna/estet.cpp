#include<iostream>
using namespace std;
int dp[5][100001];
int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i < n; ++i)
    {
        cin>>dp[0][i]; ///n
    }
    dp[1][0] = 0; ///t {0 & 1 = 0; 2 & 3 = 1}
    dp[2][0] = 1; ///count
    dp[3][0] = 0; ///cutNum
    dp[4][0] = 0; ///MaxCount
    for(int i = 1 ; i < n ; ++i)
    {
        if(dp[1][i-1] == 0)
        {
            if(dp[0][i] > dp[0][i-1])
            {
                dp[1][i] = 0; ///t {0 & 1 = 0; 2 & 3 = 1}
                dp[2][i] = dp[2][i-1] + 1; ///count
                dp[3][i] = dp[3][i-1]; ///cutNum
            }
            else if(dp[0][i] < dp[0][i-1])
            {
                dp[1][i] = 1; ///t {0 & 1 = 0; 2 & 3 = 1}
                dp[2][i] = dp[2][i-1] + 1; ///count
                dp[3][i] = dp[3][i-1]; ///cutNum
            }
            else if(dp[0][i] == dp[0][i-1])
            {
                dp[1][i] = 0; ///t {0 & 1 = 0; 2 & 3 = 1}
                dp[2][i] = dp[2][i-1]; ///count
                dp[3][i] = dp[3][i-1] + 1; ///cutNum
            }
        }
        else
        {
            if(dp[0][i] < dp[0][i-1])
            {
                dp[1][i] = 1; ///t {0 & 1 = 0; 2 & 3 = 1}
                dp[2][i] = dp[2][i-1] + 1; ///count
                dp[3][i] = dp[3][i-1]; ///cutNum
            }
            else if(dp[0][i] == dp[0][i-1])
            {
                dp[1][i] = 1; ///t {0 = 0 & 1; 1 = 2 & 3}
                dp[2][i] = dp[2][i-1]; ///count
                dp[3][i] = dp[3][i-1] + 1; ///cutNum
            }
            else if(dp[0][i] > dp[0][i-1])
            {
                dp[1][i] = 0; ///t {0 = 0 & 1; 1 = 2 & 3}
                dp[2][i] = dp[2][i-1] + 1; ///count
                dp[3][i] = dp[3][i-1]; ///cutNum
                for(int j = i - 1; j >= 0 ; --j)
                {
                    if(dp[1][j] == 0)
                    {
                        break;
                    }
                    dp[2][i]--;
                    dp[3][i]++;
                }
            }
        }
        if(dp[2][i] > dp[4][i-1]) dp[4][i] = dp[2][i];
        else dp[4][i] = dp[4][i-1];
    }
    /*for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[4][n-1]<<endl;
    return 0;
}
