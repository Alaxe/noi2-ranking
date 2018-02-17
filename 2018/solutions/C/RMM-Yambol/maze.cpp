# include <iostream>
# include <cstdio>
# include <climits>
# include <queue>
using namespace std;
int a[103][103];
int n,m,xs,ys,xe,ye;

int c[103][103][2];
priority_queue <pair <pair<int,bool>, pair<int,int> > > q;
void dijkstra()
{
    q.push(make_pair(make_pair(0,0),make_pair(xs,ys)));
    int tx,ty,d;
    bool fl;
    while(!q.empty())
    {
        d=-q.top().first.first;
        fl=q.top().first.second;
        tx=q.top().second.first;
        ty=q.top().second.second;
        q.pop();
      //cout<<tx<<" "<<ty<<" "<<d<<" "<<fl<<endl;
        if(c[tx][ty][fl]!=INT_MAX)continue;
       // if(fl&&a[tx][ty])continue;
      // if(a[tx][ty]){d+=2;fl=1;}
        c[tx][ty][fl]=d;
      //cout<<tx<<" "<<ty<<" "<<d<<" "<<fl<<endl;
        if(tx>1&&c[tx-1][ty][fl]==INT_MAX)
        {
           //cout<<1<<endl;
           if(!fl||!a[tx-1][ty])
           {
               if(a[tx-1][ty])
               q.push(make_pair(make_pair(-d-3,1),make_pair(tx-1,ty)));
               else
               q.push(make_pair(make_pair(-d-1,fl),make_pair(tx-1,ty)));
           }

        }
        if(tx<n&&c[tx+1][ty][fl]==INT_MAX)
        {

              if(!fl||!a[tx+1][ty])
           {
               if(a[tx+1][ty])
                q.push(make_pair(make_pair(-d-3,1),make_pair(tx+1,ty)));
               else
             q.push(make_pair(make_pair(-d-1,fl),make_pair(tx+1,ty)));
        }}
        if(ty>1&&c[tx][ty-1][fl]==INT_MAX)
        {

             if(!fl||!a[tx][ty-1])
           {// cout<<3<<endl;
               if(a[tx][ty-1])
                q.push(make_pair(make_pair(-d-3,1),make_pair(tx,ty-1)));
               else
             q.push(make_pair(make_pair(-d-1,fl),make_pair(tx,ty-1)));}
        }
        if(ty<m&&c[tx][ty+1][fl]==INT_MAX)
        {

             if(!fl||!a[tx][ty+1])
           { //cout<<4<<endl;
               if(a[tx][ty+1])
                q.push(make_pair(make_pair(-d-3,1),make_pair(tx,ty+1)));
               else
             q.push(make_pair(make_pair(-d-1,fl),make_pair(tx,ty+1)));}

    }
    }
}
int main()
{

    scanf("%d%d",&n,&m);
    char ch;
    int i,j,kx,ky,i1,j1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            c[i][j][0]=INT_MAX;
            c[i][j][1]=INT_MAX;
            cin>>ch;
            if(ch=='B'){xs=i;ys=j;a[i][j]=0;}
            if(ch=='E'){xe=i;ye=j;a[i][j]=0;}
            if(ch=='#'){a[i][j]=1;}
            if(ch=='.'){a[i][j]=0;}
        }
    }
 //  cout<<xs<<" "<<ys<<endl;
    dijkstra();
    i=min(c[xe][ye][1],c[xe][ye][0]);
    if(i==INT_MAX){printf("-1\n");return 0;}
    printf("%d\n",i);

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
