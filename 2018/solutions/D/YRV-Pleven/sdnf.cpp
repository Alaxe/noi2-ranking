
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<stack>
#include<queue>
long long n;
using namespace std;
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

string umn(string s1,char c){
	long long d=s1.size(),i,pr=0,ch;
	string s3;
	for(i=d-1;i>=0;i--){
		ch=(s1[i]-'0')*(c-'0')+pr;
		s3=char(ch%10+'0')+s3;
		if(ch>=10)pr=ch/10;
		else pr=0;
	}
	if(pr>=1)s3=char(pr+'0')+s3;
	return s3;
}

string sab(string s1,string s2){
	izr(s1,s2);
	long long d,i,ch,pr=0;
	string s3;
	d=s1.size();
	for(i=d-1;i>=0;i--){
		ch=(s1[i]-'0')+(s2[i]-'0')+pr;
		s3=char(ch%10+'0')+s3;
		if(ch>=10)pr=ch/10;
		else pr=0;
	}
	if(pr>=1)s3=char(pr+'0')+s3;
	return s3;
}

string umn2(string s1,string s2){
	long long d=s2.size(),i;
	string s11,s22,s33;
	s11=umn(s1,s2[d-1]);
	
	for(i=d-2;i>=0;i--){
		s33+="0";
		s22=umn(s1,s2[i]);
		s22=s22+s33;
		s11=sab(s11,s22);
	}
	return s11;
}
int main(){
	long long i,d,sum=0;
	string s1,s2,s3;
	cin>>n;
//	cin>>s1>>s2;
	s3="1";
	s2="9";
	for(i=2;i<=n;i++){
		if(i<=9)s3=umn(s3,char(i+'0'));
		else{
			s2=sab(s2,"1");
			s3=umn2(s3,s2);
		}
	}
	d=s3.size();
	for(i=0;i<d;i++){
		sum+=(s3[i]-'0');
	}
	cout<<sum<<endl;
	return 0;
}
