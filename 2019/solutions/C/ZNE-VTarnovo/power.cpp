#include <iostream>
using namespace std;

 bool prosto (int x)
{
	int a=2;
	bool ans=true;
	while(ans==true&&a*a<=x)
	{
    if(x%a==0) ans=false; 
	a++; 
	}
 	return ans;
}

int main()
{

	int n,i,j,pr=1; cin>>n;
	short k, a[n]; cin>>k;
	for(i=0;i<n;i++) cin>>a[i];
	int sort[43]; for(i=0;i<43;i++) sort[i]=0;
			
	for(i=2;i<43;i++) 
	{
	if(prosto(i)==true)
	{
		for(j=0;j<n;j++)
		{
			while(a[j]%i==0) 
			{
			sort[i]++;
			a[j]/=i;
			}
		}
		}	
	}

	for(i=2;i<43;i++) 
	{
		if(sort[i]!=0)
		{
			if(sort[i]%k==0) pr=pr*i*(sort[i]/k);
			else pr=pr*i*((sort[i]/k)+1);
		 } 
	}
	
	cout<<pr;
	return 0;
}

