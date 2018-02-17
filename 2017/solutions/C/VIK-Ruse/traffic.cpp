#include<iostream>
#include<queue>
//#include<time.h>

using namespace std;

#define MAX_DIS 10649600

struct for_queue
{
    int xk,yk,pr;
};

struct cmp
{
    bool operator()(const for_queue a,const for_queue b)
    {
        return a.pr>b.pr;
    }
};

int v1[641][641][4],v2[641][641][4],brv[641][641],n,m;
string s[641];
bool used[641][641];
int dis[641][641];

int dijkstra(int x,int y)
{
    priority_queue <for_queue,vector<for_queue>,cmp> q;
    for_queue p,p2;
    int i,t;
    
    p.xk=x;
    p.yk=y;
    p.pr=0;
    
    q.push(p);
    
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        
        //cout<<p.xk<<" "<<p.yk<<endl; 
        
        if(p.xk==0 || p.xk==n-1 || p.yk==0 || p.yk==m-1)
        {
            return p.pr;
        }
        
        if(used[p.xk][p.yk]==1)continue;
        
        used[p.xk][p.yk]=1;
        
        for(i=0;i<brv[p.xk][p.yk];i++)
        {   
            p2.xk=v1[p.xk][p.yk][i];
            p2.yk=v2[p.xk][p.yk][i];
            if(used[p2.xk][p2.yk]==0)
            {
                t=(int)s[p2.xk][p2.yk]-'A'+1;
                //cout<<t<<endl;
                if(p.pr+t<dis[p2.xk][p2.yk])
                {
                    dis[p2.xk][p2.yk]=p.pr+t;
                    p2.pr=dis[p2.xk][p2.yk];
                    q.push(p2);
                }
            }
        }
    }
    
    return 0;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //time_t t;
    
    //t=clock();
    
    int i,j,x,y;
    
    cin>>n>>m;
    
    for(i=0;i<n;i++)cin>>s[i];
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                x=i;
                y=j;
            }
            if(s[i][j]!='*')
            {
                dis[i][j]=MAX_DIS;
                if(i>0 && s[i-1][j]!='*')
                {
                    v1[i][j][brv[i][j]]=i-1;
                    v2[i][j][brv[i][j]]=j;
                    brv[i][j]++;
                }
                if(i<n-1 && s[i+1][j]!='*')
                {   
                    v1[i][j][brv[i][j]]=i+1;
                    v2[i][j][brv[i][j]]=j;
                    brv[i][j]++;
                }
                if(j>0 && s[i][j-1]!='*')
                {
                    v1[i][j][brv[i][j]]=i;
                    v2[i][j][brv[i][j]]=j-1;
                    brv[i][j]++;
                }
                if(j<m-1 && s[i][j+1]!='*')
                {
                    v1[i][j][brv[i][j]]=i;
                    v2[i][j][brv[i][j]]=j+1;
                    brv[i][j]++;
                }
            }
        }
    }
    
    //cout<<x<<" "<<y<<endl; 
    
    cout<<dijkstra(x,y)<<endl;
    
    //cout<<(double)(clock()-t)/CLOCKS_PER_SEC<<endl;
    
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