#include <bits/stdc++.h>
using namespace std;

/**
7 8
1 2
2 3
1 3
2 4
2 5
5 6
5 7
6 7
**/

int main()
{
    bool flag;
    int ans = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin>>n;
    cin>>m;
    vector <vector <int>> v = {};
    vector <pair <int, int>> edges;
    v.resize(n);
    for (int i = 0; i != n; i ++)
    {
        v[i].resize(n);
    }

    for (int i = 0; i != n; i ++)
    {
        for (int j = 0; j != n; j ++)
        {
            v[i][j] = m + 1;
        }
    }

    for (int i = 0; i != m; i ++)
    {
        cin>>a>>b;
        v[a - 1][b - 1] = 1;
        v[b - 1][a - 1] = 1;
        edges.push_back({a - 1, b - 1});
    }

   // for (int z = 0; z != m; z ++)
   // {
        pair <int, int> edge = edges[0];
        v[edge.first][edge.second] = m + 1;
        v[edge.second][edge.first] = m + 1;
        for (int i = 0; i != n; i ++)
        {
            for (int k = 0; k != n; k ++)
            {
                for (int j = 0; j != n; j ++)
                {
                    if (v[j][k] > v[i][j] + v[i][k]/** and !(j == edge.first and k == edge.second) and !(k == edge.first and j == edge.second)**/)
                    {
                        v[j][k] = v[i][j] + v[i][k];
                    }
                }
            }
        }
        for (int i = 0; i != n; i ++)
        {
            v[i][i] = m + 1;
        }
        cout<<edge.first<<" "<<edge.second<<endl;
        for (int i = 0; i != n; i ++)
        {
            for (int j = 0; j != n; j ++)
            {
                if (v[i][j] == m + 1 and i != j)
                {
                    flag = true;
                }
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }!(j == edge.first and k == edge.second)
        if (flag)
        {
            flag = false;
        }
        else
        {
            ans ++;
        }
        cout<<endl;
        v[edge.first][edge.second] = 1;
  //  }





    return 0;
}
