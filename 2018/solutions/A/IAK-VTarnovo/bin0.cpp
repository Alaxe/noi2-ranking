#include <iostream>
using namespace std; 
int main ()
{int a[1000];
	int x,i=0,z,s,t,br=0,br1=0;
	cin>>s>>t>>z;
for(int p=s;p<=t;p++)
	{x=p;
	while(x!=0)
	{	
		a[i]=x%2; x=x/2; i++; 
	}

	for(int j=i-1;j>=0;j--) 
	{
		if(a[j]==0) br++;
}
	if(br==z) br1++;
	i=0;br=0;
	
}
cout<<br1<<endl;
}
