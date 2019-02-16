#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n>100000||n<0){
		cout<<"N>100000||N<0"<<endl;
		while(n>100000){
			cin>>n;
		}
		while(n<0){
			cin>>n;
		}
	}
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>100000||a[i]<0){
			cout<<"N>100000||N<0"<<endl;
			while(a[i]>100000){
			cin>>a[i];
			}
			while(a[i]<0){
				cin>>a[i];
			}
		}
	}

	int sumv=1,sumn=0,max[10],u=0;
	for(int i=0;i<10;i++) {
		max[i]=0;
	}
	for(int i=1;i<n;i++){
		while(a[i-1]<a[i]){
			sumv++;
			i++;
		}
		max[u]+=sumv;
		sumv=1;
		if(i<n){
			while(a[i-1]>a[i]){
				sumn++;
				i++;
			}
			max[u]+=sumn;
			sumn=1;
			u++;
	    	}
		}
	int answer=max[0];
	for(int i=0;i<10;i++){
		if(answer<max[i]) answer=max[i];
	}
	cout<<answer;
}
