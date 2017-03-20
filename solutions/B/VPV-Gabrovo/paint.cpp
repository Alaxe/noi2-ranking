#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[11005][11005],ans[11005];
struct rect
{
    long long x,y,w,h;
};
bool cmp(rect a, rect b)
{
    return a.h*a.w>b.h*b.w;
}
int main()
{

    long long n,m;
    rect r[11005];
    cin>>n>>m;
    ans[0]=n*m;
    long long k;
    cin>>k;
    for(long long i=1;i<=k;i++)
    {
        cin>>r[i].x>>r[i].y>>r[i].w>>r[i].h;
    }
    sort(r+1,r+k+1,cmp);
    for(long long i=1;i<=k;i++)
    {


            int xx,yy;
            int flag=0;
            xx=r[i].x;
            yy=r[i].y;
            while(1)
            {
                if(a[xx][yy]!=0)
                {

                    if(r[a[xx][yy]].h>r[i].y-yy){ ans[a[r[i].x][yy]]=ans[a[r[i].x][yy]]-((r[i].h)*(r[i].w));flag=1; break;}
                }
            yy--;
                if(yy<0){break;}
            }
            ans[i]=(r[i].h)*(r[i].w);
            if(flag==0)ans[0]=ans[0]-((r[i].h)*(r[i].w));
        for(long long p=r[i].x;p<r[i].x+r[i].w;p++)
        {


                a[p][r[i].y]=i;

        }
    }
    long long t;
    cin>>t;

    for(long long i=1;i<=t;i++)
    {
        long long xx,yy,yys;
        cin>>xx>>yy;
        yys=yy;
        while(1)
        {
            if(a[xx][yy]!=0)
            {
                if(r[a[xx][yy]].h>yys-yy){cout<<ans[a[xx][yy]]<<endl;break;}
            }
            yy--;
            if(yy<0){cout<<ans[0]<<endl;break;}
        }
    }
    return 0;
}
// 11 7 3 2 1 5 5 8 2 2 3 3 2 3 2 4 4 3 3 5 10 1 9 3
