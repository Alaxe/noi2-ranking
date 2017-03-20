#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;
const long long MOD=123456789012345ll;
vector<int>v;
vector<vector<pair<int, int> > >neigh;
int n,ans;
void dfs(int cur, int d)
{
    for(int i=0;i<neigh[cur].size();i++)
    {
        if(d==0)
        {
            ans++;
            dfs(neigh[cur][i].second, neigh[cur][i].first);
        }
        else
        {
            if(neigh[cur][i].first==d)
            {
                ans++;
                dfs(neigh[cur][i].second, neigh[cur][i].first);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    v.resize(n+1);
    neigh.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(v[j]-v[i]>0)
            {
                pair<int, int> cur;
                cur.first=v[j]-v[i];
                cur.second=j;
                neigh[i].push_back(cur);
            }
        }
    for(int i=1;i<=n;i++)
        dfs(i,0);
    cout<<ans<<endl;
    return 0;
}
