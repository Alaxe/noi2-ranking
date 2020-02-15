#include <iostream>
#include <math.h>
#include <iomanip>
#include<queue>
using namespace std;

int a[100000]; 
int n;
int answer=0;
int FindMinSteps()
{
	int differ=0;
	int count=0;
	priority_queue<int,vector<int>,less<int> > pQueue;
	for(int y=0;y<n;y++)
	{
		if(pQueue.empty()==false && a[y]<pQueue.top())
		{
			differ=pQueue.top()-a[y];
			count+=differ;
			pQueue.pop();
			pQueue.push(a[y]);
		}
		pQueue.push(a[y]);
	}
	
	
	return count;
}

bool NotIncreasing()
{
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		return false;
	}
	return true;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	if(NotIncreasing()==true)
	{
		cout<<answer<<endl;
	}
	else
	{
		cout<<FindMinSteps()<<endl;
	}
	
}

