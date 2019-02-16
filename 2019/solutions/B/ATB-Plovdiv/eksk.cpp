#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
ll l,ans,mans=-1,j,n,a[201000],b[201000],st,en,i,f[201000],curr=0,p=0,d[201000],par[201000],pa[201000];
vector<pair<ll,ll> >q;
vector<ll>adj[201000],o;
bool flag=0,fll=0;
void dfs(ll x)
{
    f[x]=1;
    for(ll y=0; y<adj[x].size(); y++)
        if(f[adj[x][y]]==0)
        {
            par[adj[x][y]]=x;
            d[adj[x][y]]=d[x]+1;
            if(x==en)
            {
                flag=1;
                return;
            }
            dfs(adj[x][y]);
            if(flag==1)return;
        }
}
void parr(ll e)
{if(e==st){fll=1;return;}
    o.push_back(e);
parr(par[e]);
if(fll==1)return;
}

int main()
{
    cin>>n;
    for(i=0; i<n-1; i++)
    {
        cin>>a[i]>>b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    cin>>st>>en;
    dfs(st);
    parr(en);
   o.push_back(st);
   for(i=0;i<o.size()-1;i++)q.push_back({o[i],o[i+1]});
    memset(f,0,sizeof(f));
    memset(d,0,sizeof(d));
    for(i=1; i<=q.size(); i++)
    {
        if(i>1)
        {
            adj[q[i-2].f].push_back(q[i-2].s);
            adj[q[i-2].s].push_back(q[i-2].f);
        }
        for(j=0; j<adj[q[i-1].f].size(); j++)
            if(adj[q[i-1].f][j]==q[i-1].s)
                adj[q[i-1].f].erase(adj[q[i-1].f].begin()+j);
        for(j=0; j<adj[q[i-1].s].size(); j++)
            if(adj[q[i-1].s][j]==q[i-1].f)
                adj[q[i-1].s].erase(adj[q[i-1].s].begin()+j);
        memset(d,0,sizeof(d));
        memset(f,0,sizeof(f));
        d[q[i-1].f]=1;
        dfs(q[i-1].f);
        ll maq=-1,mans=0;
        for(j=1; j<=n; j++)
            maq=max(maq,d[j]);
        mans=maq;
//out<<maq<<endl;
        maq=-1;
        memset(d,0,sizeof(d));
        memset(f,0,sizeof(f));
        d[q[i-1].s]=1;
        dfs(q[i-1].s);
        for(j=1; j<=n; j++)
            maq=max(maq,d[j]);
//cout<<maq<<endl;
        mans=min(mans,maq);
        maq=-1;
        memset(d,0,sizeof(d));
        ans=max(mans,ans);
    }
    cout<<ans<<endl;
    return 0;
}
/*
6
1 2
2 3
3 4
4 5
5 6
4 5
*/
