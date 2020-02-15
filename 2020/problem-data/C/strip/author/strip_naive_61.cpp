//Author: Miroslav Mihajlov
#include <iostream>
#include <cstdio>

using namespace std;

int mini,maxi;
int n,k;

int find(int index)
{
	if(index==n)return 1;
	int sum=0;
	if(mini>1)
	{
		mini--;
		sum+=find(index+1);
		mini++;	
	}
	if(maxi<n)
	{
		maxi++;
		sum+=find(index+1);
		maxi--;	
	}
	return sum;
}

int main()
{
	scanf("%d%d",&n,&k);
	mini=k;
	maxi=k;
	printf("%d\n",find(1));
	
}
