#include<bits/stdc++.h>
using namespace std;
vector<int>graph[50002];
vector<int>ans[200005];
bool used[43302][43302];
void dfs(int v,int a)
{
    for(int i=0; i<graph[v].size(); i++)
    {
        int to=graph[v][i];
        if(!used[v][to]&&!used[to][v])
        {
            ans[a].push_back(to);
            used[v][to]=true;
            used[to][v]=true;
            dfs(to,a);
            break;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int br=0;
    for(int i=1; i<=n; i++)
    {
        ans[i].push_back(i);
        dfs(i,i);
        if(ans[i].size()!=1)
        {
            br++;
        }
    }
    cout<<br<<endl;
    for(int i=1;i<=n;i++)
    {
        if(ans[i].size()!=1)
        {
            cout<<ans[i].size()<<" ";
            for(int k=0; k<ans[i].size(); k++)cout<<ans[i][k]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
