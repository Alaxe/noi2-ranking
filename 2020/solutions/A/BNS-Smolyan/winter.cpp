#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector <int> graph[MAXN];

void read_input()
{
    scanf("%d %d", &n, &m);

    int v, w;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &v, &w);
        graph[v].push_back(w);
        graph[w].push_back(v);
    }
}

bool used[MAXN];
stack <int> st;
map < pair<int, int>, bool> us;

void dfs(int v)
{
    used[v] = true;
    for(auto x : graph[v])
    {
        if(!used[x])
        {
            us[{v, x}] = true;
            dfs(x);
        }
    }
    st.push(v);
}

bool vis[MAXN];
int br = 0;

void dfs2(int v)
{
    br++;
    vis[v] = true;
    for(auto x : graph[v])
    {
        if(!vis[x] && !us[{v, x}])
        {
            dfs2(x);
        }
    }
}

void solve()
{
    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            dfs(i);
        }
    }
    long long ans = 0;
    while(!st.empty())
    {
        int temp = st.top(); st.pop();

        if(!vis[temp])
        {
            br = 0;
            dfs2(temp);
            ans += 1LL * br * (br - 1) / 2;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    read_input();
    solve();

    return 0;
}

/*
5 5
1 2
2 3
3 1
2 4
2 5
*/

/*
6 7
1 2
2 3
3 1
2 5
5 6
5 4
4 6
*/

/*
7 9
1 2
2 3
3 1
2 5
5 6
5 4
4 6
2 7
3 7
*/

/*
9 11
1 2
2 3
3 1
3 4
4 6
4 5
5 6
4 7
7 9
7 8
8 9
*/

/*
14 18
1 2
1 3
2 3
2 4
4 5
5 6
4 6
3 8
2 7
7 8
7 9
9 10
10 11
9 11
9 12
12 13
12 14
13 14
*/
