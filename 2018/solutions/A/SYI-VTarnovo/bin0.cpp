#include<iostream>
using namespace std;
long long s,t,z,fromS=1,toS=1,before,after;
int a[100][100],ans;

void createPaskal(){
	a[0][0]=a[1][0]=a[1][1]=1;
	
	if(t<=1)return;
	
	for(int i=2;i<=toS;i++){
		for(int j=0;j<=i;j++){
			if(j==i or j==0)a[i][j]=1;
			else a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
}

void checkNum(long long value){
	int br=0;
	
	while(value!=0){
		if(value%2==0)br++;
		value=(value>>1);
	}
	if(br==z)ans++;
}

int main(){
	cin>>s>>t>>z;
	
	bool f=true;
	while(f){
		if((2<<toS)>t)f=false;
		else toS++;
	}
	
	f=true;
	while(f){
		if((2<<fromS)>=s)f=false;
		fromS++;
	}
	
	createPaskal();
	
	for(int i=fromS;i<toS;i++)ans+=a[i][z];

	if((1<<fromS)-s!=0)before=(1<<fromS)-s;
	if((1<<toS)-t!=0)after=(1<<toS)-t;
	
	for(long long i=s;i<(1<<fromS);i++)checkNum(i);
	for(long long i=(1<<toS);i<=t;i++)checkNum(i);
	
	cout<<ans<<endl;
}
