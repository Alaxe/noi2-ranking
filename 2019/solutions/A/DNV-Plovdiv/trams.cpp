#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int pops,cnt,m,n,maxx,minn,a,b;
vector<int>v[MAXN];
map<pair<int,int>,bool> mp;
queue<int> q;
void dfs(int x)
{
    //cout<<x<<endl;
    q.push(x);
    for(int i=0;i<v[x].size();i++)
    {
        maxx=max(v[x][i],x);
        minn=min(v[x][i],x);
        if(mp[make_pair(minn,maxx)]==1)
        {
            mp[make_pair(minn,maxx)]=0;
            pops++;
            dfs(v[x][i]);
            return;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        minn=min(a,b);
        maxx=max(a,b);
        mp[make_pair(minn,maxx)]=1;
    }
    //for(int i=1;i<=n;i++)
    //sort(v[i].begin(),v[i].end());
    bool lamp=0;
    while(pops!=m)
    {
        bool flag=0;
        if(lamp==0)
        for(int i=1;i<=n;i++)
        {
            if(v[i].size()%2==1)
            {
                dfs(i);
                flag=1;
                if(q.size()>1)
                {
                    cout<<q.size();
                    while(q.size()!=0)
                    {
                        cout<<" "<<q.front();
                        q.pop();
                    }
                    cout<<endl;
                }
                else
                while(q.size()!=0)q.pop();
            }
        }
        if(flag==0)
        {
            lamp=1;
            for(int i=1;i<=n;i++)
            {
                dfs(i);
                if(q.size()>1)
                {

                    cout<<q.size();
                    while(q.size()!=0)
                    {
                        cout<<" "<<q.front();
                        q.pop();
                    }
                    cout<<endl;

                }
                else
                while(q.size()!=0)q.pop();
            }
        }
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
