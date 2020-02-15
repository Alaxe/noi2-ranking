#include <iostream>
using namespace std;
int main()
{
	int n, W1, W2, a[200], b[200], k=0, max;
	cin>>n>>W1>>W2;
	for(int i=0;i<=n-1;i++)
	cin>>a[i];
	
	for(int i=0;i<=n-1;i++)
	  for(int j=i+1;j<=n-1;j++)
	{
		if(a[i] + a[j]<=W1) b[k]=a[i]+a[j];
	    k++;
	}
	 max=b[0];
	 for(int i=1;i<=k-1;i++)
    if(max<b[i]) max=b[i];
    
    cout<<max;
}
