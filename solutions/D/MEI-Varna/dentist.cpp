#include <iostream>
//#include <windows.h>
using namespace std;
int main()
{
	int a[721],m[721],n,i=0,j,te,x;
	while(1)
	{
	    cin>>a[i]>>m[i];
	    if(cin.eof()) break;
	    i++;
	}
	n=i;
	for(i=0;i<=n-1;i++)
	{
	    for(j=i+1;j<=n-1;j++)
	    {
	        if(a[i]>a[j])
	        {
	            swap(a[i],a[j]);
	            swap(m[i],m[j]);
	        }
	    }
	}
	x=a[n-1];
	for(i=0;i<n;i++)
	{
	    te=a[i]+m[i];
	    if(te>a[i+1]) a[i+1]=te;
	}
	cout<<te-x<<endl;
	return 0;
}

