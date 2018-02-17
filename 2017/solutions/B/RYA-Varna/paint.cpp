#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct rectangle{
int x,y;
int s,a,b;
};
int w,h,n,t;
rectangle r[11001];
vector<int> p[11002];
int cmp(rectangle a,rectangle b)
{
    if(a.y!=b.y)return a.y<b.y;
    if(a.x!=b.x)return a.x<b.x;
    if(a.a!=b.a)return a.a>b.a;
    return a.b>b.b;
}
int rect_in_rect(rectangle a,rectangle b)
{
    if(a.x<b.x && a.y<b.y && a.x+a.a>b.x+b.a && a.y+a.b>b.y+b.b)return 1;
    return 0;
}
int point_in_rect(rectangle a,int x,int y)
{
    if(a.x<x && a.y<y && a.x+a.a>x && a.y+a.b>y)return 1;
    return 0;
}
int main( )
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int i,j,x,y,k;
   cin>>w>>h;
   cin>>n;
   for(i=0;i<n;i++)
   {
       cin>>r[i].x>>r[i].y>>r[i].a>>r[i].b;
       r[i].s=r[i].a*r[i].b;
   }
   r[n].x=0;
   r[n].y=0;
   r[n].a=w;
   r[n].b=h;
   r[n].s=r[n].a*r[n].b;
   n++;
   sort(r,r+n,cmp);
   for(i=1;i<n;i++)
   {
       for(j=i-1;j>=0;j--)
       {
           if(rect_in_rect(r[j],r[i])==1)
           {
             p[j].push_back(i);
             break;
           }
       }
   }
   cin>>t;
   int ans;
   for(i=0;i<t;i++)
   {
       cin>>x>>y;
       ans=0;
       for(j=n-1;j>=0;j--)
       {
           if(point_in_rect(r[j],x,y)==1)
           {
              ans=r[j].s;
              for(k=0;k<p[j].size( );k++)
              {
                  ans-=r[p[j][k]].s;
              }
              cout<<ans<<endl;
              break;
           }
       }
   }
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
