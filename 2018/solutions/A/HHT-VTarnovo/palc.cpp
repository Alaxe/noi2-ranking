#include<iostream>
using namespace std;
string str;
long long dp[101][101], n;
main(){
	cin>>str;
	n = str.size();
	
	for(int i=0;i<n;i++)dp[i][i] = 1; //Glaven
		
	//Za DP[i][j]
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			dp[j][i+j] = dp[j][i+j-1] + dp[j+1][i+j] - dp[j+1][i+j-1];
			//cout<<"dp["<<j<<"]["<<i+j<<"]="<<dp[j][i+j-1]<<"+"<<dp[j+1][i+j]<<"-"<<dp[j-1][i+j-1];
			if(str[j] == str[i+j]){
				dp[j][j+i] += 1 + dp[j+1][i+j-1];
				//cout<<"+1+"<<dp[j-1][i+j-1];
			}
			//cout<<"="<<dp[j][i+j]<<endl;
			dp[j][i+j] = dp[j][i+j] % 1000000007;
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dp[0][n-1]<<endl;
}
