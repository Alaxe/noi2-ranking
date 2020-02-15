#include<bits/stdc++.h>
using namespace std;
long long n,k,dp[60][60];
long long f(int i,int j){
    if(dp[i][j]>0){
        return dp[i][j];
    }
    if(i==0 or j==n-1){
        return 1;
    }
    dp[i][j]=f(i-1,j)+f(i,j+1);
    return dp[i][j];
}
int main ()
{
    cin>>n>>k;
    cout<<f(k-1,k-1)<<"\n";
    return 0;
}

