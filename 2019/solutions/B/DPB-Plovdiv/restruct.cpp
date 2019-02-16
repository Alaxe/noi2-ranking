#include<iostream>
#include<list>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define IT list<int>::iterator
#define MAXN 5000
#define MIN(a,b) (a>b)?b:a
list<int> G[MAXN+1];
queue<int> q;
vector<int> v,tmp;
bool used[MAXN+1];
int N,K;
IT it;
int BFS(int i)
{
     int n,t,j,level;
     q.push(i);
     used[i]=true;
     for(level=0;!q.empty();level++)
     {
         n=q.size();
         v.push_back(n);
         for(j=0;j<n;j++)
         {
             t=q.front();
             q.pop();
             for(it=G[t].begin();it!=G[t].end();it++)
                 if(!used[*it])q.push(*it),used[*it]=true;
         }
     }
     return level;
}
int main()
{
    int k,i,j,p;
    int result=MAXN+2,r=0,bfs;
    cin>>N>>K;
    v.resize(N+1);
    for(i=1;i<=N;i++)
    {
        used[i]=false;
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>p;
            G[p].push_back(i);
        }
    }
    for(i=1;i<=N;i++)
    {
        bfs=BFS(i);
        if(bfs<result)
        {
            result=bfs;
            tmp=v;
            v.clear();
        }
        memset(used,false,N+1);
        q=queue<int>();
    }
    for(i=tmp.size()-1;i>=0;i--)
        r+=tmp[i]*(tmp.size()-i);
    cout<<r*K<<endl;
    return 0;
}
