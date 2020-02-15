#include <iostream>
#include<cstdio>
using namespace std;

int n,m,k,w;
int a[1000005],b[100005];

void init()
{
	int ans=0;
	scanf("%d%d",&w,&k);		
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		if(w==2)
		{
			for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int e=0;
				while(a[e+i]==b[j+e] && e<k)
				{
					e++;
				}
				if(e==k) ans++;
			}
		}
			printf("%d\n",ans);
		}
		else cout<<ans<<endl;
}

int main()
{
	init();
}


