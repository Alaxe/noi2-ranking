#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
struct point
{
  int x,y;
  point(){};
  point(int _x,int _y)
  {
      x=_x;
      y=_y;
  }
};
vector<point>v;
int check(int a,int b,int c,int pj)
{
    int cnt=2;
    for(int i=pj+1;i<n;i++)
    {
        if(v[i].x*a+v[i].y*b+c==0)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
     int ans=2;
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
         int x,y;
         scanf("%d%d",&x,&y);
         v.push_back(point(x,y));
     }
     for(int i=0;i<n;i++)
     {
         for(int j=i+1;j<n;j++)
         {
            int a=v[i].y-v[j].y;
            int b=v[j].x-v[i].x;
            int c=v[i].x*v[j].y-v[i].y*v[j].x;
            ans=max(ans,check(a,b,c,j));
         }
     }
     printf("%d\n",ans);
return 0;
}
