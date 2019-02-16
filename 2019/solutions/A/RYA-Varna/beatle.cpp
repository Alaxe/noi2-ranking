#include <bits/stdc++.h>
using namespace std;
const int maxN=1e5+1;
int n,t;
struct line{
    int x,y,d;
    line(){}
    line(int x,int y,int d): x(x), y(y), d(d) {}
}lines[maxN];
bool cmp1(line a,line b)
{
    if(a.y!=b.y)return a.y < b.y;
    return a.x < b.x;
}
vector<int> graph[maxN];
int segt[4*maxN],lazy[4*maxN];
void updateLazy(int nd,int le,int ri)
{
    if(lazy[nd]!=0)
    {
        segt[nd]=lazy[nd];
        if(le!=ri)
        {
            lazy[2*nd]=lazy[nd];
            lazy[2*nd+1]=lazy[nd];
        }
        lazy[nd]=0;
    }
}
int query(int nd,int le,int ri,int x)
{
    updateLazy(nd,le,ri);
    if(x<le || x>ri)return 0;
    if(le==ri)
    {
        return segt[nd];
    }
    int mid=(le+ri)>>1;
    return query(2*nd,le,mid,x)+query(2*nd+1,mid+1,ri,x);
}
void update(int nd,int le,int ri,int p,int q,int val)
{
    updateLazy(nd,le,ri);
    if(q<le || p>ri)return;
    if(p<=le && ri<=q)
    {
        segt[nd]=val;
        if(le!=ri)
        {
            lazy[2*nd]=val;
            lazy[2*nd+1]=val;
        }
        return;
    }
    int mid=(le+ri)>>1;
    update(2*nd,le,mid,p,q,val);
    update(2*nd+1,mid+1,ri,p,q,val);
}
int ans[maxN],used[maxN];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    int tmp;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        for(int i=0;i<graph[tmp].size();i++)
        {
            if(!used[graph[tmp][i]])
            {
                used[graph[tmp][i]]=used[tmp]+1;
                q.push(graph[tmp][i]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,j,x,y,d;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>lines[i].x>>lines[i].y>>lines[i].d;
    }
    lines[n].x=0;
    lines[n].y=0;
    lines[n++].d=1e5;
    sort(lines,lines+n,cmp1);
    int m=1e5;
    for(i=1;i<n;i++)
    {
        int le=query(1,0,m,lines[i].x-1);
        int ri=query(1,0,m,lines[i].x+lines[i].d);
        graph[le].push_back(i);
        if(le!=ri)graph[ri].push_back(i);
        update(1,0,m,lines[i].x,lines[i].x+lines[i].d-1,i);
    }
    cin>>t;
    bfs(0);
    for(i=0;i<t-1;i++)
    {
        cin>>x;
        int tmp=query(1,0,m,x);
        cout<<used[tmp]<<" ";
    }
    cin>>x;
    int tmp=query(1,0,m,x);
    cout<<used[tmp]<<endl;
}
/**
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
