#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
};
point prev, p;
struct segments
{
    point a,b;
    segments(){}
    segments(point x, point y)
    {
        a=x, b=y;
    }
}segm[500001];
long long w, h, n, m, sum;
int compare_segm (segments d1, segments d2)
{
    if (d1.a.y>d1.b.y) swap(d1.a,d1.b);
    if (d2.a.y>d2.b.y) swap(d2.a,d2.b);
    if (d2.a.y>=d1.a.y && d2.b.y<=d1.a.y && d1.a.x<d2.a.x) return 1;
    if (d2.a.y>=d1.a.y && d2.b.y<=d1.a.y && d1.a.x>d2.a.x) return 2;
    if (d1.a.y>=d2.a.y && d1.b.y<=d2.a.y && d1.a.x>d2.a.x) return 3;
    if (d1.a.y>=d2.a.y && d1.b.y<=d2.a.y && d1.a.x<d2.a.x) return 4;
    if (d2.a.y>=d1.b.y && d2.b.y>d1.b.y && d1.a.x<d2.a.x) return 5;
    if (d2.a.y>=d1.b.y && d2.b.y>d1.b.y && d1.a.x>d2.a.x) return 5;
    if (d1.a.y>=d2.b.y && d1.b.y>d1.b.y && d1.a.x<d2.a.x) return 5;
    if (d1.a.y>=d2.b.y && d1.b.y>d1.b.y && d1.a.x<d2.a.x) return 5;
    if (d2.a.y>=d1.a.y && d2.a.y<d1.b.y && d2.b.y>d1.b.y && d1.a.x<d2.a.x) return 9;
    if (d2.a.y>=d1.a.y && d2.a.y<d1.b.y && d2.b.y>d1.b.y && d1.a.x>d2.a.x) return 10;
    if (d2.b.y<=d1.b.y && d2.b.y>d1.a.y && d2.a.y<d1.a.y && d1.a.x<d2.a.x) return 11;
    if (d2.b.y<=d1.b.y && d2.b.y>d1.a.y && d2.a.y<d1.a.y && d1.a.x>d2.a.x) return 12;
}
int main ()
{
    cin >>w>>h;
    cin >>n;
    cin >>prev.x>>prev.y;
    for (int i=1; i<n; i++)
    {
        cin >>p.x>>p.y;
        if (prev.y==p.y) continue;
        else if (prev.x==p.x)
        {
            if (m==0)
            {
                segm[m++]=segments(prev,p);
                if ((p.y-prev.y)*p.x<0) sum-=(p.y-prev.y)*p.x;
                else sum+=(p.y-prev.y)*p.x;
                continue;
            }
            else
            {
                if(compare_segm(segm[m],segments(prev,p))==1)
                {
                    if ((p.y-prev.y)*(p.x-prev.x)<0) sum-=(p.y-prev.y)*(p.x-prev.x);
                    else sum+=(p.y-prev.y)*(p.x-segm[m].a.x);
                    segm[m++]=segments(prev,p);
                    continue;
                }
                else if (compare_segm(segm[m],segments(prev,p))==2)
                {
                    continue;
                }
                else if (compare_segm(segm[m],segments(prev,p))==3)
                {
                    sum+=(min(segm[m].a.y,segm[m].b.y)-min(prev.y,p.y))*p.x+(max(prev.y,p.y)-max(segm[m].a.y,segm[m].b.y))*p.x;
                    segm[m++]=segments(prev,p);
                    continue;
                }
                else if (compare_segm(segm[m],segments(prev,p))==4)
                {
                    sum+=((max(prev.y,p.y)-min(prev.y,p.y))*p.x-(max(segm[m].a.y,segm[m].b.y)-min(segm[m].a.y,segm[m].b.y))*segm[m].a.x);
                    segm[m++]=segments(prev,p);
                    continue;
                }
                else if (compare_segm(segm[m],segments(prev,p))==5)
                {
                    sum+=((max(prev.y,p.y)-min(prev.y,p.y))*p.x);
                    segm[m++]=segments(prev,p);
                    continue;
                }
                else if (compare_segm(segm[m],segments(prev,p))==9)
                {
                    sum+=((max(segm[m].a.y,segm[m].b.y)-min(prev.y,p.y))*(p.x-segm[m].a.x)+(max(p.y,prev.y)-max(segm[m].a.y,segm[m].b.y))*p.x);
                    segm[m++]=segments(prev,p);
                    continue;
                }
                else if (compare_segm(segm[m],segments(prev,p))==10)
                {
                    sum+=((min(segm[m].a.y,segm[m].b.y)-min(prev.y,p.y))*p.x);
                    segm[m++]=segments(prev,p);
                    continue;
                }
                else if (compare_segm(segm[m],segments(prev,p))==11)
                {
                    sum+=((max(prev.y,p.y)-min(segm[m].a.y,segm[m].b.y))*(p.x-segm[m].a.x));
                    segm[m++]=segments(prev,p);
                    continue;
                }
                else if (compare_segm(segm[m],segments(prev,p))==12)
                {
                    sum+=((max(p.y,prev.y)-max(segm[m].a.y,segm[m].b.y))*p.x);
                    segm[m++]=segments(prev,p);
                    continue;
                }
            }
        }
        prev=p;
    }
    cout <<w*h-sum<<endl;
}
