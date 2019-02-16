#include<iostream>
using namespace std;
int main ()
{
unsigned long long n=0 ,k,d,o=1,m=1;
   cin>>n;
for(k=2;k<=n;k++)
{
    m=m+2;
    if(k==n)
    {
        o=o+n;
    }
    else
    {
        o=o+m;
    }
}
cout<<o;
    return 0;
}
