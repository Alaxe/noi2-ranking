#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> v[1024];
int used[1024],p[1024];
int n,k,br;
void read()
{
    int i,j,x,y;
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
void BFS(int beg)
{
    queue <int> q;
    int sz,i,nb,w;
    q.push(beg);
    used[beg]=1;
    p[beg]=0;
    while(!q.empty())
    {
        w=q.front();
        q.pop();
        sz=v[w].size();


        for(i=0;i<sz;i++)
        {

            nb=v[w][i];
            if(!used[nb])
            {
                used[nb]=used[w]+1;
                p[nb]=w;
                cout<<nb;
                q.push(nb);
                br++;
            }
        }
    }
}
void DFS(int i)
{
    used[i]=1;
    int sz=v[i].size();
    for(int j=0;j<sz;j++)
    {
        int nb=v[i][j];
        if(!used[nb])
        {
            DFS(nb);
        }
    }
}
void print(int s)
{
    if(p[s]!=0)
    {
        print(p[s]);
    }
    cout<<s<<' ';
}
int main()
{
    read();
 //   init();
    DFS(1);
    cout<<endl;
    cout<<br<<endl;
    return 0;
}
/*
8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3
*/
