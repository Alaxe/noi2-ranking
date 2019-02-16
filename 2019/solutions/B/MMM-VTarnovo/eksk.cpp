#include <iostream>
#include <vector>

using namespace std;

vector <int> a[200000];
int n,m,count=1,maximum=1;

void graphscan(int n,int m)
{
	int A,B;
	for(int i;i<=m;i++)
	{
		cin>>A>>B;
		a[A].push_back(B);
		a[B].push_back(A);
	}
}

int search(vector <int> gr[200000],int A,int B)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<gr[i].size();j++)
			if(gr[i][j]==A||gr[i][j]==B)gr[i].erase(gr[i].begin()+j,gr[i].begin()+j+1);
	}
	int min1;
	min1=min(gr[A].size(),gr[B].size());
	if(min1==0)return 0;
	for(int i=0;i<min1;i++)
	{
		for(int j=0;j<min1;j++)
		{
			if(gr[A][i]==gr[B][j])
			{
				if(gr[A].size()>1)
				{   
					gr[A].erase(gr[A].begin()+i,gr[A].begin()+i+1);
					i++;
				}
					else if(gr[B].size()>1)
					{
						gr[B].erase(gr[B].begin()+j,gr[B].begin()+j+1);
						j++;
					}
						else return 0;
			}
			count++;
			search(gr,gr[A][i],gr[B][j]);
			maximum=max(count,maximum);
			count--;
		}
	}

}

int main()
{
	int A,B;
	cin>>n;m=n-1;
	graphscan(n,m);
	cin>>A>>B;
	search(a,A,B);
	cout<<maximum<<endl;
}

