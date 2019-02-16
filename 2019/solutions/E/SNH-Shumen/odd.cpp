#include<iostream>
using namespace std;
long long int del(int n)
{
    long long int br=0;
    for(int del=2;del<=n/2;del++)
    {
        if(n%del==0)br++;
    }
    br+=2;
    return br;
}
int main()
{
long long int a,b;
cin>>a>>b;
long long int br2=0;
for(long long int i=a;i<=b;i++)
{
    if(del(i)%2!=0)br2++;
}
cout<<br2<<endl;
return 0;
}
