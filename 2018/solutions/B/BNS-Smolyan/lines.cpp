#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;

struct point
{
    int x, y;

    bool operator<(point other) const
    {
        if(x < other.x) return true;
        if(x > other.x) return false;
        if(y < other.y) return true;
        if(y > other.y) return false;
        return true;
    }
};

int n;
vector <point> v;
int T[MAXN][300][300];

bool h2(point f, point s)
{
    if(f.y < s.y) return true;
    if(f.y > s.y) return false;
    if(f.x < s.x) return true;
    if(f.x > s.x) return false;
    return true;
}

bool check(int x, int y, point c)
{
    return (c.x % x == 0) && (c.y % y == 0);
}

int solve(int index, int x, int y)
{
    if(T[index][x][y])
    {
        return T[index][x][y];
    }
    int ans = 0;
    for(int i = index + 1; i < n; i++)
    {
        if(check(x, y, v[i]))
        {
            int X = abs(v[i].x - v[index].x);
            int Y = abs(v[i].y - v[index].y);
            int c = __gcd(X, Y);
            if(X == 0 || Y == 0) continue;
            X /= c; Y /= c;
            ans = max(ans, solve(i, X, Y));
        }
    }
    return T[index][x][y] = (ans + 1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        point p;
        p.x = x; p.y = y;
        v.push_back(p);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int X = abs(v[j].x - v[i].x);
            int Y = abs(v[j].y - v[i].y);
            int c = __gcd(X, Y);
            if(X == 0 || Y == 0) continue;
            X /= c; Y /= c;
            ans = max(solve(j, X, Y), ans);
        }
    }
    int X = v[0].x, l = 0;
    for(int i = 1; i < n; i++)
    {
        if(v[i].x == X)
        {
            l++;
        }
        else
        {
            ans = max(l, ans);
            l = 0;
            X = v[i].x;
        }
    }
    ans = max(l, ans);
    sort(v.begin(), v.end(), h2);
    int Y = v[0].y;
    l = 0;
    for(int i = 1; i < n; i++)
    {
        if(v[i].y == Y)
        {
            l++;
        }
        else
        {
            ans = max(l, ans);
            l = 0;
            Y = v[i].y;
        }
    }
    ans = max(l, ans);

    printf("%d\n", ans + 1);
    return 0;
}

/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3

4
*/

/*
4
-2 -6
-1 -3
0 0
1 3

4
*/

/*
4
-2 -6
-1 -3
0 0
1 4

3
*/

/*
12
1 0
1 1
1 2
1 3
2 6
1 4
1 5
2 2
3 3
4 4
5 5
6 6

6
*/

/*
4
0 4
1 3
2 2
3 1

4
*/
