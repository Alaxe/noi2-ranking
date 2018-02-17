#include<iostream>
using namespace std;

long long dp[280][280];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	if(m>n) {
		m=n;
	}
	for(int i=1;i<=m;i++) {
		dp[i][0]=1;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(j-i<0) {
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-i];
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<"\n";
	}
	cout<<dp[m][n]<<"\n";
	return 0;
}
