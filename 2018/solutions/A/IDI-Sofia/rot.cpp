#include<iostream>
#include<vector>
using namespace std;
void vectorize(string s,vector<int>& m){
	for(int j=s.size()-1;j>=0;j--){
		if(s[j]>='A'&&s[j]<='Z'){
			m.push_back(s[j]-'A'+10);
		}else{
			m.push_back(s[j]-'0');
		}
	}
}
void div(vector<int>& target, int divisor, int& rem, int sys){
	rem=0;
	for(int j=target.size()-1;j>=0;j--){
		rem*=sys;
		rem+=target[j];
		target[j]=rem/divisor;
		rem%=divisor;
	}
	while(target.size()>0&&target.back()==0) target.pop_back();
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int b;
	cin>>b;
	string mStr;
	for(int i=0;i<4;i++){
		cin>>mStr;
		vector<int> m;
		vectorize(mStr,m);
		int remainder;
		div(m,b-1,remainder,b);
		if(remainder!=0){
			cout<<"0\n";
			continue;
		}
		cout<<"1";
		for(int j=0;j+1<m.size();j++){
			m[j]++;
			m[j+1]+=m[j]/b;
			m[j]%=b;
		}
		m[m.size()-1]++;
		while(m.back()>=b){
			m.push_back((m.back()/b)+1);
			m[m.size()-2]%=b;
		}
		for(int j=m.size()-1;j>=0;j--){
			if(m[j]>=10){
				cout<<char('A'+m[j]-10);
			}else{
				cout<<m[j];
			}
		}
		cout<<"\n";
	}
	return 0;
}
