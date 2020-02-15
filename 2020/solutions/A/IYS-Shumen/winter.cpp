#include<bits/stdc++.h>
using namespace std;
const int MAXN = (int)(1<<18);
long long n,m,used[MAXN],tin[MAXN],fup[MAXN],timer=0,art[MAXN],ans;
map< pair<int,int>,int>mp;
vector<int>g[MAXN],v;
void DFS(int x,int p)
{
    used[x]=true;
    //cout<<x<<" "<<p<<endl;
    tin[x]=fup[x]=timer++;
    for(auto to:g[x])
    {
        if(to==p)
            continue;
        if(used[to])
            fup[x]=min(fup[x],tin[to]);
        else
        {
            DFS(to,x);
            fup[x]=min(fup[x],fup[to]);
            if(fup[to]>tin[x])
            {
                mp[{to,x}]=mp[{x,to}]=1;
            }
        }
    }
    //if(p==-1&&child>1)cout<<"-> "<<x<<endl;
}
void read()
{
    int i,j,x,y;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
int br=0;
void DFS1(int i)
{
    used[i]=true;
    br++;
    for(auto nb:g[i])
    {
        if(!used[nb]&&!mp[{i,nb}])DFS1(nb);
    }
}
int main()
{
    read();
    for(int i=1; i<=n; i++)
        if(!used[i])
            DFS(i,-1);
    memset(used,0,sizeof(used));
    for(int i=1; i<=n; i++)
        if(!used[i])
            {DFS1(i);ans+=(br*(br-1));br=0;}
    cout<<ans/2<<endl;
    //for(auto nb:v)cout<<nb<<endl;
    return 0;
}
