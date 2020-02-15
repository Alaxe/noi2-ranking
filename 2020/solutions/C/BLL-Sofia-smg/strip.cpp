#include<bits/stdc++.h>
using namespace std;
long long n,k,dp[100][100];
int main(){
cin>>n>>k;
for(int i=1;i<=n;i++){
    dp[i][1]=1;
    dp[i][n]=1;
}
for(int i=2;i<=n;i++){
    for(int j=2;j<=k;j++){
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    }
}
cout<<dp[n][k]<<endl;
return 0;
}
