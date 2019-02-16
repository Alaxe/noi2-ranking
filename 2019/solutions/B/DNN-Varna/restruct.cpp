#include <bits/stdc++.h>
#define MAXN 5001
#define endl '\n'
using namespace std;
int n;
long long k;
vector <int> v[MAXN];

void input()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;

            v[y].push_back(i + 1);
        }
    }
}

bool used[MAXN];
int rank[MAXN];

void dfs(int temp)
{
    memset(used, 0, sizeof(used));
    memset(rank, 0, sizeof(rank));
    queue <int> q;
    q.push(temp);
    rank[temp] = 1;
    int idx;
    used[temp] = 1;


    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        idx = rank[curr];

        for (int i = 0; i < v[curr].size(); i++)
            if (!used[v[curr][i]])
            {
                rank[v[curr][i]] = idx + 1;
                used[v[curr][i]] = 1;
                q.push(v[curr][i]);
            }
    }

}

long long check(int root)
{
    dfs(root);

    long long curr = 0;

    for (int i = 1; i <= n; i++)
        curr += rank[i] * k;

    bool poss = 1;

    for (int i = 1; i <= n; i++)
        if (!used[i])
        {
            poss = 0;
            break;
        }

    if (poss)
        return curr;
    return -1;
}

void find()
{
    long long min1 = -1;

    for (int i = 1; i <= n; i++)
    {
        long long curr = check(i);

        if (curr != -1)
        {
            if (min1 == -1)
                min1 = curr;
            else
                min1 = min(min1, curr);
        }
    }

    cout << min1 << endl;
}

/**
5 100
3 2 3 4
2 1 5
4 1 2 4 5
3 2 3 1
2 4 2

5 100
2 2 3
2 3 4
2 4 5
2 5 1
2 1 2

*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    find();

    return 0;
}
