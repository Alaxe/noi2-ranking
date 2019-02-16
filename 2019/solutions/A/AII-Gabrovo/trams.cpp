# include<iostream>
# include<vector>
# include<utility>
# include<queue>
using namespace std;

vector<int> g[100001];
pair<int,int> a[100001];
int used[100001];
vector<pair<int,int> > path,ans[100001];
int k=0;
int mxs=0;
void dfs(int u, int br)
{
    for(int i=0; i<g[u].size(); i++)
    {
        if(!used[g[u][i]])
        {
            used[g[u][i]]=1;
            if(a[g[u][i]].first==u) {path.push_back(make_pair(a[g[u][i]].second,g[u][i])); dfs(a[g[u][i]].second,br+1);}
            else {path.push_back(make_pair(a[g[u][i]].first,g[u][i])); dfs(a[g[u][i]].first,br+1);}

            used[g[u][i]]=0;
            path.pop_back();
        }
    }
    if(br>mxs)
    {
        mxs=br;
        ans[k]=path;
    }
}

int main()
{
    ios::sync_with_stdio();
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>a[i].first>>a[i].second;
        g[a[i].first].push_back(i);
        g[a[i].second].push_back(i);

    }

    for(int i=1; i<=m; i++)
    {
        path.clear();
        mxs=0;
        if(!used[i])
        {
            path.push_back(make_pair(a[i].first,i));
            dfs(a[i].first,1);
             for(int j=0; j<ans[k].size(); j++)
                used[ans[k][j].second]=1;

            k++;
        }
    }
    cout<<k<<endl;
    for(int i=0; i<k; i++)
    {
        cout<<ans[i].size()<<" ";
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j].first<<" ";
            used[ans[i][j].second]=1;
        }
        cout<<endl;
    }
}
