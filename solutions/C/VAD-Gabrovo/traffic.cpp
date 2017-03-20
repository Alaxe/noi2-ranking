#include <iostream>
#include <string>
#include <cctype>
#define MAXNM 768
using namespace std;

int n, m;
int pi, pj;
int a[MAXNM][MAXNM];
bool l=false;
bool visited [MAXNM][MAXNM];
int mintime;

void Find_Path (int x, int y, int time, bool vis[MAXNM][MAXNM])
{
    if (x==0 || y==0 || x==n-1 || y==m-1)
    {
        if (l==false)
        {
            mintime=time;
            l=true;
        }
        else
            mintime=min (mintime, time);
        return;
    }
    if (a[x-1][y]!=0 && vis[x-1][y]==false)
    {
        vis[x-1][y]=true;
        Find_Path (x-1, y, time+a[x-1][y], vis);
    }

    if (a[x+1][y]!=0 && vis[x+1][y]==false)
    {
        vis[x+1][y]=true;
        Find_Path (x+1, y, time+a[x+1][y], vis);
    }

    if (a[x][y-1]!=0 && vis[x][y-1]==false)
    {
        vis[x][y-1]=true;
        Find_Path (x, y-1, time+a[x][y-1], vis);
    }
    if (a[x][y+1]!=0 && vis[x][y+1]==false)
    {
        vis[x][y+1]=true;
        Find_Path (x, y+1, time+a[x][y+1], vis);
    }
}

void To_False ()
{
    for (int i=0; i<n; i++)
        for (int j=0; i<m; i++)
            visited[i][j]=false;
}

void Init ()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<s.size (); j++)
        {
            if (isalpha (s[j]))
                a[i][j]=(int)(s[j])-64;
            if (s[j]=='*')
                a[i][j]=0;
            if (s[j]=='#')
            {
                a[i][j]=0;
                pi=i;
                pj=j;
            }
        }
    }
}

int main ()
{
    Init ();
    visited [pi][pj]=true;
    Find_Path (pi, pj, 0, visited);
    cout<<mintime<<endl;
    return 0;
}
