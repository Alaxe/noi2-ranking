#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> A[100005];
bool used[100005];
int path[100005];
set <int> cycle;

void solve(int curr, int idx)
{
    //cout << "curr " << curr << '\n';
    path[idx] = curr;
    used[curr] = true;

    /*cout << "neighbours:\n";
    for (int i = 0; i < A[curr].size(); ++i)
    {
        cout << A[curr][i] << ' ';
    }
    cout << '\n';*/
    for (int i = 0; i < A[curr].size(); ++i)
    {
        //cout << curr << ' ' << i << "-> " << A[curr][i] << '\n';
        if (!used[A[curr][i]])
        {
            //cout << "not used\n";
            if (cycle.find(A[curr][i]) == cycle.end())
            {
                solve(A[curr][i], idx + 1);
            }
        }
        else if (A[curr][i] != path[idx - 1])
        {
            //cin >> idx;
            //cout << "cycle: ";
            cycle.insert(A[curr][i]);
            //cout << A[curr][i] << ' ';
            for (int j = idx; path[j] != A[curr][i]; --j)
            {
                cycle.insert(path[j]);
                //cout << path[j] << ' ';
            }
            //cout << '\n';
        }
    }

    used[curr] = false;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        A[a].push_back(b);
        A[b].push_back(a);
    }

    /*for (int i = 1; i <= n; ++i)
    {
        cout << i << ": ";
        for (int j = 0; j < A[i].size(); ++j)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }*/

    solve(1, 0);

    /*cout << "cycle: ";
    for (set<int>::iterator it = cycle.begin(); it != cycle.end(); it++)
    {
        cout << (*it) << ' ';
    }
    cout << '\n';*/

    int res = 0;

    for (set<int>::iterator it = cycle.begin(); it != cycle.end(); it++)
    {
            for (int i = 0; i < A[(*it)].size(); ++i)
            {
                if (cycle.find(A[(*it)][i]) != cycle.end())
                {
                    res++;
                }
            }
    }

    cout << res / 2 << '\n';

    return 0;
}

