#include<iostream>
#include<queue>
using namespace std;
int time[640][640];
bool visited[640][640];
int ans=-1;
struct vertex
{
    int x,y,road;
    bool operator < (const vertex a)const
    {
        return this->road>a.road;
    }
};
priority_queue<vertex>doseg;
int main()
{
    cin.tie();
    int m=640,n=640;
    cin>>m>>n;
    char a;
    for(int y=0; y<m; y++)
    {
        for(int x=0; x<n; x++)
        {
            cin>>a;
            if(a=='#')
            {
                doseg.push({x,y,0});
                time[x][y]=-1;
            }
            else if(a=='*')
            {
                time[x][y]=-1;
            }
            else
            {
                time[x][y]=a+1-'A';
            }
        }
    }
    while(!doseg.empty() and ans==-1){
        int x=doseg.top().x;
        int y=doseg.top().y;
        int road=doseg.top().road;
        doseg.pop();
        if(!visited[x][y]){
            visited[x][y]=1;
            if(x==0 or x==n-1 or y==0 or y==m-1){
                    ans=road;
            }else{
                if(time[x+1][y]!=-1 and visited[x+1][y]==0){
                    doseg.push({x+1,y,road+time[x+1][y]});
                }
                if(time[x-1][y]!=-1 and visited[x-1][y]==0){
                    doseg.push({x-1,y,road+time[x-1][y]});
                }
                if(time[x][y+1]!=-1 and visited[x][y+1]==0){
                    doseg.push({x,y+1,road+time[x][y+1]});
                }
                if(time[x][y-1]!=-1 and visited[x][y-1]==0){
                    doseg.push({x,y-1,road+time[x][y-1]});
                }
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}

