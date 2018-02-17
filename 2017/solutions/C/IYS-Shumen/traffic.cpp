#include<iostream>
#include<string>
#include<queue>
#include<cstring>
# define INF 12000000
using namespace std;
struct direction
{
    int x,y;
};
struct node
{
    direction ver;
    long long edge;
    bool operator<(const node&nd)const
    {
        return edge>nd.edge;
    }
};
direction dir[4]={{1,0},{0,1},{-1,0},{0,-1}};
string s[1024];
int a[650][650],X,Y;
long long used[650][650];
unsigned d[650][650];
void dijkstra(direction s)
{
    priority_queue<node>q;
    memset(d,-1,sizeof(d));
    int i,j;
    node p;
    d[s.x][s.y]=0;
    p.ver=s;
    p.edge=0;
    q.push(p);
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        if(d[p.ver.x][p.ver.y]>=p.edge)
        {
            if(!used[p.ver.x][p.ver.y])
            {
                used[p.ver.x][p.ver.y]=1;
                for(i=0;i<4;i++)
                {
                    node nb;
                    nb.ver.x=p.ver.x+dir[i].x;
                    nb.ver.y=p.ver.y+dir[i].y;
                    if(a[nb.ver.x][nb.ver.y]>=0)
                    {
                        
                    nb.edge=a[nb.ver.x][nb.ver.y];
                    if(d[nb.ver.x][nb.ver.y]>d[p.ver.x][p.ver.y]+nb.edge)
                    {
                        d[nb.ver.x][nb.ver.y]=d[p.ver.x][p.ver.y]+nb.edge;
                        nb.edge=d[nb.ver.x][nb.ver.y];
                        q.push(nb);
                    }
                }
                else if(a[nb.ver.x][nb.ver.y]==-2) {X=p.ver.x;Y=p.ver.y;return ;}
                }
            }
        }
    }
}
int main()
{
    int n,m,i,j,x1,y1;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='*')a[i+1][j+1]=-1;
            else
            if(s[i][j]=='#'){x1=i+1;y1=j+1;}
            else a[i+1][j+1]=s[i][j]-'A'+1;
        }
    }
    for(i=0;i<=n;i++)a[i][0]=a[i][m+1]=-2;
    for(j=0;j<=m;j++)a[0][j]=a[n+1][j]=-2;
    direction dd;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            d[i][j]=INF;
        }
    }
    dd.x=x1;
    dd.y=y1;
    dijkstra(dd);
    cout<<d[X][Y]<<endl;
    
    return 0;
}