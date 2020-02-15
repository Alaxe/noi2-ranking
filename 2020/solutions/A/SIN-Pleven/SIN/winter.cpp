#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#include<stack>
#include<map>
using namespace std;

int n, m;
int connected1[100001];

int root[100001];

vector<pair<int, int> > pathmem;
vector<vector<int> > G;

bool obhoden[100001];

int findParent(int x)
{
    if (root[x] == x) return x;
    else return findParent(root[x]);
}

int main ()
{
    scanf("%d%d", &n, &m);
    G.resize(n+1);

    for (int i=1; i<=n; i++)
    {
        root[i] = i;
    }

    for (int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        pathmem.emplace_back(a, b);
        connected1[a]++;
        connected1[b]++;
    }
    for (int i=0; i<m; i++)
    {
        if (connected1[pathmem[i].first] == 1 || connected1[pathmem[i].second] == 1) continue;
        G[pathmem[i].first].push_back(pathmem[i].second);
        G[pathmem[i].second].push_back(pathmem[i].first);
    }

    int start = 1;
    while (G[start].size() == 0) start++;
    obhoden[start] = true;
    stack<int> dfs, curpath;
    dfs.push(start);
    curpath.push(start);

    while (!dfs.empty())
    {
        int top = dfs.top();
        if (top != curpath.top()) curpath.push(top);
        for (int i=0; i<G[top].size(); i++)
        {
            if (!obhoden[G[top][i]])
            {
                dfs.push(G[top][i]);
                obhoden[G[top][i]] = true;
            }
            else
            {
                stack<int> disp = curpath; //G[top][i] zatvarq cikula
                while (!disp.empty())
                {
                    if (disp.top() == G[top][i]) break;
                    disp.pop();
                }
                if (!disp.empty())
                {
                    disp = curpath;
                    int toppr = findParent(G[top][i]);
                    while (disp.top() != G[top][i])
                    {
                        root[ findParent(disp.top()) ] = toppr;
                        disp.pop();
                    }
                }
            }
        }
        if (top == dfs.top())
        {
            dfs.pop();
            curpath.pop();
        }
    }
    map<int, int> last;
    for (int i=1; i<=n; i++)
    {
        root[i] = findParent(i);
        last[root[i]]++;
    }
    int ans = 0;
    for (map<int, int>::iterator it = last.begin(); it != last.end(); it++)
    {
        ans += (it->second)*(it->second-1)/2;
    }
    cout<<ans<<endl;
}
/**
1 2
2 3
3 6
3 7
4 6
5 6
5 10
6 7
6 8
7 8
7 9
9 10

28
*/
