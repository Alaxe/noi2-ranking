#include<iostream>
#include<algorithm>
struct hour
{
    int ch;
    int vr;
};
hour a[721];
bool comp(hour a1, hour a2)
{
    if(a1.ch<a2.ch) return true;
    return false;
}
using namespace std;

int main()
{
    bool k=false;
    int n=0, t, p, h, raz, m;
    while(cin>>a[n].ch>>a[n].vr)
    {
        n++;
    }
    sort(a, a+n, comp);
    t=a[n-1].vr;
    h=a[0].ch+a[0].vr;
    for(p=1; p<n-1; p++)
    {
        if(h<a[p].ch) h=a[p].ch;
        h=h+a[p].vr;
        if(h>=a[n-1].ch)
        {
            raz=h-a[n-1].ch;
            k=true;
            break;
        }
    }
    if(k)
    {
        t=t+raz;
        for(m=p+1; m<n-1; m++)
        {
            t=t+a[m].vr;
        }
    }
    cout<<t<<endl;
}


