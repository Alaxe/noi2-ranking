#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
struct op
{
	int k1,k2,k3;
}jk;
vector<op>kl;
int x[1111],y[1111],br[111][111][111],ma;
int main()
{
	int n,c1,c2,c3;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			c1=y[i]-y[j];
			c2=x[j]-x[i];
			c3=x[i]*y[j]-x[j]*y[i];
			jk.k1=c1;
			jk.k2=c2;
			jk.k3=c3;
			kl.push_back(jk);
		}
	}
	int s;
	for(int v=0;v<kl.size();v++)
	{
		s=0;
		for(int h=0;h<n;h++)
		{
			if((kl[v].k1*x[h]+kl[v].k2*y[h]+kl[v].k3)==0)s++;
			
		}
		ma=max(ma,s);
	}
	printf("%d\n",ma);
	return 0;
}


/*


6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3



10
-59 -47
65 66
-35 -18
35 -46
-3 10
33 -71
97 95
-89 -5
-90 -38
-49 -10

*/
