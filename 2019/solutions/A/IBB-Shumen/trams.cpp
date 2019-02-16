#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,otg;
int used[20000][20000];
vector<int>v[131072];
vector<int>ans[131072];
///----------------------------------------------
void read()
{
    int x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
///----------------------------------------------
void DFS(int i)
{
    //cout<<i<<"  lalal"<<endl;
    ans[otg].push_back(i);
    for(int j=0;j<v[i].size();j++)
    {
        int nb=v[i][j];
        if(!used[i][nb])
            {
                used[i][nb]=1;
                used[nb][i]=1;
                DFS(nb);
                otg++;
                ans[otg].push_back(i);
            }
    }
}
///----------------------------------------------
void solve()
{
    DFS(1);
    int br=0;
    for(int i=0;i<otg;i++)
    {
        if(ans[i].size()>1)br++;
    }
    cout<<br<<endl;
    for(int i=0;i<otg;i++)
    {
        if(ans[i].size()>1)
        {
            cout<<ans[i].size()<<" ";
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
///----------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    solve();
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
