#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <assert.h>

#define pii pair<long long, long long>
using namespace std;
struct point
{
    long long y, x, type, otherPart;
    bool operator< (const point &f) const
    {
        if (f.y > y)
            return true;
        if (f.y < y)
            return false;
        if (f.x < x)
            return false;
        if (f.x > x)
            return true;
        return f.type > type;
    }
};
struct ots
{
    long long y1, y2, x;
    ots (pii p1, pii p2)
    {
        y1 = p1.second;
        y2 = p2.second;
        x = p1.first;
        if (y1 > y2)
            swap(y1, y2);
    }
    void addPoints(vector<point> &v)
    {
        v.push_back(point{y1, x, 1, y2});
        v.push_back(point{y2, x, 2, y1});
    }
};

long long w, h; // 1..1*10^9
long long n;    // 1..200 000

vector<point> v;
set<pii> heights;

int main ()
{
    pii pOld, pNew;
    scanf("%lld%lld", &w, &h);
    scanf("%lld", &n);
    scanf("%lld%lld", &pOld.first, &pOld.second);

    for (int i = 1;  i < n; i++)
    {
        scanf("%lld%lld", &pNew.first, &pNew.second);
        if (pNew.first == pOld.first)
            ots(pOld, pNew).addPoints(v);
        pOld = pNew;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {

    }

    long long prevReach = 0;
    long long cleaned = 0;

    point p = v.back();
    p.y++;
    v.push_back(p);
    for (int i = 0; i < v.size(); i++)
    {

        if (!heights.empty())
        {
            long long currReach = v[i].y;
            long long dist = v[i].y - prevReach;
            long long maxX = (*heights.rbegin()).first;
            cleaned += dist * maxX; // max height
         }
        prevReach = v[i].y;

        if (v[i].type == 1)
        {// Opening
            int oldsize = heights.size();
            heights.insert({v[i].x, v[i].y});
        }
        else
            heights.erase({v[i].x, v[i].otherPart});
    }
    long long ans = ((long long)w) * h - cleaned;
    printf("%lld\n", ans);
    return 0;
}
/*
15 10
16
6 10
6 8
11 8
11 4
8 4
8 6
9 6
9 5
10 5
10 7
6 7
6 3
12 3
12 2
9 2
9 0
*/
