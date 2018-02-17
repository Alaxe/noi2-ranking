#include<iostream>
using namespace std;
int main(){
	long long n,q,naiVisoko=0,cvetia[10000],sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cvetia[i];
		if(cvetia[i]>naiVisoko){
			naiVisoko=cvetia[i];
		}
	}
	cin>>q;
		for(int i=0;i<n;i++){
			sum=sum+(naiVisoko-cvetia[i])*q;
		}
		cout<<sum;
return 0;
}
