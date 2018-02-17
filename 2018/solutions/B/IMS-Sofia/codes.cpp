#include<iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	unsigned long long n,k,a,b,red[104],raz[104];
	unsigned long long razlika,raz_max=0;
	cin>>n>>k>>a>>b;
	cin>>red[1];
	int maxx=-1;
	maxx=red[1];
	int j=2*n;
	for(int i=2;i<=n;i++){
		cin>>red[i];
		red[j]=red[i];
		raz[i-1]=max(red[i],red[i-1])-min(red[i],red[i-1]);
		if(raz[i-1]>raz_max){
			raz_max=raz[i-1];
		}
		if(red[i]>maxx){maxx=red[i];}
		j--;
	}
	razlika=raz_max;
	unsigned long long stepen=n;
	for(int i=2;i<k;i++) {
		stepen*=n;
	}


	int otg[10002];
	for(int i=0;i<=n;i++){
		otg[i]=maxx;
	}
	

	int i=0;
	for(;a<b;i++) {
		unsigned long long a1=a/stepen+1,b1=b/stepen+1;
		if(a%stepen==0) {
			a1--;
		}
		if(b%stepen==0){
			b1--;
		}
		if(red[a1]<red[b1]) {
			a=a+(stepen-a%stepen)+1;
			otg[i]=red[b1];
		}else if(red[a1]>red[b1]){
			b=b-b%stepen;
			otg[i]=red[a1];
		}else{
			otg[i]=red[a1];
		}		
		a%=stepen;
		b%=stepen;
		if(a==0) {
			a+=stepen;
		}
		if(b==0) {
			b+=stepen;
		}
		stepen/=n;
	}
	if(a==b) {
		otg[i]=red[a];
	}
	for(int i=0;i<k;i++){
		cout<<otg[i];
	}
	cout<<" "<<razlika<<"\n";
	return 0;

}
