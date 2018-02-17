#include <bits/stdc++.h>
using namespace std;
const int inf=1000;
int n, m;
char m1[100][100];
int d[110][110][2];
int i1, j11, i2, j2;
queue <pair<int, int> > q;
int p[2][4]={{0, 0, -1, 1},
             {1, -1, 0, 0}};
bool check(int i, int j)
{
    if (i<0 || i>=n) return 0;
    if (j<0 || j>=n) return 0;
    return 1;
}
int ui, uj, vi, vj;
void dijkstra()
{
    d[i1][j11][0]=0;
    q.push(make_pair(i1, j11));
    while (!q.empty())
    {
        ui=q.front().first;
        uj=q.front().second;
        q.pop();
        for (int k=0; k<4; k++)
        {
            if (check(ui+p[0][k], uj+p[1][k])==0) continue;
            vi=ui+p[0][k];
            vj=uj+p[1][k];
           //cout<<vi<<" "<<vj<<endl;
            //if (vi==2 && vj==0) cout<<d[ui][uj][1]<<" apsbwfb\n";
            if (m1[vi][vj]=='#')
            {
               // if (d[ui][uj][1]==inf)
                //{
                    if (d[vi][vj][1]>d[ui][uj][0]+3)
                    {
                        d[vi][vj][1]=d[ui][uj][0]+3;
                       // cout<<d[vi][vj][1]<<" zdnhp\n";
                        q.push(make_pair(vi, vj));
                    }
                //}
            }
            else
            {
                if (d[vi][vj][1]>d[ui][uj][1]+1)
                {
                    d[vi][vj][1]=d[ui][uj][1]+1;
                    q.push(make_pair(vi, vj));
                }
                if (d[vi][vj][0]>d[ui][uj][0]+1)
                {
                    d[vi][vj][0]=d[ui][uj][0]+1;
                   // cout<<d[vi][vj][0]<<endl;
                    q.push(make_pair(vi, vj));
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    int i2=-1, j2=-1;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>>m1[i][j];
            if (m1[i][j]=='B') {i1=i; j11=j;}
            if (m1[i][j]=='E') {i2=i; j2=j;}
        }
    }
    if (i2==-1 && j2==-1) cout<<"-1\n";
    else{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            d[i][j][0]=inf;
            d[i][j][1]=inf;
        }
    }
    dijkstra();
   /* for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<d[i][j][1]<<" ";
        }
        cout<<endl;
    }*/

    if (d[i2][j2][0]!=inf || d[i2][j2][1]!=inf) cout<<min(d[i2][j2][0], d[i2][j2][1])<<endl;
    else cout<<"-1\n";}
    return 0;
}/*
6 7
.....B.
.#####.
.#...#.
.#E#.#.
.###.#.
.......

5 5
...B.
#####
#####
...E.
.....*/
