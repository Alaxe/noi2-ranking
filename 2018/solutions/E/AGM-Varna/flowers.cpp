#include <iostream>
using namespace std;
int main ()
{
    int a[10000],n;
    long long q,m=0,v,mv=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]>m)m=a[i];
    }
    cin>>q;

    for (int i=0;i<n;i++)
    {
        v=m-a[i];
        mv=mv+v*q;;
    }

    cout <<mv<<endl;

    return 0;
}
