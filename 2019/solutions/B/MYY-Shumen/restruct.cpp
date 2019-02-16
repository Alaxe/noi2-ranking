#include<bits/stdc++.h>
using namespace std;
long long AnswerProblem=1LL<<60;
int n,k;
int aa[1<<13];
vector<int>bb[1<<13];

vector<int>graph[1<<13];
void read(void)
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>aa[i];
        for (int j=0;j<aa[i];j++)
        {
            int now;
            cin>>now;
            bb[i].push_back(now);
            graph[now].push_back(i);
        }
    }
}
int used[1<<13];int level[1<<13];
vector<int>newgraph[1<<13];
int cntel;
void dfs(int start)
{
    used[start]=true;
    cntel++;
    for (int j=0;j<(int)(graph[start].size());j++)
    {
        if (!used[graph[start][j]])
        {
            dfs(graph[start][j]);
            level[start]=max(level[start],level[graph[start][j]]);
        }
    }
    level[start]++;
}
void solve(void)
{
    for (int root=1;root<=n;root++)
    {
        memset(level,0,sizeof(level));
        memset(used,0,sizeof(used));
        queue<int>q;q.push(root);used[root]=-1;
        stack<int>backlist;backlist.push(root);
        int cntel=1;
        while (!q.empty())
        {
            int now=q.front();q.pop();
            for (int j=0;j<(int)(graph[now].size());j++)
            {
                int nextt=graph[now][j];
                if (!used[nextt])
                {
                    cntel++;
                    used[nextt]=now;
                    backlist.push(nextt);
                    q.push(nextt);
                }
            }
        }

        long long sumsum=0;
        while (!backlist.empty())
        {
            int nowlist=backlist.top();backlist.pop();
          //  cout<<nowlist<<" ";
            level[nowlist]=(level[nowlist]+k);
            sumsum+=level[nowlist];
            //cout<<level[nowlist]<<endl;
            if (used[nowlist]>0)
            level[used[nowlist]]=(level[used[nowlist]]+level[nowlist]);
        }
        //cout<<endl;
       // cout<<root<<" "<<sumsum<<endl;
        AnswerProblem=min(AnswerProblem,sumsum);
    }
}
void print(void)
{
    cout<<AnswerProblem<<endl;
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
