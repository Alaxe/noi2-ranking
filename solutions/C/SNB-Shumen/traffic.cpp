#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
    long long ver,edge;
    bool operator<(const node &nd)const
    {
        return edge>nd.edge;
    }
};
long long N;
unsigned long long d[500000];
vector<node>v[500000];
vector<long long>out;
bool used[500000];
long long dijkstra(int i)
{
    priority_queue<node>q;
    memset(d,-1,sizeof(d));
    long long sz,j;
    node t,nb;
    t.ver=i;
    t.edge=0;
    d[i]=0;
    q.push(t);
    while(!q.empty())
    {
        t=q.top();
        q.pop();
        if(!used[t.ver])
        {
            used[t.ver]=true;
            sz=v[t.ver].size();
            for(j=0;j<sz;j++)
            {
                nb=v[t.ver][j];
                if(nb.edge+t.edge<d[nb.ver])
                {
                    d[nb.ver]=nb.edge+t.edge;
                    nb.edge+=t.edge;
                    q.push(nb);
                }
            }
        }
    }
}
int main()
{
    long long n,m,i,j,k,pos,sz,mr=9999999999999;
    char c;
    node nd;
    cin>>n>>m;
    N=n*m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            k=j+(i-1)*m;
            cin>>c;
            if(i==1||i==n||j==1||j==m)
            {
                if(c>='A'&&c<='Z')
                {
                    out.push_back(k);
                }
            }
            if(c!='*')
            {
                if(c=='#')pos=k;
                nd.ver=k-1;
                nd.edge=c-'A'+1;
                v[k].push_back(nd);
                nd.ver=k+1;
                v[k].push_back(nd);
                nd.ver=k-m;
                v[k].push_back(nd);
                nd.ver=k+m;
                v[k].push_back(nd);
            }

        }
    }
    dijkstra(pos);
    sz=out.size();
    for(i=0;i<sz;i++)
    {
        if(mr>d[out[i]])mr=d[out[i]];
    }
    cout<<mr<<endl;
    return 0;
}
/*
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD


*/
