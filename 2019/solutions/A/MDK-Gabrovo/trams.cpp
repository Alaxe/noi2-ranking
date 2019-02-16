#include<bits/stdc++.h>
using namespace std;
const int nmax=5e4+42,LIM=2e5+42;
int n,m;
vector< pair<int/*node*/,int/*edge id*/> > adj[nmax];
int deg[nmax];
stack<int> st;
bool blocked[LIM];
void dfs(int node)
{
    for(auto k:adj[node])
        if(blocked[k.second]==0)
        {
        blocked[k.second]=1;
        dfs(k.first);
        }
    st.push(node);
}
int arr[LIM];
int broken[nmax];
void make_path(int l,int r)
{
    printf("%i",r-l+1);
    for(int j=l;j<=r;j++)
        printf(" %i",arr[j]);
    printf("\n");
}
int main()
{
scanf("%i%i",&n,&m);
int x,y;
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&x,&y);
    deg[x]++;
    deg[y]++;
    adj[x].push_back({y,i});
    adj[y].push_back({x,i});
}
vector<int> odd={};
for(int i=1;i<=n;i++)
    if(deg[i]%2==1)odd.push_back(i);
int m_=m,SZ=odd.size();

int paths=1;

for(int i=0;i<SZ-2;i=i+2)
{
    paths++;
    m_++;
    adj[odd[i]].push_back({odd[i+1],m_});
    adj[odd[i+1]].push_back({odd[i],m_});
    broken[odd[i]]=odd[i+1];
    broken[odd[i+1]]=odd[i];
    //cout<<odd[i]<<" "<<odd[i+1]<<endl;
}
if(odd.size())dfs(odd[odd.size()-1]);
else dfs(1);

SZ=st.size();
for(int i=1;i<=SZ;i++)
{
    arr[i]=st.top();
    st.pop();
}
/*
for(int i=1;i<=SZ;i++)cout<<arr[i]<<" ";cout<<endl;
*/
printf("%i\n",paths);

int prev=1;
for(int i=2;i<SZ;i++)
    if(broken[arr[i-1]]==arr[i])
    {
        make_path(prev,i-1);
        prev=i;
        broken[arr[i-1]]=0;
        broken[arr[i]]=0;
    }
make_path(prev,SZ);
return 0;
}
/*
8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3
*/
