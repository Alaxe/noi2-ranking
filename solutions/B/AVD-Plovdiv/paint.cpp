#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct rect
{
    long long x,y,w,h;
}r[16384];
long long a,b,n,q;
long long bef[16384];
long long areas[16384];
bool cmp(rect a,rect b)
{
    return (a.w*a.h)>(b.w*b.h);
}
vector<long long>v[16384];
int main()
{
    scanf("%lld%lld%lld",&a,&b,&n);
    r[0].x=r[0].y=0;
    r[0].w=a;
    r[0].h=b;
    for(long long i=1;i<=n;i++)
        scanf("%lld%lld%lld%lld",&r[i].x,&r[i].y,&r[i].w,&r[i].h);
    sort(r+1,r+n+1,cmp);
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i-1;j>=0;j--)
        {
            if(r[j].x<r[i].x && r[j].x+r[j].w>r[i].x &&
               r[j].y<r[i].y && r[j].y+r[j].h>r[i].y)
            {
                bef[i]=j;
                v[j].push_back(i);
                break;
            }
        }
    }
    for(long long i=0;i<=n;i++)
    {
        areas[i]=r[i].w*r[i].h;
        for(long long j=0;j<v[i].size();j++)
            areas[i]-=r[v[i][j]].w*r[v[i][j]].h;
    }
    scanf("%lld",&q);
    for(long long i=0;i<q;i++)
    {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        for(long long j=n;j>=0;j--)//TUK TRQBVA DA GO OPRAVQ
            if(r[j].x<x && r[j].x+r[j].w>x && r[j].y<y && r[j].y+r[j].h>y)
            {
                printf("%lld\n",areas[j]);
                break;
            }
    }
    return 0;
}
/*
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
