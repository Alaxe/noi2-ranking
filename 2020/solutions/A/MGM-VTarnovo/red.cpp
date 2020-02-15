#include <iostream>
#include <cstdio>
#include <set>
#include <deque>

using namespace std;

int w,k;
int m,n;
int a[10000],b[10000];
long long ans=0;
multiset<deque<int> >A;
void init()
{
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
}
void findKRowsA()
{
	deque<int>de;
	int prev=a[0];
	int por=1;
	de.push_back(a[0]);
	for(int i=1;i<n;i++)
	{
		de.push_back(a[i]);
		if(w==1)
		{
			if(prev<a[i])
			{
				por++;	
			}
			else
			{
				por=1;	
			}	
			if(por>=k)
			{
				A.insert(de);
			}
		}
		else
		{
			if(prev==a[i])
			{
				por++;	
			}
			else
			{
				por=1;	
			}	
			if(por>=k)
			{
				A.insert(de);
			}
		}
		prev=a[i];
		if(de.size()>=k)de.pop_front();	
	}
}
void findKRowsB()
{
	deque<int>de;
	de.push_back(b[0]);
	int prev=b[0];
	int por=1;
	for(int i=1;i<m;i++)
	{
		de.push_back(b[i]);
		if(w==1)
		{
			if(prev<b[i])
			{
				por++;	
			}
			else
			{
				por=1;	
			}	
			if(por>=k)
			{
				ans+=A.count(de);
			}
		}
		else
		{
			if(prev==b[i])
			{
				por++;	
			}
			else
			{
				por=1;	
			}	
			if(por>=k)
			{
				ans+=A.count(de);
			}
		}	
		prev=b[i];
		if(de.size()>=k)de.pop_front();
	}
}
void findKRows()
{
	findKRowsA();
	findKRowsB();
}
int main()
{
	init();
	findKRows();
	printf("%lld\n",ans);
}

