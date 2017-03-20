#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define NMax 11000

struct rect
{
    long long nx,ny,kx,ky;

    rect(){};
    rect(long long a,long long b,long long c,long long d)
    {
        nx=a,ny=b,kx=c,ky=d;
    }
} rects[NMax+5];

long long w,h,n,par[NMax+5],t,s[NMax+5];
long long sx,sy,lx,ly,x,y,curans;

vector<long long> nb[NMax+5];

bool cmp(rect a,rect b)
{
    return (a.kx-a.nx)>(b.kx-b.nx);
}

bool fit_in(rect a,rect b)
{
    if(a.nx<b.nx&&a.kx>b.kx&&a.ny<b.ny&&a.ky>b.ky)
        return 1;
    return 0;
}

bool pfit_in(long long x,long long y,rect a)
{
    if(a.nx<x&&a.kx>x&&a.ny<y&&a.ky>y)return 1;
    return 0;
}

void find_rect(long long tmpr)
{
    curans=tmpr;
    for(long long i=0;i<nb[tmpr].size();i++)
        if(pfit_in(x,y,rects[nb[tmpr][i]])==1)
            find_rect(nb[tmpr][i]);
}

int main()
{
    scanf("%lld%lld%lld",&w,&h,&n);

    for(long long i=0;i<n;i++)
        par[i]=-1;

    rects[0]=rect(0,0,w,h);

    for(long long i=0;i<n;i++)
    {
        scanf("%lld%lld%lld%lld",&sx,&sy,&lx,&ly);

        rects[i+1]=rect(sx,sy,sx+lx,sy+ly);
    }

    sort(rects,rects+n+1,cmp);

    for(long long i=1;i<=n;i++)
    {
        for(long long j=i-1;j>=0;j--)
            if(fit_in(rects[j],rects[i])==1)
            {
                par[i]=j;
                break;
            }
    }

    for(long long i=0;i<=n;i++)
        nb[par[i]].push_back(i);

    for(long long i=0;i<=n;i++)
    {
        s[i]=(rects[i].kx-rects[i].nx)*(rects[i].ky-rects[i].ny);

        for(long long j=0;j<nb[i].size();j++)
        {
            long long tmp=nb[i][j];
            s[i]-=(rects[tmp].kx-rects[tmp].nx)*(rects[tmp].ky-rects[tmp].ny);
        }
    }

    scanf("%lld",&t);

    for(long long i=0;i<t;i++)
    {
        scanf("%lld%lld",&x,&y);

        curans=0;
        find_rect(0);
        printf("%lld\n",s[curans]);
    }

    return 0;
}
/**
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
