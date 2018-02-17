#include <iostream>
using namespace std;
int main ()
{
	int a[1000],n,i,j,k,d,max,min;
	long long br=0;
	cin>>n;
	for (i=0;i<n;i++) cin>>a[i];
	max=a[0];
	min=a[0];
	for (i=1;i<n;i++)
		if (a[i]>max) max=a[i];
		else if (a[i]<min) min=a[i];
	for (d=1;d<=max-min;d++)
		for (i=0;i<n-1;i++)
			for (j=i+1;j<n;j++)
				if (a[j]==a[i]+d) br++;
					else 
						{
							k=0;
							while (j-k>0)
								{
									if (a[j-k]==a[j]-1-k+d&&a[j]-1-k==a[i]+d) br++;
									k++;
								}
						}
	cout<<br%123456789012345<<endl;		
}
// 3 1 2 3 
// 6 1 9 1 9 2 3
