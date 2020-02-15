#include<bits/stdc++.h>
using namespace std;

long long dp[51][51];

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long n,k,x,sum=0;
cin>>n>>k;
x=k-1;
dp[x][1]=1;

for(int i=k;i<n;i++){
    for(int j=i-x+1;j<=i+1;j++){
        for(int z=j-1;z>=i-x;z--){
            dp[i][j]+=dp[i-1][z];
        }
    }
}

for(int i=n-x;i<=n;i++){
    sum+=dp[n-1][i];
}
if(k-1==0)cout<<1<<endl;
else cout<<sum<<endl;

return 0;
}
