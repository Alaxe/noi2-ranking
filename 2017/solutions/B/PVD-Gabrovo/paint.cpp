#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

struct point
{
    uint16_t x, y;
    point(uint16_t x, uint16_t y):x(x),y(y){}
    point(){}
};

struct square
{
    point a, b;
    square(point a, point b):a(a),b(b){}
    square(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2):a(x1, y1), b(x2, y2){}
    square(){}

    uint64_t get_area()
    {
        return (uint64_t)(b.x-a.x)*(uint64_t)(b.y-a.y);
    }
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

bool operator< (square a, square b)
{
    if(a.a==b.a)return a.b<b.b;
    return a.a<b.a;
}

vector<square> s;

void init()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uint16_t a,b;
    cin>>a>>b;
    uint16_t n;
    cin>>n;
    s.resize(n+1);
    s[0]=square(0, 0, a, b);
    for(uint16_t i=1; i<=n; i++)
    {
        uint16_t x, y, w, h;
        cin>>x>>y>>w>>h;
        s[i]=square(x, y, x+w, y+h);
    }
    sort(s.begin(), s.end());
}

bool is_in(point a, square b)
{
    if(a.x>b.a.x&&a.y>b.a.y&&a.x<b.b.x&&a.y<b.b.y)return true;
    return false;
}

bool is_in(square a, square b)
{
    return is_in(a.a, b);
}

uint64_t solve (uint16_t x, uint16_t y)
{
    uint64_t area=0;
    point t=point(x, y);
    square in_s=s[0];
    list<square> sq;
    for(uint16_t i=1; i<s.size(); i++)
    {
        if(is_in(t, s[i]))
        {
            sq.clear();
            in_s=s[i];
        }
        else if(is_in(s[i], in_s))
        {
            bool is_inside=false;
            for(list<square>::iterator it=sq.begin(); it!=sq.end(); it++)
                if(is_in(s[i], *it)){is_inside=true;break;}
            if(!is_inside)sq.push_back(s[i]);
        }
    }
    area=in_s.get_area();
    for(list<square>::iterator it=sq.begin(); it!=sq.end(); it++)
        area-=it->get_area();
//    cout<<in_s.a.x<<" "<<in_s.a.y<<" "<<in_s.b.x<<" "<<in_s.b.y<<endl;
//    cout<<sq.size()<<endl;
//    for(list<square>::iterator it=sq.begin(); it!=sq.end(); it++)
//        cout<<it->a.x<<" "<<it->a.y<<" "<<it->b.x<<" "<<it->b.y<<endl;

    return area;
}

int main()
{
    init();
//    for(uint16_t i=0; i<s.size(); i++)
//        cout<<s[i].a.x<<" "<<s[i].a.y<<" "<<s[i].b.x<<" "<<s[i].b.y<<endl;


    uint16_t t;
    cin>>t;
    for(uint16_t i=0;i<t;i++)
    {
        uint16_t x, y;
        cin>>x>>y;
        cout<<solve(x, y)<<endl;
    }
    //cout<<is_in(s[3], s[0])<<endl;

    return 0;
}
