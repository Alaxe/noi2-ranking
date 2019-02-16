#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> v;
vector<bool> used;
vector<int> ans;
map<pair<int, int>> m;
void dfs(int x)
{
    ans.push_back(x);
    for(int n : v[x])
    {
        if(!used[n])
        {
            used[n]=true;
            dfs(n);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    v.resize(n+1);
    used.resize(n+1);
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<1<<endl;
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            used[i]=true;
            dfs(i);
            int s = ans.size();
            cout<<s<<endl;
            for(int i=0; i<s; i++)
            {
                cout<<ans[i]<<" ";
            }
            while(!ans.empty())
            {
                ans.pop_back();
            }
        }
    }
    return 0;
}
