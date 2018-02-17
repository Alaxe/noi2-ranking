#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct sqr
{
    int x,y;
    int w,h;
    int n;
};
bool fff(sqr a,sqr b)
{
    if(a.x>b.x)
        return false;
    if(a.x<b.x)
        return true;
    return a.y<b.y;
}
sqr make_sqr(int x,int y,int w,int h)
{
    sqr t;
    t.x=x;
    t.y=y;
    t.w=w;
    t.h=h;
    return t;
}
vector<sqr> sqrs[11000];
sqr a[11000];
void add(sqr s,int index)
{
    bool added=false;
    for(int i=0; i<sqrs[index].size(); i++)
    {
        sqr t=sqrs[index][i];
        if(s.x>t.x && s.y>t.y && (t.w+t.x)>s.x && (t.h+t.y)>s.y)
        {
            add(s,sqrs[index][i].n);
            added=true;
            break;
        }
    }
    if(!added)
    {
        sqrs[index].push_back(s);
        return;
    }
}
int w,h;
void findArea(int x,int y,int index,int &s)
{
    bool found=false;
    for(int i=0; i<sqrs[index].size(); i++)
    {
        sqr t=sqrs[index][i];
        if(x>t.x && y>t.y && (t.w+t.x)>x && (t.h+t.y)>y)
        {
            findArea(x,y,sqrs[index][i].n,s);
            found=true;
            break;
        }
    }
    if(!found)
    {
        if(index==0)
        {
            s=w*h;
        }
        else
            s=a[index-1].w*a[index-1].h;
        for(int i=0; i<sqrs[index].size(); i++)
        {
            s-=sqrs[index][i].w*sqrs[index][i].h;
        }
        return;
    }
}
int main ()
{
    int n,t1,t2,t3,t4,t;
    scanf("%d%d%d",&w,&h,&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
        a[i]=make_sqr(t1,t2,t3,t4);
    }
    sort(a,a+n,fff);
    //sqrs[0].push_back(make_sqr(0,0,w,h));
    for(int i=0; i<n; i++)
    {
        a[i].n=i+1;
        add(a[i],0);
    }

    vector<int> ans;
    scanf("%d",&t);
    ans.resize(t);
    for(int i=0; i<t; i++)
    {
        scanf("%d%d",&t1,&t2);
        int s=0;
        findArea(t1,t2,0,s);
        ans[i]=s;
    }
    for(int i=0; i<ans.size(); i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
