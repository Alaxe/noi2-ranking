#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,ans,ti;
vector <int> v[11][100001];
//bool f[11][100001];
int p[11][100001];

queue<int> q;

int bfs(int vr1)
{
    int ret=0,i,vr2;
    p[ti][vr1]=1;
    q.push(vr1);
    while(!q.empty())
    {
        vr1=q.front();
        for(i=0; i<v[ti][vr1].size(); i++)
        {
            vr2=v[ti][vr1][i];
            if(p[ti][vr2]==0)
            {
                q.push(vr2);
                p[ti][vr2]=p[ti][vr1]+1;
            }
            else
            {
                if(p[ti][vr2]==p[ti][vr1])
                    if(ret==0) ret=3;
                if(p[ti][vr2]==p[ti][vr1]+1)
                    if(ret==0) ret=2;
            }
        }
        q.pop();
   }
    return ret;
}

int main()
{
    int i,t,j,vi;
    cin>>t;
    for(ti=1; ti<=t; ti++)
    {
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>vi;
            v[ti][i].push_back(vi);
            v[ti][vi].push_back(i);
        }
        for(i=1; i<=n; i++)
        {
            ans=max(ans,(int)v[ti][i].size());
            if(p[ti][i]==0)
            {
                ans=max(ans,bfs(i));
            }
        }
        cout<<ans<< endl;
    }
    return 0;
}
/*
2
4
4 1 2 3
5
4 1 2 3 4
*/
