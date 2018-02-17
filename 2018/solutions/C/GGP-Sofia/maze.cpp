#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 128
#define MAXM 128
#define INF 1000000003
using namespace std;
int n, m;
char t[MAXN][MAXM];
int end_x, end_y;
struct node
{
    int ver, edge;
    bool operator < (const node &p) const
    {
        return p.edge < edge;
    }
};
node make_node(int ver, int edge)
{
    node ans;
    ans.ver = ver;
    ans.edge = edge;
    return ans;
}
vector <node> v[MAXN*MAXM];
vector <node> starting[MAXN*MAXM];
priority_queue <node> q;
int d[MAXN*MAXM];
bool used[MAXN*MAXM];
void dejkstra(int start)
{
    for (int i = 1; i <= m * n; i++)
        d[i] = INF;
    d[start] = 0;
    q.push(make_node(start, 0));
    while (!q.empty())
    {
        node top = q.top();
        q.pop();
        if (!used[top.ver])
        {
            used[top.ver] = 1;
            int sz = v[top.ver].size();
            for (int i = 0; i < sz; i++)
            {
                    node curr = v[top.ver][i];
                    if (top.edge + curr.edge < d[curr.ver])
                    {
                        d[curr.ver] = top.edge + curr.edge;
                        curr.edge = d[curr.ver];
                        q.push(curr);
                    }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];
    int start_x, start_y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (t[i][j] == 'B')
            {
                start_x = i;
                start_y = j;
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (t[i][j] == 'E')
            {
                end_x = i;
                end_y = j;
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int idx = (i-1)*m+j;
            if (i >= 2 && t[i-1][j] != '#')
                starting[idx].push_back(make_node(idx-m, 1));
            if (i <= n-1 && t[i+1][j] != '#')
                starting[idx].push_back(make_node(idx+m, 1));
            if (j >= 2 && t[i][j-1] != '#')
                starting[idx].push_back(make_node(idx-1, 1));
            if (j <= m-1 && t[i][j+1] != '#')
                starting[idx].push_back(make_node(idx+1, 1));
        }
        int min_ans = INF;
        for (int k = 0; k <= n*m; k++)
                    v[k] = starting[k];
                    dejkstra((start_x-1)*m+start_y);
                    min_ans = min(min_ans, d[(end_x-1)*m+end_y]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (t[i][j] == '#')
            {

                for (int k = 0; k <= n*m; k++)
                    v[k] = starting[k];
                int idx = (i-1)*m+j;
                if (i >= 2 && t[i-1][j] != '#')
                {
                    v[idx].push_back(make_node(idx-m, 1));
                    v[idx-m].push_back(make_node(idx, 3));
                }
                if (i <= n-1 && t[i+1][j] != '#')
                {
                    v[idx].push_back(make_node(idx+m, 1));
                    v[idx+m].push_back(make_node(idx, 3));
                }
                if (j >= 2 && t[i][j-1] != '#')
                {
                    v[idx].push_back(make_node(idx-1, 1));
                    v[idx-1].push_back(make_node(idx, 3));
                }
                if (j <= m-1 && t[i][j+1] != '#')
                {
                    v[idx].push_back(make_node(idx+1, 1));
                    v[idx+1].push_back(make_node(idx, 3));
                }
                memset(used, 0, sizeof(used));
                dejkstra((start_x-1)*m+start_y);
                min_ans = min(min_ans, d[(end_x-1)*m+end_y]);
            }
            if (min_ans == INF) cout << -1 << endl;
                else cout << min_ans << endl;
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
