#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1024;

struct Point
{
    int x, y;
};

int n, idx;
Point p[MAXN];

int cross_product(Point A, Point B)
{
    int x1 = A.x - p[idx].x, y1 = A.y - p[idx].y;
    int x2 = B.x - p[idx].x, y2 = B.y - p[idx].y;
    return x1 * y2 - x2 * y1;
}

bool cmp(Point A, Point B)
{
    if (A.y < p[idx].y and B.y > p[idx].y) return 1;
    if (A.y > p[idx].y and B.y < p[idx].y) return 0;

    if (A.y == p[idx].y and A.x < p[idx].x)
    {
        if (B.y == p[idx].y and B.y < p[idx].x) return A.x < B.x;
        else return 1;
    }
    if (B.y == p[idx].y and B.x < p[idx].x) return 0;

    if (A.y == p[idx].y and A.x > p[idx].x)
    {
        if (B.y == p[idx].y and B.x > p[idx].x) return A.x < B.x;
        else return B.y > p[idx].y;
    }
    if (B.y == p[idx].y and B.x > p[idx].x) return A.y < p[idx].y;

    return cross_product(A, B) > 0;
}

int Count()
{
    int res = 0;

    vector<Point> v;
    for (int i = 1; i <= n; ++ i)
    {
        if (i != idx) v.push_back(p[i]);
    }

    stable_sort(v.begin(), v.end(), cmp);

    int s = 0, t;
    while (s < v.size() and (v[s].y < p[idx].y or (v[s].y == p[idx].y and v[s].x < p[idx].x))) s++;
    t = s;

    for (int i = 0; i < s; ++ i)
    {
        int ii = i, cnt = 0;
        while (ii + 1 < s and cross_product(v[i], v[ii + 1]) == 0) ii++;

        cnt = ii - i + 1;

        Point P;
        P.x = p[idx].x + (p[idx].x - v[i].x);
        P.y = p[idx].y + (p[idx].y - v[i].y);

        while (t < n - 1 and cross_product(v[t], P) > 0) t++;

        if (t < n - 1 and cross_product(v[t], P) == 0)
        {
            int tt = t;
            while (tt + 1 < n - 1 and cross_product(v[t], v[tt + 1]) == 0) tt++;
            cnt = cnt + tt - t + 1;
            t = tt;
        }
        res = max(res, cnt);
        i = ii;
    }

    for (int i = s; i < v.size(); ++ i)
    {
        int ii = i;
        while (ii + 1 < n - 1 and cross_product(v[i], v[ii + 1]) == 0) ii++;
        res = max(res, ii - i + 1);
        i = ii;
    }

    return res + 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> p[i].x >> p[i].y;
    }

    int ans = 0;
//    for (int i = 1; i <= n; ++ i)
//    {
//        idx = i;
//        for (int j = i + 1; j <= n; ++ j)
//        {
//            int cnt = 2;
//            for (int k = 1; k <= n; ++ k)
//            {
//                if (k == i or k == j) continue;
//                if (cross_product(p[j], p[k]) == 0) cnt++;
//            }
//            ans = max(ans, cnt);
//        }
//    }

    for (int i = 1; i <= n; ++ i)
    {
        idx = i;
        ans = max(ans, Count());
    }

    cout << ans << endl;
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
*/
