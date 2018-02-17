#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

long long a,b,n,t,tx,ty,ans[11010], p[11010],k;
vector<int> v[11010];
struct r{
    long long x,y,w,h,area;
}s[11010];

bool f(r a, r b)
{
    return a.area<b.area;
}

bool isin(r a, long long x, long long y)
{
    if(a.x<x && a.x+a.w>x && a.y<y && a.y+a.h>y)
    {
        return true;
    }
    return false;
}

void read()
{
    scanf("%lld%lld%lld",&a,&b,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld%lld",&s[i].x, &s[i].y, &s[i].w, &s[i].h);
        s[i].area=s[i].w*s[i].h;
    }
    s[n].x=s[n].y=0;
    s[n].w=a;
    s[n].h=b;
    s[n].area=a*b;
    n++;

    sort(s,s+n,f);
    //mahane na pr., koito sa vutre i postroqvane na grafa
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((s[j].x+s[j].w)<(s[i].x+s[i].w) && (s[j].y+s[j].h)<(s[i].y+s[i].h) && s[j].x>s[i].x && s[j].y>s[i].y)
            {
                s[i].area-=s[j].area;
            }
        }
    }
    //obhojdane
    scanf("%lld",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld%lld",&tx,&ty);
        for(int j=0;j<n;j++)
        {
            if(isin(s[j],tx,ty))
            {
                ans[i]=s[j].area;
                break;
            }
        }
    }

    for(int i=0;i<t;i++)
    {
        printf("%lld\n",ans[i]);
    }
}
int main()
{
    read();
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

13 10
6
1 1 6 8
9 7 1 2
3 7 2 1
2 2 4 4
3 3 2 2
9 3 3 3
4
4 4
6 8
10 5
10 2
*/
