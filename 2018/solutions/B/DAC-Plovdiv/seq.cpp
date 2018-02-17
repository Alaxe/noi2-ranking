#include <iostream>
using namespace std;
#define MAXN 512

int n, m, i, j;
long long dp[MAXN][MAXN]={};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(i=0;i<=m;i++) dp[0][i]=1;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(i-j<0){
                dp[i][j]=dp[i][j-1];
            }
            else{
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
            }
        }

    cout<<dp[n][m]<<endl;
    return 0;
}
