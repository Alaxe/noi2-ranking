#include <bits/stdc++.h>
using namespace std;

int M, N;
char lab[120][120];
int dist[120][120];
char prev[120][120];
pair<int, int> start, e;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

void readInput()
{
    int i, j;

    cin >> M >> N;
    for (i = 0; i < M; i++)
    {
        cin >> lab[i];
        for (j = 0; j < N; j++)
        {
            if (lab[i][j] == 'B') start = make_pair(i, j);
            else if (lab[i][j] == 'E') e = make_pair(i, j);
        }
    }
}

bool isOut(const pair<int, int> &x)
{
    if (x.first < 0) return true;
    if (x.first >= M) return true;
    if (x.second < 0) return true;
    if (x.second >= N) return true;
    return false;
}

void initDistances()
{
    pair<int, int> cur, next;
    queue<pair<int, int> > q;
    int i;
    char ch;

    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (i = 0; i < 4; i++)
        {
            next.first = cur.first + dr[i];
            next.second = cur.second + dc[i];
            if (!isOut(next))
            {
                if (dist[next.first][next.second] == -1)
                {
                    dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
                    switch (i)
                    {
                        case 0: ch = 'R'; break;
                        case 1: ch = 'D'; break;
                        case 2: ch = 'L'; break;
                        case 3: ch = 'U'; break;
                    }
                    prev[next.first][next.second] = ch;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dist, -1, sizeof(dist));

    readInput();

    prev[start.first][start.second] = 'S';

    initDistances();

    int ans, br = 0;
    pair<int, int> cur;
    char ch;

    ans = dist[e.first][e.second];

    cur = e;

    while (prev[cur.first][cur.second] != 'S')
    {
        ch = prev[cur.first][cur.second];
        if (lab[cur.first][cur.second] == '#') br++;
        switch (ch)
        {
            case 'U':
                cur.first = cur.first + dr[1];
                cur.second = cur.second + dc[1];
                break;
            case 'D':
                cur.first = cur.first + dr[3];
                cur.second = cur.second + dc[3];
                break;
            case 'L':
                cur.first = cur.first + dr[0];
                cur.second = cur.second + dc[0];
                break;
            case 'R':
                cur.first = cur.first + dr[2];
                cur.second = cur.second + dc[2];
                break;
        }
    }

    if (br == 0) cout << ans << '\n';
    else if (br > 1) cout << -1 << '\n';
    else
    {
        ans = ans + 2;
        cout << ans << '\n';
    }

    return 0;
}
