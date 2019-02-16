#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define MaxNumberOfVertices 50005

vector<int> adj[MaxNumberOfVertices];
int numberOfVertices;

vector< vector<int> > paths;

struct Edge
{
    int a, b;
    bool operator< (const Edge& e) const
    {
        if (a == e.a)
        {
            return b < e.b;
        }
        return a < e.a;
    }
};

set<Edge> usedEdges;

void Input()
{
    int numberOfEdges;
    scanf("%d %d", &numberOfVertices, &numberOfEdges);

    int a, b;
    for (int i = 0; i < numberOfEdges; i++)
    {
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int GetAdj(int x)
{
    for (int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        Edge e = {min(x, y), max(x, y)};
        if (usedEdges.count(e) == 0)
        {
            return y;
        }
    }
    return -1;
}

void ConstructPath(int x)
{
    if (GetAdj(x) == -1) return;
    vector<int> vec;
    paths.push_back(vec);

    while (true)
    {
        paths.back().push_back(x);
        int y = GetAdj(x);
        if (y == -1) break;
        Edge e = {min(x, y), max(x, y)};
        usedEdges.insert(e);
        x = y;
    }
}

int main()
{
    Input();
    for (int i = 0; i < numberOfVertices; i++)
    {
        ConstructPath(i);
    }
    printf("%d\n", paths.size());
    for (int i = 0; i < paths.size(); i++)
    {
        printf("%d ", paths[i].size());
        for (int j = 0; j < paths[i].size() - 1; j++)
        {
            printf("%d ", paths[i][j] + 1);
        }
        printf("%d\n", paths[i].back());
    }

    return 0;
}
