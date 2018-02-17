#include<iostream>
using namespace std;
string s;
int ans=0,m[101][101],n;
char a[100];

int checkBr(int i,int j){
	if(i-j==0)return 1;
	
	int br=0;	
	for(int k=i+1;k<j;k++){
		br+=m[i+1][k];
		if(a[k]==a[i] and j-k==1)br++;
	}
	if(i+1==j)return 1;
	return br;
}

int main(){
	cin>>s;
	
	n=s.size();
	for(int i=0;i<n;i++){
		a[i]=s[i];
		m[i][i]=1;		
	}
	
	for(int i=n-1;i>=0;i--){
		int max=-100;
		for(int j=i;j<=n-1;j++){
			if(a[j]!=a[i]||j-i==0){			
				m[i][j]=1;
			}else{
				int br=checkBr(i,j);
				m[i][j]=2+br;
			}
			if(max<m[i][j])max=m[i][j];
		}
		ans+=max;
	}
	cout<<ans%1000000007<<endl;
}
