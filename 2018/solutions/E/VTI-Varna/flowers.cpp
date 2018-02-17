#include<iostream>
using namespace std;
int main()
{
long long n,q,m=0,l,r=0,i,c,a;
cin>>n;
for(i=0;i<n;i++)
{
cin>>c;
if(c>m)
{
if(m==0)
{
a=c;
}
r=r+c-m;
m=c;
}
r=r+m-c;
}
cin>>q;
r=r-a;
l=r*q;
cout<<l<<endl;
return 0;
}
