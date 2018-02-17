#include<bits/stdc++.h>
const long long MOD=123456789012345ll;
const int MAXN=1005;

using namespace std;
int n;
int arr[MAXN];

long long dp[MAXN][MAXN];

void mainp()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    for(int i=0; i<n; i++)
        for(int j=1; j<MAXN; j++) dp[i][j]=1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j]) dp[i][arr[i]-arr[j]]=(dp[i][arr[i]-arr[j]]+dp[j][arr[i]-arr[j]])%MOD;
        }
    }

    long long sum=0ll;
    for(int i=0; i<n; i++)
        for(int j=1; j<MAXN; j++)
        {
            if(dp[i][j]>1) {sum=sum+dp[i][j]-1ll; sum%=MOD;}
        }
    printf("%lld\n",sum);
}

int main()
{
    mainp();
    return 0;
}
/*
6
1 9 1 9 2 3
*/
