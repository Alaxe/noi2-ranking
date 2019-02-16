#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 200000;
int n;
int v1, v2;
vector<int> con[MAXN+100];
bool used[MAXN+100];
int path[MAXN+100][2], maxd[MAXN+100];
int ans;

void input()
{
    int u, v;
    cin>>n;
    n--;
    for (int i=0; i<n; i++)
    {
        cin>>u>>v;
        u--; v--;
        con[u].push_back(v);
        con[v].push_back(u);
    }
    cin>>v1>>v2;
    v1--; v2--;
}

void output()
{
    cout<<ans<<endl;
}

int dfs(int curr)
{
    //cerr<<curr<<" - ";
    used[curr] = 1;
    int temp;
    if (curr==v2) return curr;
    for (int i=0; i<con[curr].size(); i++)
    {
        if (used[con[curr][i]]) continue;
        temp = dfs(con[curr][i]);
        if (temp!=-1) 
        {
            path[curr][0] = temp;
            path[temp][1] = curr;
            return curr;
        }
    }
    return -1;
}

void zeroing()
{
    for (int i=0; i<n; i++)
    {
        used[i] = 0;
    }
}

int count_children(int curr, int cnt)
{
    int c=0, c2=cnt;
    used[curr] = 1;
    for (int i=0; i<con[curr].size(); i++)
    {
        if (!used[con[curr][i]]) 
        {
            c = count_children(con[curr][i], cnt+1);
            c2 = max(c2, c);
        }
    }
    return c2;
}

void solve()
{
    int curr;
    int c1, c2;
    int t1=1, t2=1;
    for (int i=0; i<=n; i++)
    {
        path[i][0] = -1;
        path[i][1] = -1;
    }
    dfs(v1);
    zeroing();
    /*for (int i=0; i<=n; i++)
    {
        cerr<<i<<" - "<<path[i][0]<<' '<<path[i][1]<<endl;
    }*/
    curr = path[v1][0];
    used[v1] = 1;
    used[curr] = 1;
    while(curr!=v2)
    {
        used[path[curr][0]] = 1;
        maxd[curr] = count_children(curr, 0);
        //cerr<<curr<<' '<<maxd[curr]<<endl;
        curr = path[curr][0];
    }
    c1 = count_children(v1, 0);
    c2 = count_children(v2, 0);
    //cerr<<c2.first<<' '<<c2.second<<endl;
    while(path[v1][0]!=v2 && v1!=path[v2][1])
    {
        if (c2>c1)
        {
            v1 = path[v1][0];
            if (c1 < maxd[v1]+t1) 
            {
                c1 = maxd[v1]+t1;
                t1++;
            }
        }
        else
        {
            v2 = path[v2][1];
            if (c2 < maxd[v2]+t2) 
            {
                c2 = maxd[v2]+t2;
                t2++;
            }
        }
    }
    //cerr<<v1<<' '<<v2<<endl;
    ans = min(c1, c2)+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    output();
    return 0;
}

/*
6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

16
1 2
2 3
3 4
3 5
5 6
6 7
6 8
5 16
5 12
12 10
10 9
10 11
15 13
12 14
1 15 
3 14
*/