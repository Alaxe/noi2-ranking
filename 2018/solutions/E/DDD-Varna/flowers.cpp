#include<iostream>
using namespace std;
int main()
{
    int n,q,l,a[10000];
    cin>>n;
    l=n;
    while(l!=0)
    {
        cin>>a[10000];
        l--;
    }
    cin>>q;
    int p[10000];
    p[0]=a[0];
    while(a[0]==a[1])
    {
        a[0]+=q;
    }
    cout<<a[0]-p[0];
    return 0;
}
