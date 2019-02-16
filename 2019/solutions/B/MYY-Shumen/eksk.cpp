#include<bits/stdc++.h>
using namespace std;
int AnswerProblem;
int answer1,answer2;
int n;
int A,B;
vector<int>graph[1<<20];
void read(void)
{
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin>>A>>B;
}
bool used1[1<<20],used2[1<<20];
int last1[1<<20];
void bfs1(int start)
{
    queue<int>q;q.push(start);used1[start]=true;
    while (!q.empty())
    {
        int now=q.front();q.pop();
        for (int j=0;j<(int)(graph[now].size());j++)
        {
            int nextt=graph[now][j];

            if (nextt==B){last1[nextt]=now;continue;}
            if (!used1[nextt])
            {
                last1[nextt]=now;
                used1[nextt]=true;
                q.push(nextt);
            }
        }
    }
}
void bfs2(int start)
{
    queue<int>q;q.push(start);used2[start]=true;
    while (!q.empty())
    {
        int now=q.front();q.pop();
        for (int j=0;j<(int)(graph[now].size());j++)
        {
            int nextt=graph[now][j];
            if (nextt==A)continue;
            if (!used2[nextt])
            {
                used2[nextt]=true;
                q.push(nextt);
            }
        }
    }
}
bool used[1<<20];
int badbad=-1;
int cntt;
void dfs(int start)
{
    cntt++;
    used[start]=true;
    for (int j=0;j<(int)(graph[start].size());j++)
    {
        if (graph[start][j]==badbad)
        {
            continue;
        }
        if (!used[graph[start][j]])
        {
            dfs(graph[start][j]);
        }
    }
}
void solve(void)
{
    bfs1(A);
    bfs2(B);

    for (int i=1;i<=n;i++)
    {
        if (used1[i])
        if (!used2[i])
        {
            answer1++;
        }
        if (!used1[i])
        if (used2[i])
        {
            answer2++;
        }
    }
    vector<int>normalpath;
    normalpath.push_back(B);
    int now=B;
    while (now!=A)
    {
        now=last1[now];
        normalpath.push_back(now);
    }
    reverse(normalpath.begin(),normalpath.end());
   // cout<<answer1<<" "<<n-answer1<<endl;
   // cout<<answer2<<" "<<n-answer2<<endl;
    AnswerProblem=min(answer1,n-answer1);
    AnswerProblem=max(AnswerProblem,min(answer2,n-answer2));

    for (int i=1; i+1 <(int)(normalpath.size());i++)
    {
        int lastnow=normalpath[i-1];int nextnow=normalpath[i+1];
        int nownow=normalpath[i];
        for (int j=0;j<(int)(graph[nownow].size());j++)
        {
            if (graph[nownow][j]==nextnow)
            {
                continue;
            }
            if (graph[nownow][j]==lastnow)
            {
                continue;
            }
            badbad=normalpath[i];
            dfs(graph[nownow][j]);

        }
        cntt++;
        int hello1=answer1+cntt;
        int hello2=n-hello1;
       // cout<<hello1<<" "<<hello2<<endl;
        AnswerProblem=max(AnswerProblem,min(hello1,hello2));
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
