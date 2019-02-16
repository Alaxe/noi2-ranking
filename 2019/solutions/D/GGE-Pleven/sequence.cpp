#include<iostream>
#include<stack>
using namespace std;
long long n,k,p=0,y=1,z;
long long chisla(long long x)
{
    int i;
    for(i=1;i<=x-1;i++)
    {
        p++;
        if(i==n)
        {
            k--;
        }
        if(k==0)
        {
            return p;
        }
    }
    p++;
    if(x==n)
    {
        k--;
    }
    if(k==0)
    {
        return p;
    }
    for(i=x-1;i>=1;i--)
    {
        p++;
        if(i==n)
        {
            k--;
        }
        if(k==0)
        {
            return p;
        }
    }
    return 0;
}
int main ()
{
cin>>n>>k;
while(1)
{
    z=chisla(y);
    y++;
    if(z!=0)
    {
        break;
    }
}
cout<<z<<endl;
return 0;
}
