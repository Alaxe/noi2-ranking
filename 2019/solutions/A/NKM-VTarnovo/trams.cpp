#include <iostream>
using namespace std;
int n,m,a[100][100],x,y,k,u[1000];
void dfs(int i)                         
	{        
		u[i]=1;  
		cout<<i+1<<" ";                        
		for(k=0; k<n; k++) 
			if(a[i][k]&&!u[k]) dfs(k);
	}
        
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) a[i][j]=0;
	for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			a[x-1][y-1]=1;
			a[y-1][x-1]=1;	
		}
	for (k=0; k<n; k++) u[k]=0;            
	cout<<"1"<<endl;
	dfs(0);
	 
}
// 8 12 2 3 3 4 5 4 2 6 4 8 6 8 8 7 5 7 6 7 1 2 1 5 1 3

