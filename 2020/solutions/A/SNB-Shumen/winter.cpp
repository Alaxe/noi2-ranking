#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int const maxn = 100005;

map<pair<int,int>, bool>mp;
vector<int>v[maxn];
bool used[maxn];
int tin[maxn],fup[maxn],par[maxn];
int n;
int t;

void cut_vertex(int i)
{
    used[i]=true;

    int j,sz=v[i].size();
    tin[i]=fup[i]=t++;
    for(j=0;j<sz;j++)
    {
        int nxt=v[i][j];
        if(!used[nxt])
        {
            par[nxt]=i;

            cut_vertex(nxt);
            fup[i]=min(fup[i],fup[nxt]);

            if(tin[i]<fup[nxt])
            {
                mp[make_pair(i,nxt)]=true;
                mp[make_pair(nxt,i)]=true;
            }
        }
        else
            if(nxt!=par[i])fup[i]=min(tin[nxt],fup[i]);
    }
}


int br;
void dfs(int i)
{
    int j,sz=v[i].size();

    used[i]=true;
    br++;

    for(j=0;j<sz;j++)
    {
        int nxt=v[i][j];
        if(!used[nxt]&&mp[make_pair(i,nxt)]==0)
            dfs(nxt);
    }
}

int ans;
void solve()
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(!used[i])
        {
            br=0;
            dfs(i);
            ans+=br*(br-1)/2;
        }
    }
}

int main()
{
    int m,i,a,b;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cut_vertex(1);
    memset(used,0,sizeof(used));

    solve();

    cout<<ans<<endl;
    return 0;
}
