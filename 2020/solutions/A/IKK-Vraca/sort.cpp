#include <iostream>
using namespace std;
int main(){
int n;
cin>> n;
if(0>n || n>100000 ) return 0;

int a[n];
int count = 0,min = 0;
for(int i=0;i<n;i++) cin>>a[i];
for(int i=0;i<n-1;i++)
{
if(a[i]>a[i+1] && a[i+1]>min)     // a1>a2
{
	while(a[i]!=a[i+1]){
		a[i]--;count++;
	}
	
	min = a[i];
}
else if(a[i+1]<min)
{
	while(a[i+1]!=min){
		a[i+1]++;count++;
	}
}
}

cout<<count;
return 0;
}

