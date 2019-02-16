#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
const int MAX_N = 10001;
vector<vector<pair<int, int>>> v;
vector<vector<pair<int, int>>> le, ri;
map<pair<int, int>, int> path;
bool isCrossingLeft(pair<int, int> p1, pair<int, int> p2)
{
    return (p2.first < p1.first && p2.second >= p1.first && p2.second <= p1.second);
}
bool isCrossingRight(pair<int, int> p1, pair<int, int> p2)
{
    return (p2.first <= p1.second && p2.second > p1.second && p2.first >= p1.first);
}
bool isCrossingBoth(pair<int, int> p1, pair<int, int> p2)
{
    return (p2.first < p1.first && p2.second > p1.second);
}
bool isLeft(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first >= p2.second;
}
bool isRight(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second <= p2.first;
}
pair<int,int> findLeft(int y, int x)
{
    for(int j = y-1; j>=0; j--)
    {
        if(v[j].empty())
            continue;
        pair<int, int> up = v[y][x];
        pair<int, int> first = v[j][0];
        if(isRight(up, first))
            continue;
        for(int i=0; i<v[j].size(); i++)
        {
            pair<int, int> cur = v[j][i];
            if(isCrossingLeft(up, cur) || isCrossingBoth(up, cur))
            {
                return {j,i};
            }
        }
    }
    return {-1,-1};
}
pair<int,int> findRight(int y, int x)
{
    for(int j = y-1; j>=0; j--)
    {
        if(v[j].empty())
            continue;
        pair<int, int> up = v[y][x];
        pair<int, int> last = v[j][v[j].size()-1];
        if(isLeft(up, last))
            continue;
        for(int i=0; i<v[j].size(); i++)
        {
            pair<int, int> cur = v[j][i];
            if(isCrossingRight(up, cur) || isCrossingBoth(up, cur))
            {
                return {j,i};
            }
        }
    }
    return {-1,-1};
}
bool contains(pair<int, int> p, int x)
{
    return x >= p.first && x < p.second;
}
pair<int, int> fallsIn(int x)
{
    for(int i=MAX_N-1; i>=0; i--)
    {
        if(v[i].empty())
            continue;
        for(int j=0; j<v[i].size(); j++)
        {
            if(contains(v[i][j], x))
            {
                return {i,j};
            }
        }
    }
    return {-1, -1};
}
int findSmallestPath(pair<int, int> ids)
{
    if(ids.first == -1 && ids.second == -1)
        return 0;
    int l, r;
    if(path[le[ids.first][ids.second]] == -1)
    {
        l = findSmallestPath(le[ids.first][ids.second]);
    }
    else
    {
        l = path[le[ids.first][ids.second]];
    }
    if(path[ri[ids.first][ids.second]] == -1)
    {
        r = findSmallestPath(ri[ids.first][ids.second]);
    }
    else
    {
        r= path[ri[ids.first][ids.second]];
    }
    path[ids] = min(l, r)+1;
    return path[ids];
}
int main()
{
    vector<vector<pair<int, int>>> left, right;
    int n;
    scanf("%d", &n);
    v.resize(MAX_N);
    le.resize(MAX_N);
    ri.resize(MAX_N);
    for(int i=1; i<=n; i++)
    {
        int x,y,d;
        scanf("%d%d%d", &x, &y, &d);
        v[y].push_back({x, x+d});
    }
    for(int i=0; i<MAX_N; i++)
    {
        if(!v[i].empty())
        {
            sort(v[i].begin(), v[i].end());
        }
    }
    for(int i=MAX_N-1; i>=0; i--)
    {
        if(!v[i].empty())
        {
            for(int j=0; j<v[i].size(); j++)
            {
                pair<int, int> l = findLeft(i,j);
                pair<int, int> r = findRight(i,j);
                path[ {i,j}]=-1;
                /*cout<<i<<" "<<j<<endl;
                cout<<l.first<<" "<<l.second<<endl;
                cout<<r.first<<" "<<r.second<<endl;
                cout<<endl;*/
                le[i].push_back(l);
                ri[i].push_back(r);
            }
        }
    }
    for(int i=MAX_N-1; i>=0; i--)
    {
        if(!v[i].empty())
        {
            for(int j=0; j<v[i].size(); j++)
            {
                pair<int, int> cur =v[i][j];
                path[cur] = findSmallestPath({i,j});
            }
        }
    }
    int t, ti;
    scanf("%d", &t);
    for(int i=1; i<t; i++)
    {
        scanf("%d", &ti);
        pair <int, int> beg = fallsIn(ti);
        printf("%d ", path[beg]);
    }
    scanf("%d", &ti);
    pair <int, int> beg = fallsIn(ti);
    printf("%d\n", path[beg]);
    return 0;
}
/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11


9
1 8 2
1 7 2
1 3 1
1 2 2
3 4 5
3 1 2
4 6 4
6 7 3
7 5 3
*/
