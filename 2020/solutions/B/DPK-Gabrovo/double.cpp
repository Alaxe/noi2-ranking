#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int n,w1,w2;
    int sb=0;
    short a[200];
    cin>>n>>w1>>w2;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if (w2>w1)swap(w2,w1);
    if (w2>a[0])w1=w1+w2;

    for (int i=n;i>0;i--)
    {
        sb=sb+a[i];
        if (sb>w1)sb=sb-a[i];
    }
    int sb1=0;
    for (int i=0;i<n;i++)
    {
        sb1=sb1+a[i];
        if (sb1>w1)sb1=sb1-a[i];
    }
    cout<<max(sb,sb1)<<endl;

    return 0;
}
