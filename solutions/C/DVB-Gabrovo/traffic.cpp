#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

const int INF = 1 << 30;

const int MAXN = 750;
const int MAXM = 750;

int dir[4][2] = {{+1, 0}, {-1, 0}, {0, -1}, {0, +1}};

int a[MAXN][MAXM], n, m;
int start_x, start_y;

int vis[MAXN][MAXM];

void Init()
{
    char x;

    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 1; j <= m; ++ j)
        {
            cin >> x;
            if (x == '#')
            {
                a[i][j] = 0;
                start_x = i;
                start_y = j;
            }
            else if (x == '*')
            {
                a[i][j] = -1;
            }
            else
            {
                a[i][j] = (int)(x - 'A' + 1);
            }
        }
    }
}

int BFS()
{
    int answer = INF;

    queue< pair<int, int> > q;
    q.push(make_pair(start_x, start_y));
    vis[start_x][start_y] = 0;

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        int x = u.first, y = u.second;

        if (x == 1 or x == n or y == 1 or y == m)
        {
            answer  = min(answer, vis[x][y]);
        }

        q.pop();

        for (int i = 0; i < 4; ++ i)
        {
            int new_x = x + dir[i][0];
            int new_y = y + dir[i][1];

            if (new_x >= 1 and new_x <= n and new_y >= 1 and new_y <= m)
            {
                if (a[new_x][new_y] > 0 and vis[new_x][new_y] == 0)
                {
                    vis[new_x][new_y] = a[new_x][new_y] + vis[x][y];
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
    }
    return answer;
}

int main()
{
    Init();
    cout << BFS() << endl;
    return 0;
}
