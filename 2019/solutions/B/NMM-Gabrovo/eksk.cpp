#include<bits/stdc++.h>
using namespace std;

const int MAXN=200002;

int n, a, b;
vector<int> adj[MAXN];
pair<int, int> A[MAXN], B[MAXN];
bool beenThere[MAXN];

void dfsA(int u, int c)
{
    beenThere[u]=true;
    A[u].first=c;
    for(int v=0; v<adj[u].size(); ++v)
    {
        if(adj[u][v]!=b && !beenThere[adj[u][v]])
            dfsA(adj[u][v], c+1);
    }
}

void dfsB(int u, int c)
{
    beenThere[u]=true;
    B[u].first=c;
    for(int v=0; v<adj[u].size(); ++v)
    {
        if(adj[u][v]!=a && !beenThere[adj[u][v]])
            dfsB(adj[u][v], c+1);
    }
}

bool works;
stack<int> path;

void dfs(int u, int dist)
{
    beenThere[u]=true;
    if(u==dist)
    {
        works=true;
    }
    else
    {
        if(!works)
            for(int v=0; v<adj[u].size(); ++v)
            {
                if(!beenThere[adj[u][v]])
                    dfs(adj[u][v], dist);
            }
    }
    if(!works) beenThere[u]=false;
}

bool checkThesePaths(int distA, int distB)
{
    for(int i=0; i<n; ++i) beenThere[i]=false;

    works=false;
    int start=a, dist=distA;
    dfs(start, dist);

    works=false;
    start=b; dist=distB;
    dfs(start, dist);

    return works;
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    int u, v;
    for(int i=1; i<n; ++i)
    {
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin>>a>>b;
    a--; b--;

    for(int i=0; i<n; ++i)
        A[i].first=B[i].first=(-1);

    dfsA(a, 0);

    for(int i=0; i<n; ++i) beenThere[i]=false;
    dfsB(b, 0);

    for(int i=0; i<n; ++i)
        A[i].second=B[i].second=i;

    sort(A, A+n);
    sort(B, B+n);

    /*for(int i=0; i<n; ++i)
        cout<<A[i].first<<" "<<A[i].second<<" "
        <<B[i].first<<" "<<B[i].second<<endl;*/

    int j, current=n-1;
    for(int i=n-1; i>=0; --i)
    {
        j=current;
        while(B[j].first>A[i].first && j>=0)
            j--;

        while(B[j].first==A[i].first)
        {
            bool sol=checkThesePaths(A[i].second, B[j].second);
            if(sol)
            {
                int ans=A[i].first;
                cout<<ans+1<<endl;
                exit(0);
            }
            j--;
        }
    }

    return 0;
}

/*
12
9 8
8 6
6 10
10 7
7 12
6 1
1 2
2 3
1 11
11 4
4 5
11 12

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

6
1 2
2 3
3 4
4 5
5 6
4 5

15
2 5
5 4
4 3
3 1
3 9
9 10
5 6
6 7
6 8
8 12
8 11
11 15
1 13
10 14
5 9
*/
