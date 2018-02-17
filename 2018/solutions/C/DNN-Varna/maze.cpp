#include <iostream>
#include <vector>
using namespace std;
long long n, m;
long long bx, by, ex, ey;
char d[128][128];
long long dist[128][128][2];
long long min_path = 300000;

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> d[i][j];
            dist[i][j][0] = dist[i][j][1] = 300000;
            if (d[i][j] == 'E')
            {
                ex = i;
                ey = j;
            }
            if (d[i][j] == 'B')
            {
                bx = i;
                by = j;

            }
        }


    /*cout << "------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << d[i][j];
        cout << endl;
    }*/

}

void rec(long long x, long long y, long long path, long long walls)
{

    if (d[x][y] == 'E')
    {
        min_path = min(min_path, path);
        return;
    }

    if (path >= dist[x][y][0] && walls == 0)return;
    if (path < dist[x][y][0] && walls == 0)dist[x][y][0] = path;
    if (path >= dist[x][y][1] && walls == 1)return;
    if (path < dist[x][y][1] && walls == 1)dist[x][y][1] = path;

    //cout << x << " " << y << " " << path << " " << walls << endl;

    // up
    if (x > 0)
    {
        if (d[x - 1][y] == '#' && walls == 0)rec(x - 1, y, path + 3, walls + 1);
        if (d[x - 1][y] != '#')rec(x - 1, y, path + 1, walls);
    }

    // down
    if (x < n - 1)
    {
        if (d[x + 1][y] == '#' && walls == 0)rec(x + 1, y, path + 3, walls + 1);
        if (d[x + 1][y] != '#')rec(x + 1, y, path + 1, walls);
    }

    //left
    if (y > 0)
    {
        if (d[x][y - 1] == '#' && walls == 0)rec(x, y - 1, path + 3, walls + 1);
        if (d[x][y - 1] != '#')rec(x, y - 1, path + 1, walls);
    }

    //right
    if (y < m - 1)
    {
        if (d[x][y + 1] == '#' && walls == 0)rec(x, y + 1, path + 3, walls + 1);
        if (d[x][y + 1] != '#')rec(x, y + 1, path + 1, walls);
    }
}

int main()
{
    input();
    rec(bx, by, 0, 0);

    cout << min_path << endl;

    return 0;

}
/*
6 7
.....B.
.#####.
.#...#.
.#E#.#.
.###.#.
.......
*/
