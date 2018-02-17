#include<iostream>
using namespace std;
int main ()
{
long long n,k,i,j,h,g,f,d,s,a;
cin>>n>>k;
if(n==1)
{
    h=1;
    g=9;
}
else if(n==2)
{
    h=10;
    g=99;
}
else if(n==3)
{
    h=100;
    g=999;
}
else if(n==4)
{
    h=1000;
    g=9999;
}
else if(n==5)
{
    h=10000;
    g=99999;
}
else if(n==6)
{
    h=100000;
    g=999999;
}
else if(n==7)
{
    h=1000000;
    g=9999999;
}
else if(n==8)
{
    h=10000000;
    g=99999999;
}
else if(n==9)
{
    h=100000000;
    g=999999999;
}
else if(n==10)
{
    h=1000000000;
    g=9999999999;
}
else if(n==11)
{
    h=10000000000;
    g=99999999999;
}
else if(n==12)
{
    h=100000000000;
    g=999999999999;
}
else if(n==13)
{
    h=1000000000000;
    g=9999999999999;
}
else if(n==14)
{
    h=10000000000000;
    g=99999999999999;
}
else if(n==15)
{
    h=100000000000000;
    g=999999999999999;
}
else if(n==16)
{
    h=1000000000000000;
    g=9999999999999999;
}
else if(n==17)
{
    h=10000000000000000;
    g=99999999999999999;
}
else if(n==18)
{
    h=100000000000000000;
    g=999999999999999999;
}
for(i=h;i<=g;i++)
{
    if(i%k==0)
    {
        f=1;
        break;
    }
    else
    {
        f=0;
    }
}
if(f==0)
{
    cout<<"NO"<<endl;
}
else
{
    cout<<i<<endl;
}
    return 0;
}
