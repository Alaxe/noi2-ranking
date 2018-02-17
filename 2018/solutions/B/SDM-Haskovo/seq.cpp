#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 275, MAXLen = 1005;

int n, m;

int dpLen[MAXN][MAXN], prefixLen[MAXN][MAXN];
char dp[MAXN][MAXN][MAXLen], prefix[MAXN][MAXN][MAXLen];

char n0[MAXN];

int answerLen = 0;
char answer[MAXLen];

char help[MAXLen];
int add(char A[], char B[], char C[], int ALength, int BLength)
{
    memset(help, 0, sizeof(help));
    for(int i = 0;i<max(ALength, BLength);i++)
    {
        help[i] += A[i] + B[i];

        help[i+1] += help[i]/10;
        help[i] %= 10;
    }

    for(int i = 0;i<=max(ALength, BLength);i++)
        C[i] = help[i];

    if(help[max(ALength, BLength)]!=0) return max(ALength, BLength) + 1;
    return max(ALength, BLength);
}

int main()
{
    cin >> n >> m;

    for(int i = 1;i<=n;i++)
    {
        if(i<=m)
        {
            dpLen[i][i] = 1;
            dp[i][i][0] = 1;
        }

        for(int j = 1;j<=min(i, m);j++)
        {
            if(i==1)
            {
                for(int k = 1;k<=j;k++)
                {
                    dpLen[i][j] = add(dp[i][j] , dp[i-j][k], dp[i][j], dpLen[i][j], dpLen[i-j][k]);
                }
            }
            else
            {
                dpLen[i][j] = add(dp[i][j] , prefix[i-j][j], dp[i][j], dpLen[i][j], prefixLen[i-j][j]);
            }

            prefixLen[i][j] = add(prefix[i][j-1], dp[i][j], prefix[i][j], prefixLen[i][j-1], dpLen[i][j]);
        }

        for(int j = i+1;j<=m;j++)
            prefixLen[i][j] = add(prefix[i][j-1], n0, prefix[i][j], prefixLen[i][j-1], 1);
    }

    for(int i = 1;i<=m;i++)
        answerLen = add(answer, dp[n][i], answer, answerLen, dpLen[n][i]);

    for(int i = answerLen-1;i>=0;i--)
        cout << (int)answer[i];
    cout << '\n';
}
