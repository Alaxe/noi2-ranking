#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>sumi;

bool imavveca(int suma)
{
	for(int i=0;i<sumi.size();i++)
	{
		if(sumi[i]==suma)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int N;
	bool in=false;
	cin>>N;
	int indn=-1;
	bool io=0;
	int co=0;
	int oti[N];
	int r[N];
	int cursum=0;
	for(int i=0;i<N;i++)
	{
	cin>>r[i];
	if(r[i]==0)
	{
	in=true;
	indn=i;	
	}
	if(r[i]<0)
	{
		io=true;
		oti[co]=i;
		co++;
	}
	
	}	
	while(next_permutation(r,r+N))
	{
		for(int bc=1;bc<=N;bc++)
		{
			for(int j=0;j<bc;j++)
			{
				cursum=cursum+(r[j]);			
			}	
			if(imavveca(cursum)==false)
			{
				sumi.push_back(cursum);
			}
			cursum=0;
		}
	}
	if(in==true)
	{
		swap(r[in],r[0]);
		while(next_permutation(r,r+N))
		{
			for(int bc=0;bc<N;bc++)
			{
				for(int j=0;j<bc;j++)
				{
				cursum=cursum+(r[j]);			
				}	
				if(imavveca(cursum)==false)
				{
				sumi.push_back(cursum);
				}
				cursum=0;
			}
		}
	}
	if(io==true)
	{
		for(int i=0;i<co;i++)
		{
		swap(r[oti[i]],r[0]);
		while(next_permutation(r,r+N))
		{
			for(int bc=0;bc<=N;bc++)
			{
				for(int j=0;j<bc;j++)
				{
				cursum=cursum+(r[j]);		
				}	
				if(imavveca(cursum)==false)
				{
				sumi.push_back(cursum);
				}
				cursum=0;
			}
		}
	}
	}
	cout<<sumi.size();
	return 0;
}
