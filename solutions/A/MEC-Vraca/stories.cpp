#include<iostream>
#include <cmath>
using namespace std;


int main(){
	
	int a[100];
	int K,N,j,max[100];
	do{
		cin>>N>>K;
	}while(N<1&&K<1);
	int FIRST, MUL, ADD, MOD;
	do{
		cin>>FIRST>>MUL>>ADD>>MOD;
	}while (FIRST<0&&MUL<0&&ADD<0&&MOD<=0);
	int i;
	a[0]=FIRST;
	for(i=1;i<=N;i++)
		a[i]=(a[i-1]*MUL+ADD)%MOD;
	cout<<endl;
	int check;
	int st, end;
	for(i=0;i<N;i++)
		cout<<a[i]<<' ';
		cout<<endl;
		max[0]=a[0];
	for(i=1;i<N;i++)
	if (i < K) {
		st = 0;
		end = i;
	} else {
		st = i - K;
		end = i; 
	}
		for(j=st;j<=end;j++)
		{
			
			if(a[j]>=a[j+1]){
				max[i]=a[j];
				break;
			}
			//max[i+j]=a[i];
			if(a[j]<a[j+1])
			{
				max[j+1]=a[j];
			}
		
		}
	
		for(i=0;i<N;i++)
		cout<<max[i]<<' ';
	//	cout<<endl;
		
return 0;
}

