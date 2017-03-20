#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int W, H, n, ix, iy, iw, ih, t, qx, qy, rNumb;

struct Rectangle
{
    int x1, y1, x3, y3, s;    
};

bool cmp(Rectangle ff, Rectangle ss)
{
    return ff.s<ss.s;
}

vector<Rectangle> a;
Rectangle currR;

int solve(int qX, int qY)
{
    int ansR, mindist=1000000, currdist;
    for(int i=0; i<n+1; ++i)
    {
        if(a[i].x1<qX && a[i].y1<qY && a[i].x3>qX && a[i].y3>qY)
        {
            currdist=min(qX-a[i].x1, a[i].x3-qX)*min(qY-a[i].y1, a[i].y3-qY);
            if(currdist<mindist)
            {
                mindist=currdist;
                ansR=i;
            }
        }
    }
    return ansR;
}

int main ()
{
    //freopen("i1.txt", "r", stdin);
    scanf("%d %d", &W, &H);
    scanf("%d", &n);
    currR.x1=0;currR.y1=0;currR.x3=W;currR.y3=H;currR.s=W*H;
    a.push_back(currR);
    for(int i=0; i<n; ++i)
    {
        scanf("%d %d %d %d", &ix, &iy, &iw, &ih);
        currR.x1=ix;
        currR.y1=iy;
        currR.x3=ix+iw;
        currR.y3=iy+ih;
        currR.s=iw*ih;
        a.push_back(currR);
    }
    sort(a.begin(), a.end(), cmp);
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n+1; ++j)
        {
            if(a[j].x1<a[i].x1 && a[j].y1<a[i].y1 && a[j].x3>a[i].x3 && a[j].y3>a[i].y3)
            {
                a[j].s-=a[i].s;
            }
        }
    }
    scanf("%d", &t);
    for(int kk=0; kk<t; ++kk)
    {
        scanf("%d %d", &qx, &qy);
        rNumb=solve(qx, qy);
        printf("%d\n", a[rNumb].s);
    }
    return 0;
}