#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
struct vr
{
    int a;
    int b;
};
int cmp (vr a,vr b)
{
    if (a.a<b.a)return true;
    else return false;
}
int main ()
{
     vr a[20];

     int b,c,sv,otg=0;
    for (int i=0;i<3;i++)
    {
        cin>>a[i].a>>a[i].b;
    }
    sort (a,a+3,cmp);

    sv=a[0].a+a[0].b;
    if (a[1].a<=sv)sv=sv+a[1].b;
    else sv=a[1].a+a[1].b;
    otg=sv-a[2].a;
    if (otg<0)otg=0;
    otg=otg+a[2].b;
    cout<<otg<<endl;
    return 0;
}
