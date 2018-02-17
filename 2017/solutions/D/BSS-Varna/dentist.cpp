#include<bits/stdc++.h>
using namespace std;
struct str
{
    int p,v;
};
int cmp(str x,str y)
{
    if(x.p>y.p)return x.p<y.p;
}
int main()
{
    str a[10000];
    int n=0,i,t;
    while(!cin.eof())
    {
        cin>>a[n].p>>a[n].v;
        n++;
    }
    n--;
    sort(a,a+n,cmp);
    t=a[n-1].p;
    for(i=0;i<n-1;i++)
    {
        if(a[i].p+a[i].v>a[i+1].p)a[i+1].p=a[i].p+a[i].v;
    }
    a[n-1].p+=a[n-1].v;
    cout<<a[n-1].p-t<<endl;
}
/**
55 15
185 22
130 10

0 30
720 10
715 20
714 25
*/
