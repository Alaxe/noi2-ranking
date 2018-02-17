#include <iostream>
#include <cstdio>
using namespace std;

struct Segment
{
 long long x1;
 long long y1;
 long long x2;
 long long y2;
};

Segment a[100005];
long long x[100005],y[100005];

int main()
{

long long w,h,cy,s,ans;
int n,i;

scanf("%lld%lld",&w,&h);
scanf("%d",&n);

 for(i=1;i<=n;i++)
  scanf("%lld%lld",&x[i],&y[i]);

 for(i=1;i<n;i++)
 {
  a[i].x1=x[i];
  a[i].y1=y[i];
  a[i].x2=x[i+1];
  a[i].y2=y[i+1];
 }

s=0;
cy=0;
 for(i=1;i<n;i++)
 {
  if(a[i].x1==a[i].x2)
  {
   if(a[i].y2>cy)
   {
    s+=(a[i].y2-cy)*a[i].x1;
    cy=a[i].y2;
   }
  }
 }

ans=w*h-s;

printf("%lld\n",ans);

return 0;
}
