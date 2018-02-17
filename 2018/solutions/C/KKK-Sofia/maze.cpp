#include<iostream>
#include<queue>
struct path
{
    int x,y,len;
    bool bombed;
    bool operator <(path compared)const
    {
        return this->len>compared.len;
    }
};
int m,n;
int bx,by,ex,ey;
int maze[101][101];
bool visited[101][101][2];
std::priority_queue<path>current;
int main()
{
    std::cin.tie(nullptr);
    std::cout.sync_with_stdio(false);
    std::cin>>m>>n;
    char a;
    for(int y=0; y<m; y++)
    {
        for(int x=0; x<n; x++)
        {
            std::cin>>a;
            switch(a)
            {
            case '.':
                maze[x][y]=0;
                break;
            case '#':
                maze[x][y]=1;
                break;
            case 'B':
                maze[x][y]=1;
                bx=x;
                by=y;
                break;
            case 'E':
                maze[x][y]=1;
                ex=x;
                ey=y;
                break;
            }
        }
    }
    current.push({bx,by,0,0});
    int ans=-1;
    while(!current.empty())
    {
        path cPath=current.top();
        //std::cout<<cPath.x<<" "<<cPath.y<<" "<<cPath.len<<" "<<cPath.bombed<<std::endl;
        current.pop();
        if(visited[cPath.x][cPath.y][cPath.bombed]){
            continue;
        }
        visited[cPath.x][cPath.y][cPath.bombed]=1;
        if(cPath.x==ex && cPath.y==ey)
        {
            ans=cPath.len;
            break;
        }
        if(cPath.x>0 && !visited[cPath.x-1][cPath.y][cPath.bombed])
        {
            if(maze[cPath.x-1][cPath.y]!=0)
            {
                current.push({cPath.x-1,cPath.y,cPath.len+1,cPath.bombed});
            }
            if(maze[cPath.x-1][cPath.y]==0 && !cPath.bombed)
            {
                current.push({cPath.x-1,cPath.y,cPath.len+3,1});
            }
        }
        if(cPath.y>0 && !visited[cPath.x][cPath.y-1][cPath.bombed])
        {
            if(maze[cPath.x][cPath.y-1]!=0)
            {
                current.push({cPath.x,cPath.y-1,cPath.len+1,cPath.bombed});
            }
            if(maze[cPath.x][cPath.y-1]==0 && !cPath.bombed)
            {
                current.push({cPath.x,cPath.y-1,cPath.len+3,1});
            }
        }
        if(cPath.x<n-1 && !visited[cPath.x+1][cPath.y][cPath.bombed])
        {
            if(maze[cPath.x+1][cPath.y]!=0)
            {
                current.push({cPath.x+1,cPath.y,cPath.len+1,cPath.bombed});
            }
            if(maze[cPath.x-1][cPath.y]==0 && !cPath.bombed)
            {
                current.push({cPath.x+1,cPath.y,cPath.len+3,1});
            }
        }
        if(cPath.y<m-1 && !visited[cPath.x][cPath.y+1][cPath.bombed])
        {
            if(maze[cPath.x][cPath.y+1]!=0)
            {
                current.push({cPath.x,cPath.y+1,cPath.len+1,cPath.bombed});
            }
            if(maze[cPath.x][cPath.y+1]==0 && !cPath.bombed)
            {
                current.push({cPath.x,cPath.y+1,cPath.len+3,1});
            }
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
