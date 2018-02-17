#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Rect
{
 int x1;
 int y1;
 int x2;
 int y2;
 int s;
 bool inside;
 int rs;
};

Rect a[11005];
int ans[11005];

bool Compare(Rect p,Rect q)
{
 return p.s<q.s;
}

bool IsInside(int j,int i)
{
  if(a[j].x1>a[i].x1 && a[j].y1>a[i].y1 && a[j].x2<a[i].x2 && a[j].y2<a[i].y2)
   return true;

 return false;
}

bool PointIsInside(int j,int x,int y)
{
  if(x>a[j].x1 && y>a[j].y1 && x<a[j].x2 && y<a[j].y2)
   return true;

 return false;
}

int main()
{

int n,w,h,i,j,p,q,x,y,t,mn,ind;

scanf("%d%d",&w,&h);

scanf("%d",&n);

 for(i=1;i<=n;i++)
 {
  scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&p,&q);
  a[i].x2=a[i].x1+p;
  a[i].y2=a[i].y1+q;
  a[i].s=p*q;
  a[i].inside=false;
  a[i].rs=0;
 }

a[n+1].x1=0;
a[n+1].y1=0;
a[n+1].x2=w;
a[n+1].y2=h;
a[n+1].s=w*h;
a[n+1].inside=false;
a[n+1].rs=0;
n++;

sort(a+1,a+n+1,Compare);

 for(i=1;i<=n;i++)
  for(j=i-1;j>=1;j--)
  {
   if(IsInside(j,i))
   {
    if(!a[j].inside)
    {
     a[j].inside=true;
     a[i].rs+=a[j].s;
    }
   }
  }

scanf("%d",&t);

 for(i=1;i<=t;i++)
 {
  scanf("%d%d",&x,&y);

  mn=999999999;
   for(j=1;j<=n;j++)
   {
    if(PointIsInside(j,x,y))
    {
     if(a[j].s<mn)
     {
      mn=a[j].s;
      ind=j;
     }
    }
   }

  ans[i]=a[ind].s-a[ind].rs;
 }

 for(i=1;i<=t;i++)
  printf("%d\n",ans[i]);

return 0;
}
