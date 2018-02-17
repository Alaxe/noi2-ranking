#include<string>
#include<iostream>
using namespace std;
string s;
long long dp[110];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(int i=0;i<s.size();i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(s[j]==s[i]){
                for(int k=j;k<i;k++){
                    dp[j]=(dp[k]+dp[j])%1000000007;
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<s.size();i++) ans=(ans+dp[i])%1000000007;
    cout<<ans<<"\n";
    return 0;
}
