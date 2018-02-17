#include<iostream>
using namespace std;

const long long INF=10000000;

int m, n, answer=INF, exit_x, exit_y;
char maze[124][124];
bool w[124][124];

void solve(int x, int y, int time, bool bomb)
{
    //cout<<x<<" "<<y<<" "<<time<<" "<<bomb<<endl;
    if(x==exit_x && y==exit_y)
    {
        if(time<answer) answer=time;
    }
    else
    {
        w[x][y]=true;

        //move right:
        if(y!=n-1 && !w[x][y+1])
        {
            if(maze[x][y+1]=='#')
            {
                if(bomb)
                {
                    solve(x, y+1, time+3, false);
                }
            }
            else
            {
                solve(x, y+1, time+1, bomb);
            }
        }

        //move left:

        if(y && !w[x][y-1])
        {
            if(maze[x][y-1]=='#')
            {
                if(bomb)
                {
                    solve(x, y-1, time+3, false);
                }
            }
            else
            {
                solve(x, y-1, time+1, bomb);
            }
        }

        // move down:
        if(x!=m-1 && !w[x+1][y])
        {
            if(maze[x+1][y]=='#')
            {
                if(bomb)
                {
                    solve(x+1, y, time+3, false);
                }

            }
            else
            {
                solve(x+1, y, time+1, bomb);
            }
        }

        // move up:
        if(x && !w[x-1][y])
        {
            if(maze[x-1][y]=='#')
            {
                if(bomb)
                {
                    solve(x-1, y, time+3, false);
                }
            }
            else
            {
                solve(x-1, y, time+1, bomb);
            }
        }

        w[x][y]=false;
    }

}

int main()
{
    cin>>m>>n;

    int start_x, start_y;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='B')
            {
                start_x=i;
                start_y=j;
            }
            else if(maze[i][j]=='E')
            {
                exit_x=i;
                exit_y=j;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            w[i][j]=false;
        }
    }

    solve(start_x, start_y, 0, true);

    if(answer==INF) answer= -1;

    cout<<answer<<endl;

    return 0;
}
