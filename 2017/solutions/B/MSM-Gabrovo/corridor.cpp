#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct point
{
    int x;
    int y;
    int e;
};

bool cmp(point k, point l)
{
    if(k.y!=l.y) return k.y<l.y;
    return k.x<l.x;
}

point a[100005];
long long s;

int main()
{
    int w,h;
    cin>>w>>h;
    int n;
    cin>>n;

    long long minx=1100000005;

    for(int i=1;i<=n;i++)
    {
        int xt,yt;
        cin>>xt>>yt;
        a[i].x=xt;
        a[i].y=yt;

        if(xt<minx) minx=xt;

        if(a[i-1].x==a[i].x)
        {
            a[i-1].e=a[i].y;
            a[i].e=a[i-1].y;
        }
    }

    sort(a,a+n+1,cmp);

    s+=minx*h;

    int k=a[n].x,l=a[n].y,p=a[n].e;
    s+=(k-minx)*(abs(l-p));
    if(l>p) swap(l,p);

    for(int i=n-1;i>0;i--)
    {
        if(a[i].y!=l && !(a[i].x<k && a[i].y>=l && a[i].y<=p))
        {
            s+=(a[i].x-minx)*(abs(a[i].y-a[i].e));
            k=a[i].x;
            l=a[i].y;
            p=a[i].e;
            if(l>p) swap(l,p);
        }
    }

    cout<<w*h-s<<endl;

    return 0;
}








