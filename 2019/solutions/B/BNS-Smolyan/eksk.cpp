#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 * 2 + 5;

int n;
int a, b;
vector <int> graph[MAXN];
int parent[MAXN];
int child_count[MAXN];
int depth[MAXN];

void read_input()
{
    scanf("%d", &n);

    int v, w;
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &v, &w);
        graph[v].push_back(w);
        graph[w].push_back(v);
    }
    scanf("%d %d", &a, &b);
}

int dfs(int v, int p, int dpth)
{
    int v_cnt = 0;
    parent[v] = p;
    depth[v] = dpth;

    int z = graph[v].size();
    for(int i = 0; i < z; i++)
    {
        int to = graph[v][i];
        if(to == p) continue;
        int c_cnt = dfs(to, v, dpth + 1);

        v_cnt = max(v_cnt, c_cnt);
    }
    return (child_count[v] = v_cnt) + 1;
}

/*void dfs2(int v)
{
    int z = graph[v].size();
    printf("%d %d\n", v, child_count[v]);
    for(int i = 0; i < z; i++)
    {
        int to = graph[v][i];

        if(to == parent[v]) continue;
        dfs2(to);
    }
}*/

void make_tree()
{
    dfs(b, b, 1);
    //dfs2(b);
}

int t_a, cnt_a, prev_a, max_a;

int calc_a()
{
    int ans = 0;

    int z = graph[t_a].size();
    for(int i = 0; i < z; i++)
    {
        int to = graph[t_a][i];

        if(to == prev_a || to == parent[t_a]) continue;

        ans = max(ans, child_count[to] + 1);
    }
    ans += cnt_a;
    max_a = max(max_a, ans);
    return max_a;
}

int answer = 0;

void dfs_sol(int v, int used)
{
    int z = graph[v].size();

    int ans = 0;

    for(int i = 0; i < z; i++)
    {
        int to = graph[v][i];
        if(to == used || to == parent[v]) continue;

        ans = max(ans, child_count[to] + 1);
    }

    ans += depth[v];

    int second = calc_a();
    int temp = min(second, ans);
    answer = max(answer, temp);

    //printf("%d %d %d\n", v, ans, second);

    prev_a = t_a; t_a = v; cnt_a++;

    if(v == b) return;
    dfs_sol(parent[v], v);
}

void solve()
{
    t_a = a; cnt_a = 1; prev_a = a; max_a = 0;
    dfs_sol(parent[a], a);

    printf("%d\n", answer);
}

int main()
{
    read_input();
    make_tree();
    solve();

    return 0;
}

/*
8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8
*/

/*
6
1 2
2 3
3 4
4 5
5 6
4 5
*/

/*
6
1 2
2 3
3 4
4 5
5 6
1 6
*/

/*
10
1 2
6 2
2 3
3 4
4 7
7 5
8 5
5 9
9 10
10 7
*/

/*
14
1 2
6 2
2 3
3 4
4 7
7 5
8 5
5 9
9 10
6 11
6 12
6 13
6 14
11 7
*/

/*
18
8 2
1 2
2 12
12 6
6 7
4 3
11 3
6 9
9 10
9 5
3 6
1 13
13 14
14 15
11 16
16 17
18 15
*/
