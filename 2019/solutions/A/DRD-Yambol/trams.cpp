#include <iostream>
#include <vector>
using namespace std;

const int N=(1e5)+5;

vector < pair <int,int> > g[N];
vector <int> ans[N],path;
bool used[N];
bool fl;
int cnt;

void DFS(int v)
{
 int i,sz;

  for(i=0;i<g[v].size();i++)
  {
   if(!used[g[v][i].second])
   {
    used[g[v][i].second]=true;
    path.push_back(g[v][i].first);
    DFS(g[v][i].first);

     if(!fl)
      return;
   }
  }

  sz=(int)path.size();

   if(sz>=2)
   {
    cnt++;
    ans[cnt]=path;
    fl=false;
   }
}

int main()
{

ios::sync_with_stdio(false);
cin.tie(nullptr);

int n,m,u,v,i,j,sz;

cin>>n>>m;

 for(i=1;i<=m;i++)
 {
  cin>>u>>v;
  g[u].push_back(make_pair(v,i));
  g[v].push_back(make_pair(u,i));
 }

 for(i=1;i<=n;i++)
 {
  fl=true;
  path.clear();
  path.push_back(i);
  DFS(i);
 }

cout<<cnt<<"\n";

 for(i=1;i<=cnt;i++)
 {
  sz=(int)ans[i].size();

  cout<<sz<<" ";

   for(j=0;j<sz;j++)
    cout<<ans[i][j]<<" ";

  cout<<"\n";
 }

return 0;
}
