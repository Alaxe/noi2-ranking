#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int n,m;
int grad[10000][10000];
bool used[10000];
int zat,cik;

bool Dfs(int t, int prev)
{
	used[t]=true;		

	for(int i=0;i<n;i++)
	{
		if(grad[t][i]==1 && prev!=i && used[i]==true)
		{	
		zat=prev;cik=i;
		return true;
		
		}
		
	else	 if(used[i]==false && grad[t][i]==1)
		{		
			prev=t;	
			Dfs(i,prev);		
		}
	 		
	}	
	return false;	
}

int FromAtoB(int t,int sum)
{
		used[t]=true;		
		sum++;
		if(grad[t][cik]==1)
		{
			
			sum++;
			return sum;	
			
		}
	
	for(int i=0;i<n;i++)
	{				
	
		 if(used[i]==false && grad[t][i]==1)
		{	
			
			sum++;
			FromAtoB(i,sum);
					
		}		
	}		
	
	return sum;
}



void MakeNotUsed()
{
	for(int i=0;i<n;i++)
	{
		used[i]=false;
	}
}


int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		grad[a-1][b-1]=1;
		grad[b-1][a-1]=1;
	}
	
	MakeNotUsed();
	if(Dfs(0,-1)==false)
	{
		cout<<"0";
	}
	else
	{
		MakeNotUsed();
		grad[zat][cik]=0;
		grad[cik][zat]=0;
		int result=FromAtoB(zat,1);
	//	cout<<result;
	cout<<(result*(result-1))/2<<endl;
		
	}
	
	
}

/*
5 5
1 2
2 3
3 1
2 4
2 5

5 4
1 2
2 3
3 4
4 5


*/



