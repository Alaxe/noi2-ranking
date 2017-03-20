#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,sx,sy,matr[641][641],spc[641][641];
bool used[641][641];
char ch;
long long mn=1<<31-1;
struct str
{
    str() {}
    str(int a,int b,int d)
    {
        x=a;
        y=b;
        sp=d;
    }
    int x,y, sp;
};
priority_queue <str> q;
bool operator < (str a, str b)
{
    return a.sp>b.sp;
}
int main()
{
    cin>>n>>m;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>ch;
            if(ch=='*')continue;
            if(ch=='#')
            {
                sx=i;
                sy=j;
            }
            else matr[i][j]=ch-'A'+1;
        }
    }
    q.push(str(sx-1,sy,0));
    q.push(str(sx,sy-1,0));
    q.push(str(sx+1,sy,0));
    q.push(str(sx,sy+1,0));
    used[sx][sy]=true;
    spc[sx][sy]=0;
    while(!q.empty())
    {
        str tp=q.top();
       // cout<<tp.x<<" "<<tp.y<<"\n";
        q.pop();
        if(tp.x<0 || tp.y<0 || tp.x==n || tp.y==m)continue;
        if(matr[tp.x][tp.y]==0)continue;
        if(spc[tp.x][tp.y])tp.sp=min(tp.sp+matr[tp.x][tp.y],spc[tp.x][tp.y]);
        else tp.sp+=matr[tp.x][tp.y];
        spc[tp.x][tp.y]=tp.sp;
        if((tp.x==0 || tp.y==0 || tp.x==n-1 || tp.y==m-1) && mn>spc[tp.x][tp.y])mn=spc[tp.x][tp.y];
        //if(tp.sp>100)cout<<tp.x<<" "<<tp.y<<" "<<tp.sp<<"\n";
        if(!used[tp.x][tp.y])
        {
        q.push(str(tp.x-1,tp.y,tp.sp));
        q.push(str(tp.x+1,tp.y,tp.sp));
        q.push(str(tp.x,tp.y+1,tp.sp));
        q.push(str(tp.x,tp.y-1,tp.sp));
        }
        used[tp.x][tp.y]=true;
    }
    cout<<mn<<"\n";
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
ASGSHKAGSHAS
ASHKSKAJHSJK
*/
