#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,w1,w2;
int a[256];

void Read()
{
	cin>>n>>w1>>w2;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
}
int Sol1()
{
	int ans;
	int t[200][200];
	vector<int> u[200][200];
	for(int i=0;i<w1;i++)
	{
		if(a[0]>i+1)
		{
			u[0][i].clear();
			t[0][i]=0;
		}
		else
		{
			u[0][i].push_back(0);
			t[0][i]=a[0];
		}
	}

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<w1;j++)
		{
			u[i][j].clear();
			if(a[i]>j+1)
			{
				t[i][j]=t[i-1][j];
				u[i][j]=u[i-1][j];
			}
			else if(a[i]==j+1)
			{
				t[i][j]=a[i];
				u[i][j].push_back(i);
			}
			else
			{
				if(a[i]+t[i-1][j-a[i]]>=t[i-1][j])
				{
					t[i][j]=a[i]+t[i-1][j-a[i]];
					u[i][j]=u[i-1][j-a[i]];
					u[i][j].push_back(i);
				}
				else
				{
					t[i][j]=t[i-1][j];
					u[i][j]=u[i-1][j];
				}

			}
		}

	}

	ans=t[n-1][w1-1];
	bool used[200];
	for(int i=0;i<200;i++) used[i]=0;
	for(int i=0;i<u[n-1][w1-1].size();i++)
	{
		used[u[n-1][w1-1][i]] =1;
	}

	for(int i=0;i<w2;i++)
	{
		if(a[0]>i+1) t[0][i]=0;
		else
		{
			if(used [0]==1) t[0][i]=0;
			else t[0][i]=a[0];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<w2;j++)
		{
			if(used[i]==1) t[i][j]=t[i-1][j];
			else
			{
				if(a[i]>j+1)
				{
					t[i][j]=t[i-1][j];
				}
				else if(a[i]==j+1)
				{
					t[i][j]=a[i];
				}
				else
				{
					t[i][j]=max(t[i-1][j],a[i]+t[i-1][j-a[i]]);
				}
			}
		}
	}
	ans+=t[n-1][w2-1];
	return ans;
}
int main()
{
	Read();
	cout<<Sol1()<<endl;
	return 0;
}
