#include<iostream>
#include<math.h>
using namespace std;
struct point
{
    int x,y;
};
int n,i,j,k,tab[1000][1000],res=0;
bool OnLine(point a,point b,point c)
{
    if(a.y==b.y && a.y==c.y)return true;
    if(a.x==b.x && a.x==c.x)return true;
    if(a.x-b.x==0)return false;
    if(a.y-b.y==0)return false;
    if(a.x-c.x==0)return false;
    if(a.y-c.y==0)return false;
    if((c.x-a.x)/(c.y-a.y) == (b.x-a.x)/(b.y-a.y))return true;
    return false;
}
int main()
{
    point p[1000];
    cin>>n;
    for(i=0;i<n;i++)cin>>p[i].x>>p[i].y;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(OnLine(p[i],p[j],p[k])==true)
                {
                    tab[i][j]++;
                    tab[i][k]++;
                    tab[j][k]++;
                    res=max(res,tab[i][j]);
                    res=max(res,tab[i][k]);
                    res=max(res,tab[j][k]);
                }
            }
        }
    }
    cout<<res+2<<endl;
    return 0;
}