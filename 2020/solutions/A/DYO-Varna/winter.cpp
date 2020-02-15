#include <iostream>
#include <vector>
#include <cstdlib>
#define endl '\n'
using namespace std;

#define NMax 1000
#define MMax 10000

struct edge
{
    int v1, v2;
    edge(){};
    edge(int a, int b)
    {
        v1 = a, v2 = b;
    }
} edges[MMax + 2];

int n, m, leint[NMax + 2], riint[NMax + 2], depth[NMax + 2];
int from, to, cnt;
vector<int> nb[NMax + 2];
bool used[NMax + 2];
int ans;

void dfs_par(int v)
{
    used[v] = 1;

    leint[v] = ++ cnt;
    for(int i = 0; i < nb[v].size(); i ++)
    {
        if(used[nb[v][i]] == 1) continue;

        depth[nb[v][i]] = depth[v] + 1;
        dfs_par(nb[v][i]);
    }
    riint[v] = ++ cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i ++)
    {
        cin >> from >> to;
        nb[from].push_back(to);
        nb[to].push_back(from);
        edges[i] = edge(from, to);
    }

    dfs_par(1);



    for(int v1 = 1; v1 <= n; v1 ++)
        for(int v2 = v1 + 1; v2 <= n ; v2 ++)
        {
            for(int e = 0; e < m; e ++)
            {
                if(depth[edges[e].v1] > depth[edges[e].v2]) swap(edges[e].v1, edges[e].v2);
                if(depth[edges[e].v1] - depth[edges[e].v2] == -1) continue;

                if(leint[edges[e].v1] <= leint[v1] && riint[edges[e].v1] >= riint[v1] &&
                   leint[edges[e].v1] <= leint[v2] && riint[edges[e].v1] >= riint[v2] &&
                   leint[edges[e].v2] >= leint[v1] && riint[edges[e].v2] <= riint[v1] &&
                   leint[edges[e].v2] >= leint[v2] && riint[edges[e].v2] <= riint[v2])
                {
                    ans ++;
                    break;
                }
            }
        }
    cout << ans << endl;

    return 0;
}
/**
8 9
1 2
1 5
2 8
3 8
4 7
5 8
6 7
6 8
7 8
*/
