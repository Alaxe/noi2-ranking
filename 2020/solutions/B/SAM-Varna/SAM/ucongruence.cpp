#include<iostream>
using namespace std;
unsigned long long C(int u,int n)
{
	unsigned long long s=1;
	int k=1;
	while(k<=n)
	{

		s=(s*u)/k;
		k++;u--;
	}
	return s;
}

bool ht[61];
int n,u;
int a[1000000];
void Read()
{
	cin>>n>>u;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ht[a[i]]=1;
	}

}
int rn=0;
unsigned long long s=1;
int p[61];
bool usd[61];
void Solve()
{
	vector<int> ip,ep;
	for(int i=0;i<61;i++)
	{
		if(ht[i]==1)
		{
			rn++;
			uds[rn]=1;
			p[i]=rn;
		}
	}
	for(int i=0;i<n;i++)
	{
		a[i]=p[a[i]];
		if(usd[a[i]]!=0)
		{
			ep.push_back(a[i]);
			ip.push_back(a[i]);
			usd[a[i]]=0;
		}

	}
	unsigned long long tr=(s+1)/2;
	int br=0;
    int i=0;
    int tu=u;
    while(tr>0)
	{
		if(C(u-1,rn-1)<tr) (tr-=C(u-1,rn);br++;u--;)
		else if(C(u-1,rn)==tr)
		{
			ep[i]+=br;
			break;
		}
		else
		{
			rn--;
			i++;
			tu=u-i;
			br=0;
		}
	}
	a[0]=
	for(int i=1;i<n;i++)
	{
		a[i]=ep[a[i]];
		cout<<
	}

}
int  main()
{

	return 0;
}
