#include<iostream>
using namespace std;
int br;

void find(string s1){
	unsigned long long chis=0;
	int n=s1.size();
	unsigned long long from=0;;
	for(int i=0;i<n;i++){
		chis+=(s1[i]-'0')*10;
		from*=10;
	}
	bool f=true;
	unsigned long long i=from,k;
	while(f){
		k=(i%from)*10+i/from;
		
		if(k-i==chis){
			f=false;
			cout<<i<<endl;
		}
		i++;
	}
}

int main(){
	cin>>br;
	string s[4];
	for(int i=0;i<4;i++){
		cin>>s[i];
	}
	
	for(int i=0;i<4;i++){
		int sum=0;

		for(int j=0;j<s[i].size();j++){
			sum+=s[i][j]-'0';
		}
		if(sum%9!=0)cout<<0<<endl;
		else find(s[i]);
	}
}
