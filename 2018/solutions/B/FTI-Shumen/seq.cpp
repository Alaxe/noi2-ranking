#include<cstdio>
using namespace std;
long long dp[280][280];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=270; i++){
        dp[i][1]=1;
        dp[1][i]=1;
    }
    for(int i=2; i<=n+2; i++)
        for(int j=2; j<=m+2; j++)
            for(int k=1; k<=j; k++)
                if(i>k) dp[i][j]+=dp[i-k][k];
    printf("%lld\n",dp[n+1][m]);
    return 0;
}
