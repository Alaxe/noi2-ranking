#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

struct point
{
    uint32_t x, y;
    point(uint32_t x, uint32_t y):x(x),y(y){}
    point(){}
};

bool operator< (point a, point b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}

bool operator== (point a, point b)
{
    if(a.x==b.x&&a.y==b.y)return true;
    return false;
}

struct segment
{
    point a, b;
    segment(point a, point b):a(a),b(b){}
    segment(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2):a(x1, y1), b(x2, y2){}
    segment(){}
};

vector<segment> v;
vector<uint32_t> dist;
uint32_t w, h;

void init()
{
    cin>>w>>h;
    dist.resize(h);
    for(uint32_t i=0; i<h; i++)
        dist[i]=1100000000;
    uint32_t n;
    cin>>n;
    point f;
    cin>>f.x>>f.y;
    for(uint32_t i=1; i<n; i++)
    {
        point s;
        cin>>s.x>>s.y;
        if(f.x==s.x&&f.y<s.y)v.push_back(segment(f, s));
        f=s;
    }
}

void fill_dist (segment s)
{
    for(uint32_t i=s.a.y; i<s.b.y; i++)
    {
        if(dist[i]>w-s.a.x)dist[i]=w-s.a.x;
        //cout<<i<<" "<<w-s.a.x<<endl;
    }
}

void solve()
{
    for(uint32_t i=0;i<v.size(); i++)
        fill_dist(v[i]);

}

int main()
{   init();
    solve();
//    for(uint32_t i=0;i<v.size(); i++)
//        cout<<v[i].a.x<<" "<<v[i].a.y<<" "<<v[i].b.x<<" "<<v[i].b.y<<endl;
    uint64_t area=0;
    for(uint32_t i=0;i<dist.size(); i++)
        area+=(uint64_t)dist[i];//cout<<dist[i]<<endl;
    cout<<area<<endl;


    return 0;
}
