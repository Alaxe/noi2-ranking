#include<iostream>

using namespace std;

const int MAXN = 1005;

int n;
pair <int, int> a[MAXN];

int maxValue[MAXN];
int dp[MAXN][MAXN];

int calcFace(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return ( x1*y2 + y1*x3 + x2*y3 ) - ( y1*x2 + x1*y3 + y2*x3 );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = 0;

    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> a[i].first >> a[i].second;

    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(maxValue[j]+1<answer) continue;

            dp[i][j] = 2;
            for(int k = 0;k<j;k++)
            {
                if(calcFace(a[i].first, a[i].second, a[j].first, a[j].second, a[k].first, a[k].second)==0)
                    dp[i][j] = max(dp[i][j], dp[j][k] + 1);
            }

            maxValue[i] = max(maxValue[i], dp[i][j]);
        }
    }

    for(int i = 0;i<n;i++)
        for(int j = i+1;j<n;j++)
            answer = max(answer, dp[j][i]);

    cout << answer << '\n';
}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
