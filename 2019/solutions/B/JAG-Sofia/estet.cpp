#include <iostream>
using namespace std;
int main()
{
  int N, i, j, currmax , max1 = 0;
  int A[100000];
  int Dp[100000];
  int Dp2[100000];
  cin >> N;
  for ( i = 0 ; i < N ; i++) cin >> A[i];

  for ( i = 0 ; i < N ; i++) Dp[i] = 1;
  for ( i = 0 ; i < N ; i++)
  {
    currmax = 1;
    for ( j = i - 1 ; j >= 0 ; j--)
    {
      if (A[j] < A[i]) { if (Dp[i]+Dp[j] > currmax) currmax = Dp[i] + Dp[j]; }
    }
    Dp[i] = currmax;
    if ( currmax >  max1 ) max1 = currmax;
  }

  for ( i = 0 ; i < N ; i++) Dp2[i] = 1;
  for ( i = N-1 ; i >= 0 ; i--)
  {
    currmax = 1;
    for ( j = i + 1 ; j < N ; j++)
    {
      if (A[j] < A[i]) { if (Dp2[i]+Dp2[j] > currmax) currmax = Dp2[i] + Dp2[j]; }
    }
    Dp2[i] = currmax;
    if ( currmax >  max1 ) max1 = currmax;
  }
  for (i = 0 ; i < N ; i++) if (Dp[i]+Dp2[i]-1 > max1) max1 = Dp[i]+Dp2[i]-1;

  cout << max1;
  return 0;
}
