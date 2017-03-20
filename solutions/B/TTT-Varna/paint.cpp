#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct point
{
    int x, y;
    point(){}
    point(int a, int b)
    {
        x=a, y=b;
    }
}points[11005];
struct rect
{
    point t;
    int a, b;
    long long s, parts;
    rect(){}
    rect(point k, int l, int m, int n)
    {
        t=k, a=l, b=m, s=n;
    }
}rectangles[11005];
bool cmp (rect a, rect b)
{
    return a.s<b.s;
}
int apl, bpl, n, t;
vector<int>nextnode[11005];
int vlogen (rect r1, rect r2)
{
    if (r2.t.x>=r1.t.x && r2.t.y>=r1.t.y && r2.t.x+r2.a<=r1.t.x+r1.a && r2.t.y+r2.b<=r1.t.y+r1.b) return 1;
    return 0;
}
void built(rect pr, int m)
{
    for (int i=0; i<=n; i++)
    {
        if (i!=m)
        {
            if (vlogen(pr,rectangles[i])) nextnode[m].push_back(i);
        }
    }
}
void find_parts(rect &pr, int n)
{
    for (int j=0; j<nextnode[n].size(); j++)
    {
        pr.parts-=rectangles[nextnode[n][j]].s;
        if (!nextnode[nextnode[n][j]].size()) continue;
        else
        {
            for (int k=0; k<nextnode[nextnode[n][j]].size(); k++)
            {
                pr.parts+=rectangles[nextnode[nextnode[n][j]][k]].s;
            }
        }
    }
}
void find_point(point p)
{
    for (int i=0; i<=n; i++)
    {
        if (p.x>=rectangles[i].t.x && p.y>=rectangles[i].t.y && p.x<=rectangles[i].t.x+rectangles[i].a &&
            p.y<=rectangles[i].t.y+rectangles[i].b)
        {
            printf("%lld\n",rectangles[i].parts);
            return ;
        }
    }
}
int main ()
{
    scanf ("%d%d",&apl,&bpl);
    scanf ("%d",&n);
    rectangles[0]=rect(point(0,0),apl,bpl,apl*bpl);
    rectangles[0].parts=rectangles[0].s;
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d%d%d",&rectangles[i].t.x,&rectangles[i].t.y,&rectangles[i].a,&rectangles[i].b);
        rectangles[i].s=rectangles[i].a*rectangles[i].b;
        rectangles[i].parts=rectangles[i].s;
    }
    sort(rectangles,rectangles+n+1,cmp);
    for (int i=0; i<=n; i++)
    {
        built(rectangles[i],i);
    }
    for (int i=0; i<=n; i++)
    {
        find_parts(rectangles[i],i);
    }
    scanf ("%d",&t);
    for (int i=0; i<t; i++)
    {
        scanf("%d%d",&points[i].x,&points[i].y);
        find_point(points[i]);
    }
}
