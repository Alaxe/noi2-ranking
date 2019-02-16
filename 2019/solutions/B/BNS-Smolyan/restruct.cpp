#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e3 * 5 + 5;
const int INF = 1e9;

int n, k;
vector <int> graph[MAXN];
int t_graph[MAXN][MAXN];

void read_input()
{
    scanf("%d %d", &n, &k);

    int z, w;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &z);
        for(int j = 0; j < z; j++)
        {
            scanf("%d", &w);
            graph[i].push_back(w);
        }
    }
}

int cnt;
int child[MAXN], prt[MAXN];
bool visited[MAXN];

int tempAns = 0;

int dfs(int v)
{
    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        if(t_graph[v][i] > 0)
        {
            ans += dfs(i);
        }
    }
    tempAns += ans + 1;
    return ans + 1;
}

bool testDfs(int v)
{
    visited[v] = true;
    for(int i = 1; i <= n; i++)
    {
        if(t_graph[v][i] > 0 && !visited[i])
        {
            testDfs(i);
        }
    }
}

int answer = INF;
bool marked[MAXN];

void calc()
{
    int root = 0;
    for(int i = 1; i <= n; i++)
    {
        if(prt[i] == 0)
        {
            if(root != 0) return;
            root = i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(marked[i] == false) return;
    }
    if(root == 0) return;
    for(int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    testDfs(root);
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false) return;
    }

    dfs(root);
    /*if(answer > tempAns)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                printf("%d ", t_graph[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }*/
    answer = min(answer, tempAns);
    tempAns = 0;
}

void brute_force(int v)
{
    if(v == n + 1)
    {
        if(cnt == n - 1)
        {
            calc();
        }
        return;
    }

    int z = graph[v].size();

    for(int i = 0; i < z; i++)
    {
        int parent = graph[v][i];

        prt[v]++;
        child[parent]++;
        t_graph[parent][v]++;
        marked[v] = true;
        marked[parent] = true;
        cnt++;

        brute_force(v + 1);

        prt[v]--;
        child[parent]--;
        marked[v] = false;
        marked[parent] = false;
        t_graph[parent][v]--;
        cnt--;
    }
    brute_force(v + 1);
}

void solve()
{
    brute_force(1);

    printf("%lld\n", 1LL * k * answer);
}

int main()
{
    read_input();
    solve();

    return 0;
}
