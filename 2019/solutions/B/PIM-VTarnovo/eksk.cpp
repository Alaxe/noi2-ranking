#include<iostream>
#include<vector>
using namespace std;
vector<int> gr[150000];
bool used[150000];
int a[150000],b[5];
void dfs(int node,int g,int i)
{
	used[node]=1;
	a[node]++;
	for(i=0; i<gr[node].size(); i++) if(gr[node][i]==g) return;
	
	for(int i=0; i<gr[node].size(); i++)
	{
		if(used[gr[node][i]]==false) {dfs(gr[node][i],g,i); b[i]++;}
	}
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,u,v,A,B;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
    	cin>>u>>v;
    	gr[u].push_back(v);
    	gr[v].push_back(u);
	}
	cin>>A>>B;
	int x;
	dfs(A,B,0);
	dfs(B,A,1);
	cout<<b[0]<<" "<<b[1]<<endl;
	if(b[0]<b[1]) x=b[0]; 
	  else x=b[1];
	  
	  int br=0;
	for(int i=1; i<=n; i++)
	{
		if(a[i]==2) br++;
	}
	cout<<x-br+2<<endl;
}

