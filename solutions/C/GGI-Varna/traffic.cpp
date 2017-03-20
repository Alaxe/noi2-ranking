#include <bits/stdc++.h>
using namespace std;
int curr_dist = 0, dist = 123456, m, n, sr, sc;
char a[641][641];
void rec (int r, int c)
{
    if (a[r][c] == '*') return;
    if (r == 0 || r == n - 1)
    {
        curr_dist += (int) (a[r][c] - 'A' + 1);
        if (dist > curr_dist) dist = curr_dist;
        curr_dist = 0;
        return;
    }
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    curr_dist += (int) (a[r][c] - 'A' + 1);
    a[r][c] = '*';
    rec (r - 1, c);
    rec (r, c - 1);
    rec (r, c + 1);
    rec (r + 1, c);

}

int main ( )
{
    cin >> n >> m;
    for (int i = 0; i < n; ++ i)
    {
        for (int j = 0; j < m; ++ j)
        {
            cin >> a[i][j];
            if (a[i][j] == '#')
            {
                sr = i;
                sc = j;
            }
        }

    }
    a[sr][sc] = '*';
    rec (sr + 1, sc);
    rec (sr - 1, sc);
    rec (sr, sc + 1);
    rec (sr, sc - 1);
    cout << dist << endl;
    return 0;
}
