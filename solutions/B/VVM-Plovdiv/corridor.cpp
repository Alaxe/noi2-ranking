#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

long long w,h,n,x[100010],y[100010],c=0,ans[100000000],anss;
struct line{
    long long x;
    long long y1, y2;
}a[100010];

bool f(line a, line b)
{
    return a.y1<b.y1;
}

int main()
{
    scanf("%lld%lld%lld",&w, &h, &n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
        if(i>0 && x[i]==x[i-1])
        {
            a[c].x=x[i];
            a[c].y1=min(y[i],y[i-1]);
            a[c].y2=max(y[i],y[i-1]);
            c++;
        }
    }
    sort(a,a+c,f);
    for(int i=0;i<c;i++)
    {
        for(int j=a[i].y1;j<a[i].y2;j++)
        {
            ans[j]=max(ans[j],a[i].x);
        }
    }
    for(int i=0;i<h;i++)
    {
        anss+=ans[i];
    }
    printf("%lld\n",w*h-anss);
    return 0;
}
/*
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
