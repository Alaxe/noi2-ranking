#include <iostream>
#include <algorithm>
using namespace std;
struct graph
{
    short x,y;
    double diff;
};
bool cmp(graph a,graph b)
{
    return a.x<b.x;
}
bool cmp2(graph a,graph b)
{
    return a.y<b.y;
}
bool cmp3(graph a,graph b)
{
    return a.diff<b.diff;
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    graph p[1002];
    int n;
    int br=1,br_max=-1;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i].diff=(double)p[i].x/p[i].y;
    }
    sort(p,p+n,cmp);
    for (int i=1; i<n; i++)
    {
        if(p[i].x==p[i-1].x) br++;
        else
        {
            if (br>br_max)br_max=br;
            br=1;
        }
    }
    if (br>br_max)br_max=br;
    sort(p,p+n,cmp2);
    br=1;
    for (int i=1; i<n; i++)
    {
        if(p[i].y==p[i-1].y) br++;
        else
        {
            if (br>br_max)br_max=br;
            br=1;
        }
    }
    if (br>br_max)br_max=br;
    sort(p,p+n,cmp3);
    br=1;
    for (int i=1; i<n; i++)
    {
        if(p[i].diff==p[i-1].diff) br++;
        else
        {
            if (br>br_max)br_max=br;
            br=1;
        }
    }
    if (br>br_max)br_max=br;
    cout<<br_max<<endl;
    return 0;
}
