#include<iostream>

using namespace std;

int n;
int a[1005];

int dp[2000005];
int maxReached = 0, newMaxReached , offSet = 1000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = 0;

    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> a[i];

    maxReached = a[0] + offSet;
    dp[ a[0] + offSet ] = 1;
    for(int i = 1;i<n;i++)
    {
        if(dp[ a[i] + offSet ]==0) dp[ a[i] + offSet ] = i + 1;

        newMaxReached = maxReached;
        for(int j = maxReached;j>=0;j--)
        {
            if(dp[j]!=0 && i+1>dp[j])
            {
                dp[ j + a[i] ] = i + 1;
                if(j+a[i]>newMaxReached) newMaxReached = j + a[i];
            }
        }
        maxReached = newMaxReached;
    }

    for(int i = 0;i<=maxReached;i++)
        if(dp[i]!=0) answer++;

    cout << answer << '\n';
}
