#include<iostream>
#include<queue>

using namespace std;

#define MAXI 100000000000

string s[101];
long long n,m;
bool used[101][101][3];

struct data
{
    long long x,y,b,dist;
};

struct cmp
{
    bool operator()(data d1,data d2)
    {
        return d1.dist>d2.dist;
    }
};

long long dijkstra(long long x,long long y,bool b)
{
    priority_queue<data,vector<data>,cmp> q;
    data d1,d2;
    long long dist;
    
    d1.x=x;
    d1.y=y;
    d1.b=b;
    d1.dist=0;
    
    q.push(d1);
    
    while(!q.empty())
    {
        d1=q.top();
        q.pop();
        x=d1.x;
        y=d1.y;
        b=d1.b;
        dist=d1.dist;
        if(used[x][y][b])continue;
        if(s[x][y]=='E')return dist;
        used[x][y][b]=1;
        
        d2=d1;
        
        if(b)
        {
            if(x>=1)
            {
                d2.x-=1;
                d2.b=0;
                d2.dist+=3;
                
                q.push(d2);
                
                d2.x+=1;
                d2.b=b;
                d2.dist-=3;
            }
            if(x<n-1)
            {
                d2.x+=1;
                d2.b=0;
                d2.dist+=3;
                
                q.push(d2);
                
                d2.x-=1;
                d2.b=b;
                d2.dist-=3;
            }
            if(y>=1)
            {
                d2.y-=1;
                d2.b=0;
                d2.dist+=3;
                
                q.push(d2);
                
                d2.y+=1;
                d2.b=b;
                d2.dist-=3;
            }
            if(y<m-1)
            {
                d2.y+=1;
                d2.b=0;
                d2.dist+=3;
                
                q.push(d2);
                
                d2.y-=1;
                d2.b=b;
                d2.dist-=3; 
            }
        }
        
        if(x>=1 && s[x-1][y]!='#')
        {
            d2.x-=1;
            d2.dist+=1;
            
            q.push(d2);
            
            d2.x+=1;
            d2.dist-=1;
        }
        if(x<n-1 && s[x+1][y]!='#')
        {
            d2.x+=1;
            d2.dist+=1;
            
            q.push(d2);
            
            d2.x-=1;
            d2.dist-=1;
        }
        if(y>=1 && s[x][y-1]!='#')
        {
            d2.y-=1;
            d2.dist+=1;
            
            q.push(d2);
            
            d2.y+=1;
            d2.dist-=1;
        }
        if(y<m-1 && s[x][y+1]!='#')
        {
            d2.y+=1;
            d2.dist+=1;
            
            q.push(d2);
            
            d2.y-=1;
            d2.dist-=1;
        }
    }
    
    return -1;
}


int main()
{
    long long i,j;
    
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='B')
            {

                cout<<dijkstra(i,j,1)<<endl;
                
                return 0;
            }
        }
    }
    
    cout<<"-1"<<endl;
    
    return 0;
}
/*
8 5
....E
.##.#
..#..
#.#..
..#..
.#...
##...
B#...
*/