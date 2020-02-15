#include<bits/stdc++.h>
using namespace std;
int n,k;
bool li[51][51];
long long dp[51][51];
long long ff(int i,int j){
if(i==1 and j==n)return 1;
if(li[i][j])return dp[i][j];
li[i][j]=true;
if(i>1)dp[i][j]+=ff(i-1,j);
if(j<n)dp[i][j]+=ff(i,j+1);
return dp[i][j];
}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>k;
cout<<ff(k,k)<<"\n";
return 0;
}
