#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
long long n;
string s;
void izr(string &s2,string &s3){
	long long d2=s2.size(),i,d3=s3.size();
	if(d2<d3){
		for(i=1;i<=d3-d2;i++){
			s2="0"+s2;
		}
	}
	if(d3<d2){
		for(i=1;i<=d2-d3;i++){
			s3="0"+s3;
		}
	}
}
int izv(string &st1,string st2){
	long long d1=st1.size(),pr=0,i,fl=0,p=-1;
	izr(st1,st2);
//	cout<<st1<<" "<<st2<<endl;
	string s3;
	for(i=d1-1;i>=0;i--){
		
		if((st1[i]-'0')-pr-(st2[i]-'0')>=0){
			s3=char((st1[i]-'0')-pr-(st2[i]-'0')+'0')+s3;
			if(s3[0]=='0' && fl==0){
				p=i;
				fl=1;
			}
			else{
				fl=0;
			}
			pr=0;
		}
		else{
			s3=char(10+(st1[i]-'0')-pr-(st2[i]-'0')+'0')+s3;
			if(s3[0]=='0' && fl==0){
				p=i;
				fl=1;
			}
			else{
				fl=0;
			}
			pr=1;
		}
	}
	st1=s3;
	if(fl==1){
		return  st1.size()-p-1;
	}
//	cout<<st1<<" "<<pr<<" "<<st1.size()<<endl;
	return st1.size();
}
int main(){
	long long i,d;
	string s3,s2;
	cin>>n>>s;
	//n=6;
	//s="2";
	s2=s;
	if(s.size()==n){
		cout<<s<<endl;
		return 0;
	}
	d=s.size();
	for(i=1;i<=n-d;i++){
		s2=s2+"0";
	}
//	izv(s2,s);
	//cout<<s2<<endl;
	while(1){
		s3=s2;
		if(izv(s2,s)<n){
			cout<<s3<<endl;
			return 0;
		}
		d=izv(s2,s);
	}
	cout<<s2<<endl;
	return 0;
}
