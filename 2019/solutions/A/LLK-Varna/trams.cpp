#include<iostream>
#include<vector>
#include<cstring>
#define MAX 40000
using namespace std;
bool line[MAX][MAX];
int n,m;
vector <int> G[MAX];
int tram[MAX];
int lineCount=0;
void dfs(int s)
{
    tram[lineCount]=s;
    lineCount++;
    for(int a=0; a<G[s].size(); a++)
    {
        int k=G[s][a];
        if(line[s][k]==true)
        {
            line[s][k]=false;
            line[k][s]=false;
            dfs(k);
            break;
        }
    }
}
vector <int> ans[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        line[x][y]=true;
        line[y][x]=true;
    }
    int ansLine=0;
    for(int a=1; a<=n; a++)
    {
        lineCount=0;
        memset(tram,0,sizeof(tram));
        dfs(a);
        if(lineCount<2)continue;
        for(int a=0; a<lineCount; a++)
            ans[ansLine].push_back(tram[a]);
            ansLine++;
    }
    cout<<ansLine<<endl;
    for(int a=0; a<ansLine; a++)
    {
        cout<<ans[a].size();
        for(int b=0; b<ans[a].size(); b++)
            cout<<" "<<ans[a][b];
        cout<<endl;
    }
    return 0;
}

