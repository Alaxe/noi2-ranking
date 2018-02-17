#include<iostream>

using namespace std;

int grid[105][105];
int dp[105][105];
int n;
string input;

void dipi()
{

  for (int i = n-1; i >= 0; i--)
  {
      for (int j = 0; j <= n; j++)
      {
          if (i==n-1 && j == 0) {dp[i][j] = grid[i][j];continue;}
          if (j==0) dp[i][j] = grid[i][j]+dp[i+1][j];
          else dp[i][j]=max(grid[i][j]+dp[i+1][j],grid[i][j]+dp[i][j-1]);
      }
  }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {   cin>>input;
            if (input[0] >= '2' && input[0] <= '9') grid[i][j] = input[0] - '0';
            else if (input[0] == 'A') grid[i][j] = 1;
            else if (input[0] == 'T') grid[i][j] = 10;
            else if (input[0] == 'J') grid[i][j] = 11;
            else if (input[0] == 'Q') grid[i][j] = 12;
            else if (input[0] == 'K') grid[i][j] = 13;
        }
    }
    dipi();

    cout << dp[0][n-1]<<'\n';
    return 0;
}
/*
____________________
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
____________ _______
_Vhod_______|_Izhod_|
4           | 69    |
8S AD 3C AC |       |
8C 4H QD QS |       |
5D 9H KC 7H |       |
TC QC AS 2D |       |
____________|_______|
input:        output:
                 ^
4               / \
8S AD 3C AC    /   \
8C 4H QD QS   /  6  \
5D 9H KC 7H  /   9   \
TC QC AS 2D /_________\


    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            cout<<grid[i][j];
        }
        cout<<"\n";
    }

 ---------------------------------------
 */
