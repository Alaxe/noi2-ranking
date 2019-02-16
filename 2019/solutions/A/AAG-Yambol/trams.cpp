#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cstdlib>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 5e4 + 5;

int n, m;
vector <int> nb[N];
int deg[N];

int paths;
vector <int> ans[N];
int ptr[N];

map <pair <int, int>, bool> seen;
multiset <pair <int, int> > ms;

void DFS(int v, int path)
{
    ans[path].pb(v);
    bool done = false;
    for(; ptr[v] < nb[v].size();)
    {
        if(done)
            break;
        ptr[v]++;
        if(seen[{v, nb[v][ptr[v] - 1]}])
            continue;
        done = true;

        int u = nb[v][ptr[v] - 1];
        ms.erase({deg[u], u});
        deg[u]--;
        ms.insert({deg[u], u});

        ms.erase({deg[v], v});
        deg[v]--;
        ms.insert({deg[v], v});

        seen[{v, nb[v][ptr[v] - 1]}] = true;
        seen[{nb[v][ptr[v] - 1], v}] = true;
        DFS(nb[v][ptr[v] - 1], path);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

  //  srand(313);

    int u, v;

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        nb[u].pb(v);
        nb[v].pb(u);

        deg[u]++;
        deg[v]++;
    }

/*    for(int i = 1; i <= n; i++)
        random_shuffle(nb[i].begin(), nb[i].end()); */

    for(int i = 1; i <= n; i++)
        ms.insert({deg[i], i});
    while(!ms.empty())
    {
        pair <int, int> t = *(ms.begin());
        if(t.first == 0)
        {
            ms.erase(t);
            continue;
        }

        paths++;
        DFS(t.second, paths);
    }

    cout << paths << endl;
    for(int i = 1; i <= paths; i++)
    {
        cout << ans[i].size() << " ";
        for(auto x: ans[i])
            cout << x << " ";
        cout << endl;
    }

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
