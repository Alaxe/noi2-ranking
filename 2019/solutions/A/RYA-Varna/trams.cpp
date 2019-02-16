#include <bits/stdc++.h>
using namespace std;
const int maxN=5e4+10,maxM=1e5+1;
int n,m;
struct node{
    int v,ind;
    node(){}
    node(int a,int b){
        v=a;
        ind=b;
    }
};
struct edge{
    int b,e;
    long long t;
};
edge edges[maxM];
vector<node> graph[maxN];
int vis[maxM],usede[maxM],used[maxN];
int k;
bool fl;
vector<int> paths[maxN];
void dfs(int s,int b)
{
    if(fl==1)return;
    if(s!=b && graph[s].size()%2==1 && used[s]==0)
    {
        paths[k].push_back(s);
        used[s]=1;
        fl=1;
        return;
    }
    for(int i=0;i<graph[s].size();i++)
    {
        if(vis[graph[s][i].ind]!=k+1 && vis[graph[s][i].ind]!=-1)
        {
            vis[graph[s][i].ind]=k+1;
            dfs(graph[s][i].v,b);
        }
    }
    paths[k].push_back(s);
}
void dfs2(int s)
{
    for(int i=0;i<graph[s].size();i++)
    {
        if(vis[graph[s][i].ind]!=k+1 && vis[graph[s][i].ind]!=-1)
        {
            vis[graph[s][i].ind]=k+1;
            dfs2(graph[s][i].v);
        }
    }
    paths[k].push_back(s);
}
void dfs1(int s)
{
    for(int i=0;i<graph[s].size();i++)
    {
        if(vis[graph[s][i].ind]==0)
        {
            vis[graph[s][i].ind]=1;
            dfs1(graph[s][i].v);
        }
    }
    paths[k].push_back(s);
}
bool cmp(edge a,edge b)
{
    return a.t < b.t;
}
int bins(long long tmp)
{
    int le=0,ri=m-1,mid;
    while(le<=ri)
    {
        int mid=(le+ri)>>1;
        if(edges[mid].t==tmp)return mid;
        else if(edges[mid].t<tmp)le=mid+1;
        else ri=mid-1;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,j,b,e;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>edges[i].b>>edges[i].e;
        if(edges[i].b>edges[i].e)swap(edges[i].b,edges[i].e);
        edges[i].t=edges[i].b*maxN+edges[i].e;
    }
    sort(edges,edges+m,cmp);
    for(i=0;i<m;i++)
    {
        graph[edges[i].b].push_back(node(edges[i].e,i));
        graph[edges[i].e].push_back(node(edges[i].b,i));
    }
    int cnto=0;
    for(i=1;i<=n;i++)
    {
        if(graph[i].size()%2==1)cnto++;
    }
    if(cnto==0)
    {
        dfs1(1);
        cout<<1<<endl;
        cout<<paths[k].size()<<" ";
        for(i=0;i<paths[k].size()-1;i++)
        {
            cout<<paths[k][i]<<" ";
        }cout<<paths[k][paths[k].size()-1]<<endl;
    }
    else if(cnto==2)
    {
        for(i=1;i<=n;i++)
        {
            if(graph[i].size()%2==1){
                dfs1(i);
                break;
            }
        }
        cout<<1<<endl;
        cout<<paths[k].size()<<" ";
        for(i=0;i<paths[k].size()-1;i++)
        {
            cout<<paths[k][i]<<" ";
        }cout<<paths[k][paths[k].size()-1]<<endl;
    }
    else {
        for(i=1;i<=n;i++)
        {
            if(graph[i].size()%2==1 && used[i]==0)
            {
                fl=0;
                if(cnto>2)
                {
                    dfs(i,i);
                    for(j=0;j<paths[k].size()-1;j++)
                    {
                        long long v1=min(paths[k][j],paths[k][j+1]),v2=max(paths[k][j],paths[k][j+1]);
                        long long tmp=v1*maxN+v2;
                        int ind=bins(tmp);
                        vis[ind]=-1;
                    }
                }
                else if(cnto==2)dfs2(i);
                cnto-=2;
                used[i]=1;
                k++;
            }
        }
        cout<<k<<endl;
        for(i=0;i<k;i++)
        {
            cout<<paths[i].size()<<" ";
            for(j=0;j<paths[i].size()-1;j++)
            {
                cout<<paths[i][j]<<" ";
            }cout<<paths[i][paths[i].size()-1]<<endl;
        }
    }
}
/**
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
-----------
5 7
1 4
2 4
1 2
3 4
2 3
4 5
2 5
*/
