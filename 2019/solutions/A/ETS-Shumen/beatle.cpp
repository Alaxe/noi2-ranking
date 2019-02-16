#include<iostream>
using namespace std;
long long n;
long long a[10000][10000],b[10000];
int maxy;
void read()
{
    int i,j;
    int x,y,d,t;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y>>d;
        if(y>=maxy)
        {
            maxy=y;
        }
        for(j=x;j<=d;j++)
        {
            a[j][y]=1;
        }
    }
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>b[i];
    }
}
void solve()
{
    int i,j,t;
    for(i=1;i<=t;i++)
    {
        for(j=maxy;j>=)

        fall( b[i],maxy,)
        br++;
    }
}
void fall(int x,y,d)
{
    while(a[x][y]==0)
    {
        y--;
    }
    while(a[x][y]==1)
    {
        x--;
    }
}
int main
{
    return 0;
}
