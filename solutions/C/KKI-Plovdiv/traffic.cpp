#include<iostream>
#include<queue>
#include<vector>
using namespace std;
char mas[640][640];
int used[640][640];
bool inqueue[640][640];
queue<pair<int,int> > q;
  int m,n;
int path(int x,int y)
{
    int result=100000001;
    pair<int,int> p;
    p.first=x;
    p.second=y;
    q.push(p);
    used[x][y]=0;
    inqueue[x][y]=true;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        inqueue[x][y]=true;

        if(x==m-1||x==0||y==n-1||y==0)
        {
            if(used[x][y]<result)result=used[x][y];
            continue;
        }

         //x+1 y
        if(mas[x+1][y]+used[x][y]<used[x+1][y]&&mas[x+1][y]!='*')
        {

            used[x+1][y]=mas[x+1][y]+used[x][y];
            if(inqueue[x+1][y]==false)
            {
                pair<int,int> p1;
                p1.first=x+1;
                p1.second=y;
                q.push(p1);
            }
        }


          //x-1 y
        if(mas[x-1][y]+used[x][y]<used[x-1][y]&&mas[x-1][y]!='*')
        {

            used[x-1][y]=mas[x-1][y]+used[x][y];
            if(inqueue[x-1][y]==false)
            {
                pair<int,int> p1;
                p1.first=x-1;
                p1.second=y;
                q.push(p1);
            }
        }


           //x y+1
        if(mas[x][y+1]+used[x][y]<used[x][y+1]&&mas[x][y+1]!='*')
        {

            used[x][y+1]=mas[x][y+1]+used[x][y];
            if(inqueue[x][y+1]==false)
            {
                pair<int,int> p1;
                p1.first=x;
                p1.second=y+1;
                q.push(p1);
            }
        }


           //x y-1
        if(mas[x][y-1]+used[x][y]<used[x][y-1]&&mas[x][y-1]!='*')
        {

            used[x][y-1]=mas[x][y-1]+used[x][y];
            if(inqueue[x][y-1]==false)
            {
                pair<int,int> p1;
                p1.first=x;
                p1.second=y-1;
                q.push(p1);
            }
        }

    }
        return result;
}
int main()
{
    int x,y;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        cin>>mas[i][j];
    }
     for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        used[i][j]=10000001;
    }
     for(int i=0;i<m;i++)
     for(int j=0;j<n;j++)
    {
        if(mas[i][j]>='A'&&mas[i][j]<='Z')mas[i][j]=mas[i][j]-'A'+1;
        if(mas[i][j]=='#'){x=i;y=j;}
    }
    for(int i=0;i<m;i++)
     for(int j=0;j<n;j++)
    {
        inqueue[i][j]=false;
    }
    cout<<path(x,y)<<endl;
    return 0;
}
