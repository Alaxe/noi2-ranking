#include<iostream>
using namespace std;
long long dp[2][1001];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n;
    long long m,ans=0;
    cin>>n>>m;
    dp[1][0]=1;
    for(int i=0;i<s.size();i++){
        int ind=i%2;
        for(int j=0;j<n;j++){
                dp[ind][j]=dp[ind^1][j];
        }
        for(int j=0;j<n;j++){
            int newRem=(j*10+(s[i]-'0'))%n;
            dp[ind][newRem]+=dp[ind^1][j];
            dp[ind][newRem]%=m;
        }
    }
    int ind=(s.size()-1)%2;
    dp[ind][0]=(dp[ind][0]+m-1)%m;
    cout<<dp[ind][0]<<"\n";
    return 0;
}
