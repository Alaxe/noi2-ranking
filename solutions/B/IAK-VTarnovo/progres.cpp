#include <iostream>
using namespace std;
int main ()
{
int n,a[1000],max,br=0,k,j,i;
cin>>n;
cin>>a[0];max=a[0];
for(i=1;i<n;i++) {
cin>>a[i]; 
if(max<a[i]) max=a[i];}
for(int d=1;d<=max;d++)
{
	for( i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	 if(a[i]+d==a[i+j]) 
	 	{
	 	br++;
		 for(int k=i+j;k<=n;k++)
		 for(j=0;j<n;j++)
		 if(a[k]+d==a[k+j]) br++;}
	 }
}
cout<<br<<endl;
}
