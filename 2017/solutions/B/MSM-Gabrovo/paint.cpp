#include<iostream>
#include<algorithm>
using namespace std;

struct rectangle
{
    int x;
    int y;
    int w;
    int h;
    int s;
};

bool cmp (rectangle a,rectangle b)
{
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}

rectangle p[11005];

int main()
{
    int a,b;
    cin>>a>>b;
    p[0].x=0;
    p[0].y=0;
    p[0].w=a;
    p[0].h=b;
    p[0].s=a*b;

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int xt,yt,wt,ht;
        cin>>xt>>yt>>wt>>ht;
        p[i].x=xt;
        p[i].y=yt;
        p[i].w=wt;
        p[i].h=ht;
        p[i].s=wt*ht;
    }

    sort(p,p+n+1,cmp);

    for(int i=n;i>0;i--)
    {
        bool flag=false;
        int j=i-1;

        while(!flag)
        {
            if(p[i].x>p[j].x && p[i].x<p[j].x+p[j].w && p[i].y>p[j].y && p[i].y<p[j].y+p[j].h)
            {
                p[j].s-=p[i].w*p[i].h;
                flag=true;
            }
            j--;
        }


    }

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int x,y;
        cin>>x>>y;

        for(int j=n;j>=0;j--)
        {
            if(x>p[j].x && x<p[j].x+p[j].w && y>p[j].y && y<p[j].y+p[j].h)
            {
                cout<<p[j].s<<endl;
                break;
            }
        }
    }

    return 0;
}









