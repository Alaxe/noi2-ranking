#include<iostream>
using namespace std;
const int MOD=1e9+7;
long long dp[105][105];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	long long ans=0;
	for(int i=0;i<s.size();i++){
		for(int j=i;j>=0;j--){
			if(s[i]!=s[j]) continue;
			dp[i][j]=1;
			for(int p=i-1;p>j;p--){
				for(int q=p;q>j;q--){
					dp[i][j]+=dp[p][q];
					dp[i][j]%=MOD;
				}
			}
			ans+=dp[i][j];
			ans%=MOD;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
