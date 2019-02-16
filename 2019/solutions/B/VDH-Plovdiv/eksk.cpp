#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector <int> g[200010];
int a, b;
int n;
queue <int> q;
stack <int> q1;
int used[200010];
int pref[200000], suff[200000], par[200000];
bool fl=0;
void dfs(int st)
{
    for (int i=0; i<g[st].size(); i++)

    {
        if (g[st][i]!=par[st])
        {
        par[g[st][i]]=st;
        if (g[st][i]==b) {fl=1;return;}
        dfs(g[st][i]);
        if (fl) return;
        }
    }

    return;
}
bool fl1=0;
void rec(int e)
{
    if (e==a) {fl1=1; return;}
    q1.push(e);
    //cout<<e<<endl;
    used[e]=1;
    rec (par[e]);
    if (fl1==1) return;
}
int bfs(int st)
{
    q.push(st);
    used[st]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
       // if (g[u].size()) {cout<<u<<" ibfel";return used[u];}
        for (int i=0; i<g[u].size(); i++)
        {
            if (used[g[u][i]]==0)
            {//cout<<"jwjowen\n";
                q.push(g[u][i]);
                used[g[u][i]]=used[u]+1;
               // cout<<used[g[u][i]]<<" "<<g[u][i]<<endl;
            }
        }

    }
    int max1=0, max2=0;
    for (int i=1; i<=n; i++)
    {
        max1=max(used[i], max1);
    }
    return max1;
}
int main()
{
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }//cout<<"jwjowen\n";
    cin>>a>>b;
    dfs(a);
    rec(b);//cout<<"jwjowen\n";
    int i=0;
    q1.push(b);
    int m=q1.size(), d[200000];

    while (!q1.empty())
    {
        //cout<<q1.top()<<endl;
        d[i]=bfs(q1.top());i++;
        q1.pop();
        //cout<<d[i]<<" gweo"<<endl;
    }
    pref[0]=d[0];
    for (int i=1; i<m; i++)
    {
        pref[i]=max(pref[i-1], i+d[i]);
        // cout<<
    }
    suff[m-1]=m+d[i]-1;
    for (int i=m-2; i>=0; i--)
    {
        suff[i]=max(suff[i+1], m-i-1+d[i]);
    }
    int ans=0;
    for (int i=0; i<m; i++)
    {
        ans=max(ans, min(pref[i], suff[i+1]));
    }
    cout<<ans<<endl;
}
/*
6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8
*/
