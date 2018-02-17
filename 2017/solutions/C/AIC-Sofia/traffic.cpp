#include <iostream>
#include <queue>

using namespace std;

const int max_val = 641*641*28;

bool matrix [1024][1024];
int map [1024][1024];

int optimal = -1;

int n, m;

int dx [] = {0, 0, 1, -1};
int dy [] = {1, -1, 0, 0};
/*
void dfs (int x, int y, int time)
{
    //cout << time << endl;
    //cout << x << " " << y << " " << time << endl;
    //cout << map [y][x] << " " << matrix [y][x] << "\n";
    if (map [y][x] == 0 and time != 0)
        return;
    if (time > optimal and optimal != -1)
        return;
    if (x == 0 or y == 0 or x == m - 1 or y == n - 1)
    {
        if (optimal == -1)
            optimal = time;
        else
            optimal = min (optimal, time);
        return;
    }
    if (x < 0 or x >= m or y < 0 or y >= n)
    {
        return;
    }
    for (int i = 0 ; i < 4 ; i ++)
    {
        if (matrix [y + dy [i]][x + dx [i]] == !true)
        {
            matrix [y + dy [i]][x + dx [i]] = true;
            dfs (x + dx [i], y + dy [i], time + map [y + dy [i]][x + dx[i]]);
            matrix [y + dy [i]][x + dx [i]] = !true;
        }
    }
}
*/
int dist [1024][1024];

void dijkstra (int x, int y, int useless)
{
    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < m ; j ++)
            dist [i][j] = max_val;
    ///                     Dist         X    Y
    priority_queue < pair < int, pair < int, int > > > q;
    q.push (make_pair (0, make_pair (x, y)));
    while (!q.empty ())
    {
        pair < int, pair < int, int > > top = q.top (); q.pop ();
    ///    cout << top.first << " " << top.second.first << " " << top.second.second << endl;
        if (dist [top.second.second][top.second.first] < top.first)
        {
            continue;
        }
        dist [top.second.second][top.second.first] = top.first;
        for (int i = 0 ; i < 4 ; i ++)
        {
            int new_x = top.second.first + dx [i];
            int new_y = top.second.second + dy [i];
            if (new_x < 0 or new_x >= m or new_y < 0 or new_y >= n)
                continue;
            if (map [new_y][new_x] != 0)
            {
                q.push (make_pair(top.first + map [new_y][new_x], make_pair(new_x, new_y)));
            }
        }
    }
    ///for (int i = 0 ; i < n ; i ++, cout << "\n")
    ///    for (int j = 0 ; j < m ; j ++)
    ///        cout << dist[i][j] << " ";
    int ans = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        if (matrix [i][0]) continue;
        int val = dist [i][0];
        if (ans == 0)
            ans = val;
        else
            ans = min (ans, val);
    }
    for (int i = 0 ; i < n ; i ++)
    {
        if (matrix [i][m - 1]) continue;
        int val = dist [i][m - 1];
        if (ans == 0)
            ans = val;
        else
            ans = min (ans, val);
    }
    for (int i = 0 ; i < m ; i ++)
    {
        if (matrix [0][i]) continue;
        int val = dist [0][i];
        if (ans == 0)
            ans = val;
        else
            ans = min (ans, val);
    }
    for (int i = 0 ; i < m ; i ++)
    {
        if (matrix [n - 1][i]) continue;
        int val = dist [n - 1][i];
        if (ans == 0)
            ans = val;
        else
            ans = min (ans, val);
    }
    optimal = ans;
}

int main ()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int myY, myX;
    for (int i = 0 ; i < n ; i ++)
    {
        string bla;
        cin >> bla;
        for (int j = 0 ; j < m ; j ++)
        {
            char a = bla [j];
            if (a == '*')
            {
                matrix [i][j] = true;
                map [i][j] = 0;
            }
            else if (a == '#')
            {
                myY = i;
                myX = j;
                map [i][j] = 0;
                matrix [i][j] = true;
            }
            else
                map [i][j] = a - 'A' + 1;
        }
    }
    dijkstra(myX, myY, 0);
    cout << optimal << "\n";
}
/**
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
