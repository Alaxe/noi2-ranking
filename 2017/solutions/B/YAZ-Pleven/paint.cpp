#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct rectangle
{
    int x,y,w,h;
    int area;
};
bool f1(rectangle a1, rectangle a2)
{
    if(a1.area>a2.area)return true;
    if(a1.area<a2.area)return false;
    if(a1.x>a2.x)return true;
    if(a1.x<a2.x)return false;
    return a1.y>a2.y;
}
vector<rectangle> v;
int a[11010][11010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w,h;
    cin>>w>>h;
    int n;
    cin>>n;
    v.resize(n+1);
    v[0].x=0;
    v[0].y=0;
    v[0].w=w;
    v[0].h=h;
    v[0].area=w*h;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].x>>v[i].y>>v[i].w>>v[i].h;
        v[i].area=v[i].w*v[i].h;
    }
    sort(v.begin(), v.end(), f1);
    for(int i=0; i<=n; i++)
    {
        for(int j=n; j>=0; j--)
        {
            if(v[i].x >= v[j].x &&
               v[i].y >= v[j].y &&
               v[i].x+v[i].w <= v[j].x+v[j].w &&
               v[i].y+v[i].h <= v[j].y+v[j].h &&
               i!=j)
               {
                   v[j].area-=v[i].area;
                   break;
               }
        }
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int x,y;
        cin>>x>>y;
        for(int j=n;j>=0;j--)
        {
            if(x >= v[j].x &&
               y >= v[j].y &&
               x <= v[j].x+v[j].w &&
               y <= v[j].y+v[j].h)
               {
                   cout<<v[j].area<<endl;
                   break;
               }
        }
    }
}
