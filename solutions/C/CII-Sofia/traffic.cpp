#include<iostream>
#include<queue>
#include<cmath>
#include<cstdio>
#define MAX 100000
using namespace std;
//vector< pair<int,int> >ss[409600];
int n,m;
char table1[642][642];
int ot[642][642],px,py;
/**int dist[642][642];
int rek(int x,int y)
{
    if(ot[x-1][y]>0 && ot[x-1][y]!=MAX)
        {
            if(dist[x][y]+ot[x-1][y]<dist[x-1][y])
                dist[x-1][y]=dist[x][y]+ot[x-1][y];
            res(x-1,y);
        }if(ot[x+1][y]>0 && ot[x+1][y]!=MAX)
        {
            if(dist[x][y]+ot[x+1][y]<dist[x+1][y])
                dist[x+1][y]=dist[x][y]+ot[x+1][y];
            res(x+1,y);
        }if(ot[x][y-1]>0 && ot[x][y-1]!=MAX)
        {
            if(dist[x][y]+ot[x][y-1]<dist[x][y-1])
                dist[x][y-1]=dist[x][y]+ot[x][y-1];
            res(x,y-1);
        }if(ot[x][y-1]>0 && ot[x][y+1]!=MAX)
        {
            if(dist[x][y]+ot[x][y+1]<dist[x][y+1])
                dist[x][y+1]=dist[x][y]+ot[x][y+1];
            res(x,y+1);
        }
}*/
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
   /* for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dist[i][j]=MAX;*/
    for(int i=1; i<=n; i++)
    {
        string a;
        cin>>a;
        for(int j=0; j<a.size(); j++)
        {
            if(a[j]>='A' && a[j]<='Z')
                ot[i][j+1]=a[j]-'A'+1;
            if(a[j]=='*')
                ot[i][j+1]=MAX;
            if(a[j]=='#')
            {
                ot[i][j+1]=0;
                px=i;
                py=j;
            }
        }
    }
    cout<<"0\n";
    return 0;
}
/**
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
