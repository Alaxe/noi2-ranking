#include <iostream>
using namespace std;
int main()
{
    long long a,b,c,d,e,n,m;
    cin>>n>>m;
    if (n>m)
    {
        return 0;
    }
    if (n/10==1 || n/10==2 || n/10==3 || n/10==4 || n/10==5 || n/10==6 || n/10==7 || n/10== 8 || n/10==9)
    {
        a=m-n;
        b=a%10;
        cout<<b<<endl;
    }
    if (n/100==1 || n/100==2 || n/100==3 || n/100==4 || n/100==5 || n/100==6 || n/100==7 || n/100== 8 || n/100==9)
    {
        a=m-n;
        b=a%10;
        c=(a/10)%10;
        cout<<c<<b<<endl;
    }
    if (n/1000==1 || n/1000==2 || n/1000==3 || n/1000==4 || n/1000==5 || n/1000==6 || n/1000==7 || n/1000== 8 || n/1000==9)
    {
        a=m-n;
        b=a%10;
        c=(a/10)%10;
        d=(a/100)%10;
        cout<<d<<c<<b<<endl;
    }
    if (n/10000==1 || n/10000==2 || n/10000==3 || n/10000==4 || n/10000==5 || n/10000==6 || n/10000==7 || n/10000== 8 || n/10000==9)
    {
        a=m-n;
        b=a%10;
        c=(a/10)%10;
        d=(a/100)%10;
        e=(a/1000)%10;
        cout<<e<<d<<c<<b<<endl;
    }
    return 0;
}