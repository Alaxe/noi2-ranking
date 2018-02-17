#include<iostream>
using namespace std;
int main(){
	long long n,k,i,z=1;
	cin>>n>>k;
	for(int j=0;j<n;j++){
		z=z*10;
	}
	if(k>z/10){
		cout<<"NO";
	}else{
		for(i=z/10;i%k!=0;i++){}
		cout<<i;
	}
return 0;
}
