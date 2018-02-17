#include<bits/stdc++.h>

using namespace std;

struct coor
{
    int first, second;

    coor ();
    coor (int f, int s)
    {
        first = f;
        second = s;
    }
};

int t[105][105] = {0};

int main()
{
    int n, m, sr, sc, fr, fc;
    char c;

    cin >> n >> m;

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cin >> c;

            if (c == '#')
            {
                t[i][j] = -1;
            }
            else if (c == 'B')
            {
                sr = i;
                sc = j;
            }
            else if (c == 'E')
            {
                fr = i;
                fc = j;
            }
        }
    }

    queue< coor > q;

    q.push( coor(sr, sc) );

    while (q.size())
    {
        coor front = q.front();

        int i = front.first;
        int j = front.second;

        q.pop();

        if (i + 1 < n)
        {
            if (t[i+1][j] == 0 && !(sr == i + 1 && sc == j))
            {
                q.push(coor(i+1, j));
                t[i+1][j] = t[i][j] + 1;
            }
        }
        if (j + 1 < m)
        {
            if (t[i][j+1] == 0 && !(sr == i && sc == j + 1))
            {
                q.push(coor(i, j+1));
                t[i][j+1] = t[i][j] + 1;
            }
        }
        if (i - 1 >= 0)
        {
            if (t[i-1][j] == 0 && !(sr == i - 1 && sc == j))
            {
                q.push(coor(i-1, j));
                t[i-1][j] = t[i][j] + 1;
            }
        }
        if (j - 1 >= 0)
        {
            if (t[i][j-1] == 0 && !(sr == i && sc == j - 1))
            {
                q.push(coor(i, j-1));
                t[i][j-1] = t[i][j] + 1;
            }
        }
    }

//    for (int i = 0; i < n; i ++)
//    {
//        for (int j = 0; j < m; j ++)
//        {
//            cout << t[i][j] << " ";
//        }
//        cout << endl;
//    }

    if (t[fr][fc])
    {
        int r = fr, c = fc, mini = 0;

        q.push(coor(fr, fc));

        while (q.size())
        {
            coor front = q.front();
            r = front.first;
            c = front.second;
            q.pop();

            if (r + 1 < n)
            {
                if (t[r+1][c] == t[r][c] - 1)
                {
                    q.push(coor(r+1, c));
                }
                else if (t[r+1][c] == -1)
                {
                    if (r + 2 < n)
                    {
                        if (t[r+2][c] != -1)
                        {
                            mini = min(mini, t[r+2][c] - t[r][c] + 4);
                        }
                    }
                    if (c + 1 < m)
                    {
                        if (t[r+1][c+1] != -1)
                        {
                            mini = min(mini, t[r+1][c+1] - t[r][c] + 4);
                        }
                    }
                    if (c - 1 >= 0)
                    {
                        if (t[r+1][c-1] != -1)
                        {
                            mini = min(mini, t[r+1][c-1] - t[r][c] + 4);
                        }
                    }
                }
            }
            if (r - 1 >= 0)
            {
                if (t[r-1][c] == t[r][c] - 1)
                {
                    q.push(coor(r-1, c));
                }
                else if (t[r-1][c] == -1)
                {
                    if (r - 2 >= 0)
                    {
                        if (t[r-2][c] != -1)
                        {
                            mini = min(mini, t[r-2][c] - t[r][c] + 4);
                        }
                    }
                    if (c + 1 < m)
                    {
                        if (t[r-1][c+1] != -1)
                        {
                            mini = min(mini, t[r-1][c+1] - t[r][c] + 4);
                        }
                    }
                    if (c - 1 >= 0)
                    {
                        if (t[r-1][c-1] != -1)
                        {
                            mini = min(mini, t[r-1][c-1] - t[r][c] + 4);
                        }
                    }
                }
            }
            if (c + 1 < m)
            {
                if (t[r][c+1] == t[r][c] - 1)
                {
                    q.push(coor(r, c+1));
                }
                else if (t[r][c+1] == -1)
                {
                    if (c + 2 < m)
                    {
                        if (t[r][c+2] != -1)
                        {
                            mini = min(mini, t[r][c+2] - t[r][c] + 4);
                        }
                    }
                    if (r + 1 < n)
                    {
                        if (t[r+1][c+1] != -1)
                        {
                            mini = min(mini, t[r+1][c+1] - t[r][c] + 4);
                        }
                    }
                    if (r - 1 >= 0)
                    {
                        if (t[r-1][c+1] != -1)
                        {
                            mini = min(mini, t[r-1][c+1] - t[r][c] + 4);
                        }
                    }
                }
            }
            if (c - 1 >= 0)
            {
                if (t[r][c-1] == t[r][c] - 1)
                {
                    q.push(coor(r, c-1));
                }
                else if (t[r][c-1] == -1)
                {
                    if (c - 2 >= 0)
                    {
                        if (t[r][c-2] != -1)
                        {
                            mini = min(mini, t[r][c-2] - t[r][c] + 4);
                        }
                    }
                    if (r + 1 < n)
                    {
                        if (t[r+1][c-1] != -1)
                        {
                            mini = min(mini, t[r+1][c-1] - t[r][c] + 4);
                        }
                    }
                    if (r - 1 >= 0)
                    {
                        if (t[r-1][c-1] != -1)
                        {
                            mini = min(mini, t[r-1][c-1] - t[r][c] + 4);
                        }
                    }
                }
            }
        }

        cout << t[fr][fc] + mini << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
/**
6 7
.....B.
.#####.
.#...#.
.#E#.#.
.###.#.
.......
*/
