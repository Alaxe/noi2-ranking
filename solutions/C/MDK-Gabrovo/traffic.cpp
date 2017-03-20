#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int nmax=650;
char inp[nmax][nmax];
int n,m;
int mem[nmax][nmax];
bool vis[nmax][nmax];
priority_queue</*cost*/pair<int, pair<int,int> >/*ind1,ind2*/ > pq;
int take(char p)
{
return p-'A'+1;
}
vector< pair<int,int> > adj[nmax][nmax];
int SIZ[nmax][nmax];
void dij(int x,int y)
{
pq.push(mp(0,mp(x,y)));
int SZ=1;
pair<int, pair<int,int> > ALL;
int cost_now;
pair<int,int> ind;
int i;
while(SZ)
{
ALL=pq.top();
cost_now=-ALL.first;
ind=ALL.second;
pq.pop();
SZ--;
if(vis[ind.first][ind.second]==1)continue;
vis[ind.first][ind.second]=1;
mem[ind.first][ind.second]=cost_now;
if(ind.first==1||ind.first==n||ind.second==1||ind.second==m)return;
//cout<<ind.first<<" "<<ind.second<<endl;
//cout<<mem[ind.first][ind.second]<<endl<<endl;
int ADJ=SIZ[ind.first][ind.second];
//cout<<ADJ<<endl;
    for(i=0;i<ADJ;i++)
    if(inp[adj[ind.first][ind.second][i].first][adj[ind.first][ind.second][i].second]!='*')
        if(vis[adj[ind.first][ind.second][i].first][adj[ind.first][ind.second][i].second]==0){pq.push(mp(-(cost_now+take(inp[adj[ind.first][ind.second][i].first][adj[ind.first][ind.second][i].second])),mp(adj[ind.first][ind.second][i].first,adj[ind.first][ind.second][i].second)));SZ++;}
}

}
bool in(int x,int y)
{
return 1<=x&&x<=n&&1<=y&&y<=m;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
int b1,b2;
cin>>n>>m;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
    cin>>inp[i][j];
    if(inp[i][j]=='#')b1=i,b2=j;
    }
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
    if(in(i,j-1)&&inp[i][j-1]!='*'){adj[i][j].push_back(mp(i,j-1));SIZ[i][j]++;}
    if(in(i,j+1)&&inp[i][j+1]!='*'){adj[i][j].push_back(mp(i,j+1));SIZ[i][j]++;}
    if(in(i+1,j)&&inp[i+1][j]!='*'){adj[i][j].push_back(mp(i+1,j));SIZ[i][j]++;}
    if(in(i-1,j)&&inp[i-1][j]!='*'){adj[i][j].push_back(mp(i-1,j));SIZ[i][j]++;}
    }
dij(b1,b2);
int ans=n*m*26;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(i==1||i==n||j==1||j==m)
            if(vis[i][j]==1)ans=min(ans,mem[i][j]);
cout<<ans<<endl;
return 0;
}
/*
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
O(4*SZ*log(4*SZ))
SZ=n*m
*/
