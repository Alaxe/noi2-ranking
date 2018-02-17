#include<iostream>
using  namespace std;
int main()
{
 long long n,x=1,b,u=10,ans=0, d=1,y=0,a;
    cin>>n;
    b=n;
    for(int i=n; i>=1; i--)
    {
        x=x*i;

    }
    while(u/10<x)
    {
        d=(x%u)/(u/10);
        y=y+d;
        u=u*10;
    }
    cout<<y<<endl;

    return 0;
}
