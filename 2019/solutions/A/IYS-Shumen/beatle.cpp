#include <bits/stdc++.h>
using namespace std;
struct line
{
    pair<int,int>lft;
    pair<int,int>rgt;
};

vector<line>lines;
vector<int>v[131072];
int n,used[131072],t;

bool cmp(line a,line b)
{
    if(a.lft.second==b.lft.second)return a.lft.first<b.lft.first;
    return a.lft.second>b.lft.second;
}

void read()
{
    int i,x,y,l;
    line h;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x>>y>>l;
        h.lft= {x,y};
        h.rgt= {x+l,y};
        lines.push_back(h);
    }
    sort(lines.begin(),lines.end(),cmp);
}

bool Fine(line a,line b,line c)
{
    if(a.lft.second==b.lft.second)return false;
    if(b.rgt.first<a.lft.first)return false;
    if(b.lft.first>a.rgt.first)return false;
    if(b.rgt.first<=a.rgt.first&&b.lft.first>=a.lft.first)return false;
    ///b under a

    if(a.lft.second==c.lft.second)return true;
    if(c.rgt.first<a.lft.first)return true;
    if(c.lft.first>a.rgt.first)return true;
    if(c.rgt.first<=a.rgt.first&&c.lft.first>=a.lft.first)return true;
    ///c under a
    if(b.lft.first<a.lft.first&&b.rgt.first>=a.lft.first&&c.lft.first<a.lft.first&&c.rgt.first>=a.lft.first)return false;
    if(b.rgt.first>a.rgt.first&&b.lft.first<=a.rgt.first&&c.rgt.first>a.rgt.first&&c.lft.first<=a.rgt.first)return false;

    return true;

}

bool Problem(line a,line b)
{
    if(a.lft.second==b.lft.second)return false;
    if(b.rgt.first<a.lft.first)return false;
    if(b.lft.first>a.rgt.first)return false;
    if(b.rgt.first<=a.rgt.first&&b.lft.first>=a.lft.first)return false;
    return true;
}

void PreCompGraph()
{
    int i,j,l;
    bool lamp=false;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(!Problem(lines[i],lines[j]))continue;
            else if(v[i].size()==0)
            {
                v[i].push_back(j);
                continue;
            }
            else if(v[i].size()==2)
            {
                continue;
            }
            else
            {
                if(lines[i].lft.first>lines[v[i][0]].lft.first&&lines[i].rgt.first<lines[v[i][0]].rgt.first)continue;
                else
                {
                    if(Fine(lines[i],lines[j],lines[v[i][0]]))v[i].push_back(j);
                    else continue;
                }
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(v[i].size()==1&&(!(lines[i].lft.first>lines[v[i][0]].lft.first&&lines[i].rgt.first<lines[v[i][0]].rgt.first)))v[i].clear();
    }
}

int BFS(int i)
{
    memset(used,0,sizeof(used));
    used[i]=1;
    queue<int>q;
    int nb,sz,j;
    q.push(i);
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        sz=v[i].size();
        if(sz==0)return used[i];
        for(j=0; j<sz; j++)
        {
            nb=v[i][j];
            if(!used[nb])
            {
                q.push(nb);
                used[nb]=used[i]+1;
            }
        }

    }
}

int FindIdx(int x)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(x>lines[i].lft.first&&x<=lines[i].rgt.first)return i;
    }
    return -1;
}

void solve(int x)
{
    int f=FindIdx(x+1);
    if(f==-1)cout<<"0";
    else
    cout<<BFS(f);
    if(t>0)cout<<" ";
}

void Queries()
{
    int a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        solve(a);
    }
    cout<<endl;
}

int main()
{
    read();
    PreCompGraph();
    Queries();
    return 0;
}
/*
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
