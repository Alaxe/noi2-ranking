#include <bits/stdc++.h>
using namespace std;
int n,m,br;
vector<int>v[50002];
map< pair<int,int>, int>used;
vector<int>ans[50002];
bool lamp=0;

void read()
{
    int i,j,a,b;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void DFS(int i)
{
    ans[br].push_back(i);
    int j,nb,sz=v[i].size();
    for(j=0; j<sz; j++)
    {
        nb=v[i][j];
        if(used[ {i,nb}]==0)
        {
            lamp=true;
            used[ {i,nb}]=used[ {nb,i}]=1;
            DFS(nb);
            return ;
        }
    }
}
int main()
{
    read();
    int i,j;
    for(i=1; i<n; i++)
    {
        DFS(i);
        if(lamp){br++;lamp=0;}
        else ans[br].clear();
    }
    cout<<br<<endl;
    for(i=0;i<br;i++)
    {
        cout<<ans[i].size()<<" ";
        for(j=0;j<ans[i].size();j++)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
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
