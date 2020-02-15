#include<iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector <int> graph[MAXN];

bool used[MAXN];
int cnt[MAXN], depth[MAXN];

set <pair <int, int>> bad;

void DFSArt(int x, int last, int level)
{
    used[x] = true;
    depth[x] = level;

    for(int y: graph[x])
    {
        if(y==last) continue;

        if(used[y]==false)
        {
            DFSArt(y, x, level+1);
            cnt[x] += cnt[y];
        }
        else
        {
            if(depth[y]<depth[x]) cnt[x]++;
            else cnt[x]--;
        }
    }

    if(cnt[x]==0)
    {
        bad.insert({x, last});
        bad.insert({last, x});
    }
}

long long compSize = 0;
void DFS(int x)
{
    compSize++;
    used[x] = true;

    for(int y: graph[x])
    {
        if(used[y]==false && bad.count({x, y})==false)
        {
            DFS(y);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long answer = 0;

    cin >> n >> m;
    for(int i = 0;i<m;i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFSArt(1, -1, 1);
    memset(used, false, sizeof(used));

    for(int x = 1;x<=n;x++)
    {
        if(used[x]==false)
        {
            compSize = 0;
            DFS(x);

            answer += (compSize*(compSize-1))/2;
        }
    }

    cout << answer << '\n';
}
/*
5 5
1 2
2 3
3 1
2 4
2 5
*/
