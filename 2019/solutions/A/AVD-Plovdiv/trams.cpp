#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[50042],v[50042];
map<pair<int,int>,bool>used;
vector<vector<int> >ans,finalAns;
vector<int>currvect;
int idxs[50042];
void dfs(int i)
{
    int j=0;
    while(j<v[i].size() && used[make_pair(min(i,v[i][j]),max(i,v[i][j]))]==1)
        j++;
    if(j!=v[i].size())
    {
        used[make_pair(min(i,v[i][j]),max(i,v[i][j]))]=1;
        currvect.push_back(v[i][j]);
        dfs(v[i][j]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        idxs[i]=i+1;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int QQ=1;QQ<=10;QQ++)
    {
        for(int i=0;i<50042;i++)
            v[i]=g[i];
        used.clear();
        ans.clear();
        random_shuffle(idxs,idxs+n);
        for(int i=0;i<n;i++)
        {
            currvect.push_back(idxs[i]);
            dfs(idxs[i]);
            if(currvect.size()!=1)
                ans.push_back(currvect);
            currvect.clear();
        }
        if(ans.size()<finalAns.size() || finalAns.size()==0)
            finalAns=ans;
    }
    cout<<finalAns.size()<<endl;
    for(int i=0;i<finalAns.size();i++)
    {
        cout<<finalAns[i].size()<<" ";
        for(int j=0;j<finalAns[i].size();j++)
            cout<<finalAns[i][j]<<" ";
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

6 7
1 2
2 3
3 4
4 2
1 6
6 5
1 5
*/
