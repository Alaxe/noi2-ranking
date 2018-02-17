#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
    int64_t x, y;
};

int64_t cross_product (point a, point b, point c)
{
    int64_t x1=b.x-a.x, y1=b.y-a.y;
    int64_t x2=c.x-a.x, y2=c.y-a.y;
    return (y1*x2)-(y2*x1);
}

vector <point> points;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n;
    cin>>n;
    points.resize(n);
    for(int64_t i=0; i<n; i++)
        cin>>points[i].x>>points[i].y;
}

point cmp_point_base;
bool cmp_point (const point &a, const point &b)
{
    int64_t res;
    if((res=cross_product(cmp_point_base, a, b))==0)
    {
        //cout<<a.x<<' '<<a.y<<' '<<b.x<<' '<<b.y<<endl;
        //return (int64_t)((int64_t)cmp_point_base.x-(int64_t)a.x)*((int64_t)cmp_point_base.x-(int64_t)a.x)+((int64_t)cmp_point_base.y-(int64_t)a.y)*((int64_t)cmp_point_base.y-(int64_t)a.y) <
        //       (int64_t)((int64_t)cmp_point_base.x-(int64_t)b.x)*((int64_t)cmp_point_base.x-(int64_t)b.x)+((int64_t)cmp_point_base.y-(int64_t)b.y)*((int64_t)cmp_point_base.y-(int64_t)b.y);
    }
    //else
    //   return res<0;
    return res>0;
}

/*uint16_t find_max_pos(const vector <point> &p)
{
    point minp=p[1];
    uint16_t minpos=1;
    for(uint32_t i=1; i<p.size(); i++)
    {
        if()
    }
}*/

int64_t solve(int64_t pos)
{
    vector <point> p=points;
    swap(p[0], p[pos]);
    cmp_point_base=p[0];
    sort(p.begin()+1, p.end(), cmp_point);
    /*for(uint16_t i=0; i<p.size(); i++)
    {
        cout<<p[i].x<<' '<<p[i].y<<endl;
    }*/
    int64_t cur_res=2, res_max=2;
    for(int64_t i=1; i<p.size()-1; i++)
    {
        //cout<<"ADDSA: "<<i<<" "<<cross_product(p[0], p[i], p[i+1])<<endl;;
        if(cross_product(p[0], p[i], p[i+1])==0)cur_res++;
        else
        {
            cur_res=2;
        }
        if(res_max<cur_res)res_max=cur_res;
    }
    return res_max;
}

int main()
{
    init();
    int64_t res=solve(0);
    for(int64_t i=1; i<points.size(); i++)
    {
        res=max(res, solve(i));
    }
    cout<<res<<endl;

}
