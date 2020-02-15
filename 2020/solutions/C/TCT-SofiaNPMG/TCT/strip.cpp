#include<bits/stdc++.h>
#define nl '\n'
using namespace std;

const int MAXN=69;

long long dp[MAXN][MAXN];
int n, k;

int main(){
    for(int i=0;i<MAXN;i++){
        dp[i][0]=1;
        dp[0][i]=1;
    }
    for(int i=1;i<MAXN;i++){
        for(int j=1;j<MAXN;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
        }
    }
    cin>>n>>k;
    cout<<dp[n-k][k-1]<<'\n';
}
