#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,MX=1e4+42;
int n,inp[nmax];
int dp[MX];
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<inp[i];j++)
            dp[j]=dp[j]+inp[i]-j;
        for(int j=inp[i];j<MX;j++)
            dp[j]=dp[j]+j-inp[i];
        for(int j=1;j<MX;j++)
            if(dp[j-1]<dp[j])dp[j]=dp[j-1];
    }
    printf("%i\n",dp[MX-1]);
    return 0;
}
/*
5
2 6 4 3 2

5
2 6 6 7 7

4
10 6 8 1

4
1 10 6 8

4
1 10 8 6

4
10 8 6 1
*/
