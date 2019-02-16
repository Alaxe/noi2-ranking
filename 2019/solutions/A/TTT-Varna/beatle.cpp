#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct greda
{
    int xb, yb, ln;
    greda() {};
    greda (int a, int b, int c)
    {
        xb=a, yb=b, ln=c;
    }
} dyski[100005];
int over[100005], under[100005];
int n, p1, p2, p3;
vector <int> v[100005];
bool cmp (greda a, greda b)
{
    if (a.yb!=b.yb)
        return a.yb>b.yb;
    return a.xb<b.xb;
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    for (int i=1; i<=n; i++)
    {
        cin >>p1>>p2>>p3;
        dyski[i]=greda(p1, p2, p3);
    }
    sort (dyski+1,dyski+n+1, cmp);
    for (int i=1; i<=n; i++)
    {
        for (int j=dyski[i].xb; j<dyski[i].xb+dyski[i].ln; j++)
        {
            if (!over[j])
                over[j]=i;
        }
    }
    for (int i=1; i<=n; i++)
    {
        int tmpind=under[dyski[i].xb-1];
        for (int j=dyski[i].xb; j<dyski[i].xb+dyski[i].ln; j++)
        {
            if (under[j]==0)
            {
                under[j]=i;
            }
            else
            {
                if (under[j]!=tmpind)
                {
                    if (!tmpind && (j-1==dyski[tmpind].xb || j-1==dyski[tmpind].xb+dyski[tmpind].ln-1))
                        v[tmpind].push_back(i);
                    tmpind=under[j];
                    under[j]=i;
                }
                if (dyski[under[dyski[i].xb+dyski[i].ln]].xb>dyski[i].xb)
                    v[under[dyski[i].xb+dyski[i].ln]].push_back(i);
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        cout <<i<<": ";
        for (int j=0; j<v[i].size(); j++)
        {
            cout <<v[i][j]<<" ";
        }
        cout <<endl;
    }
}
/**
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


-----

2 6 3
8 6 2
4 5 2
7 5 1
9 5 2
1 4 2
5 4 5
1 3 1
4 3 2
9 3 3
2 2 2
6 2 2
8 1 5
*/
