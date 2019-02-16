#include <iostream>
#include <math.h>
using namespace std;
int n,b,br,i; 
int p[50]={3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,
67,71,73,79,83,89,97,101,103,107,109,
113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,
197,199};
int broi(int n)
	{
		int broj=0;
		while(n!=0)
			{
				n=n/10;
				broj++;
			}
		return broj;
	}
int main()
{
	cin>>n;
	br=broi(n);
	if(n%2==1) n++;
	while(br<=broi(n))
		{
			for(i=0;i<=20;i++)
				{
					long long s=p[i]*p[i]+n; int j=2,b=0;
					while(j<=sqrt(s)&&!b)
						{
							if(s%j==0) b=1;
							j++;
						}
					if (!b) i=45; 	
				}
			if(i<=44) {cout<<n<<endl; return 0;}
			n=n+2;
		}
	cout<<"0"<<endl;
}

