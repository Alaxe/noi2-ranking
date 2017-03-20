#include<iostream>
using namespace std;
struct a
{
    int x1,x2,x3,x4,y1,y2,y3,y4;
};
int main()
{
    int w,h;
    cin>>w>>h;
    int broi;
    cin>>broi;
    int d,f;
    a p[broi];
    for(int i=0;i<broi;i++)
    {
        cin>>p[i].x1>>p[i].y1>>d>>f;
        p[i].x2=p[i].x1+d;
        p[i].y2=p[i].y1;
        p[i].x3=p[i].x2;
        p[i].y3=p[i].y2+f;
        p[i].x4=p[i].x1;
        p[i].y4=p[i].y3;
        //cout<<p[i].x1<<p[i].y1<<p[i].x2<<p[i].y2<<p[i].x3<<p[i].y3<<p[i].x4<<p[i].y4;
    }
    int x;
    cin>>x;
    int a[x],b[x];
    for(int j=0;j<x;j++)
    {
        cin>>a[j]>>b[j];


    }
}
