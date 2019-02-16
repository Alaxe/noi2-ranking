#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
ll root,j,n,k,sz,i,a,br[5100],maxx=-1,pos,f,pr[5100],fq[5100],sum=0;
vector<ll>nach[5100],adj[5100],par[5100];
queue<ll>q;
int main()
{cin>>n>>k;
for(i=0;i<n;i++)
{cin>>sz;
for(j=0;j<sz;j++){cin>>a;
if(a!=(i+1)){
nach[i+1].push_back(a);
br[a]++;
}
}
}
for(i=1;i<=n;i++)if(maxx<br[i]){maxx=br[i];pos=i;}
root=pos;
while(n>0)
{maxx=-1;
for(i=1;i<=n;i++)if(maxx<br[i]){maxx=br[i];pos=i;}
for(i=1;i<=n;i++){
f=0;
for(j=0;j<nach[i].size();j++)if(nach[i][j]==pos){adj[pos].push_back(i);f=1;}
if(f==1)nach[i].clear();
}
nach[pos].clear();
memset(br,0,sizeof(br));
ll ff=0;
for(i=1;i<=n;i++)
if(nach[i].size()>0){ff=1;for(j=0;j<nach[i].size();j++)br[nach[i][j]]++;}
//cout<<maxx<<" "<<pos<<endl;
if(ff==0)break;
}
for(i=1;i<=n;i++){
if(adj[i].size()==0){fq[i]=1;q.push(i);}
}
for(i=1;i<=n;i++){
for(j=0;j<adj[i].size();j++)par[adj[i][j]].push_back(i);
}
/*for(i=1;i<=n;i++){
for(j=0;j<par[i].size();j++)cout<<par[i][j]<<" ";
cout<<endl;}*/
while(q.empty()==false)
{pr[q.front()]+=k;
for(i=0;i<par[q.front()].size();i++){pr[par[q.front()][i]]+=pr[q.front()];if(fq[par[q.front()][i]]==0){q.push(par[q.front()][i]);fq[par[q.front()][i]]=1;}}
q.pop();
}
for(i=1;i<=n;i++)sum+=pr[i];
cout<<sum<<endl;
return 0;
}
