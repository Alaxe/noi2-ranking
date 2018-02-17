#include<bits/stdc++.h>
using namespace std;
int m[2][128][128],bx,by,ex,ey,A,B;
char c[128][128]; bool f;
int min(int a,int b)
{
    if(a>b){f=1;return b;}
    return a;
}
void rec(int x,int y)
{
    if(x>0)
    {f=0;
        if(c[x-1][y]=='#')
        {
            if(x>1&&c[x-2][y]!='#')
            {
                if(m[1][x-2][y]==-1){f=1;m[1][x-2][y]=m[1][x][y]+4;}
                else m[1][x-2][y]=min(m[1][x-2][y],m[1][x][y]+4);
                if(f) rec(x-2,y);
            }
        }
        else{if(m[0][x][y]!=-1)
        {
            if(m[0][x-1][y]==-1){f=1;m[0][x-1][y]=m[0][x][y]+1;}
            else m[0][x-1][y]=min(m[0][x-1][y],m[0][x][y]+1);
        }
        if(m[1][x][y]!=-1)
        {
            if(m[1][x-1][y]==-1){f=1;m[1][x-1][y]=m[1][x][y]+1;}
            else m[1][x-1][y]=min(m[1][x-1][y],m[1][x][y]+1);
        }if(f) rec(x-1,y);}

    }
    if(y>0)
    {f=0;
        if(c[x][y-1]=='#')
        {
            if(y>1&&c[x][y-2]!='#')
            {
                if(m[1][x][y-2]==-1){f=1;m[1][x][y-2]=m[1][x][y]+4;}
                else m[1][x][y-2]=min(m[1][x][y-2],m[1][x][y]+4);
                if(f) rec(x,y-2);
            }
        }
        else{if(m[0][x][y]!=-1)
        {
            if(m[0][x][y-1]==-1){f=1;m[0][x][y-1]=m[0][x][y]+1;}
            else m[0][x][y-1]=min(m[0][x][y-1],m[0][x][y]+1);
        }
        if(m[1][x][y]!=-1)
        {
            if(m[1][x][y-1]==-1){f=1;m[1][x][y-1]=m[1][x][y]+1;}
            else m[1][x][y-1]=min(m[1][x][y-1],m[1][x][y]+1);
        }if(f) rec(x,y-1);}

    }
    if(x<A-1)
    {f=0;
        if(c[x+1][y]=='#')
        {
            if(x<B-2&&c[x+2][y]!='#')
            {
                if(m[1][x+2][y]==-1){f=1;m[1][x+2][y]=m[1][x][y]+4;}
                else m[1][x+2][y]=min(m[1][x+2][y],m[1][x][y]+4);
                if(f) rec(x+2,y);
            }
        }
        else{if(m[0][x][y]!=-1)
        {
            if(m[0][x+1][y]==-1){f=1;m[0][x+1][y]=m[0][x][y]+1;}
            else m[0][x+1][y]=min(m[0][x+1][y],m[0][x][y]+1);
        }
        if(m[1][x][y]!=-1)
        {
            if(m[1][x+1][y]==-1){f=1;m[1][x+1][y]=m[1][x][y]+1;}
            else m[1][x+1][y]=min(m[1][x+1][y],m[1][x][y]+1);
        }if(f) rec(x+1,y);}

    }
    if(y<B-1)
    {f=0;
        if(c[x][y+1]=='#')
        {
            if(y<B-2&&c[x][y+2]!='#')
            {
                if(m[1][x][y+2]==-1){f=1;m[1][x][y+2]=m[1][x][y]+4;}
                else m[1][x][y+2]=min(m[1][x][y+2],m[1][x][y]+4);
                if(f) rec(x,y+2);
            }
        }
        else{if(m[0][x][y]!=-1)
        {
            if(m[0][x][y+1]==-1){f=1;m[0][x][y+1]=m[0][x][y]+1;}
            else m[0][x][y+1]=min(m[0][x][y+1],m[0][x][y]+1);
        }
        if(m[1][x][y]!=-1)
        {
            if(m[1][x][y+1]==-1){f=1;m[1][x][y+1]=m[1][x][y]+1;}
            else m[1][x][y+1]=min(m[1][x][y+1],m[1][x][y]+1);
        }if(f) rec(x,y+1);}

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int a,b; A=a; B=b;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='B'){bx=i;by=j;}
            else if(c[i][j]=='E'){ex=i;ey=j;}
            m[0][i][j]=m[1][i][j]=-1;
        }
    }
    m[0][bx][by]=m[1][bx][by]=0;
    rec(bx,by);
    for(int i=0;i<0;i++);
    if(m[1][ex][ey]==-1&&m[0][ex][ey]==-1) cout<<-1<<endl;
    else
    {
        if(m[1][ex][ey]==-1) cout<<m[0][ex][ey]<<endl;
        else if(m[0][ex][ey]==-1) cout<<m[1][ex][ey]<<endl;
        else cout<<min(m[0][ex][ey],m[1][ex][ey])<<endl;
    }
    return 0;
}
/*

6 7
.....B.
.#####.
.#...#.
.#E#.#.
.###.#.
.......

*/
