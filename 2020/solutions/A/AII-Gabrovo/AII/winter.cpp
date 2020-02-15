# include<iostream>
# include<vector>
# include<utility>
using namespace std;

vector<int> g[100001];
int vis[100001];
vector<int> path,cir;
void dfs(int u, int start, int last)
{
    if(u==start && path.size()>2)
    {
        if(path.size()>cir.size()) cir=path;
        return;
    }
    vis[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        if(!vis[g[u][i]] || g[u][i]==start && g[u][i]!=last)
        {
            path.push_back(g[u][i]);
            dfs(g[u][i],start,u);
            path.pop_back();
        }
    }
    vis[u]=0;
}

void del(int u)
{
    if(g[u].size()==2)
    {
        vis[u]=1;
        for(int i=0; i<g[u].size(); i++)
        {
            if(!vis[g[u][i]]) del(g[u][i]);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(g[i].size()==1)
        {
            vis[i]=1;
            del(g[i][0]);
        }
    }

    long long ans=0;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            cir.clear();
            dfs(i,i,0);
            int k=cir.size();
            for(int i=0; i<k; i++) vis[cir[i]]=1;
            ans+=(k*(k-1)/2);
        }
    }
    cout<<ans<<endl;
}

/*
7 9
1 2
2 3
3 1
2 4
2 5
3 6
5 7
5 4
4 7


5 6
1 2
2 3
3 4
4 1
4 5
5 3

8 10
1 2
2 3
3 4
4 1
4 5
5 3
3 6
6 7
4 8
5 8

12 15
1 2
2 3
3 4
4 1
4 5
5 3
3 6
6 7
4 8
5 8
6 9
9 10
10 11
11 12
2 12
*/
