#include<iostream>
using namespace std;
int main()
{
long long n,k[10000],q,h[10000],m=1,l,r=0;
cin>>n;
for(int i=0;i<=n-1;i++)
{
cin>>k[i];
}
cin>>q;
if(k[0]>k[1])
    h[0]=k[0];
    else
    h[0]=k[1];
for(int i=2;i<=n-1;i++)
{
  if(k[i]>k[i-1])
  h[m]=k[i];
else
  h[m]=k[i-1];
  m++;
}
cout<<endl;
for(int i=0;i<=n-1;i++)
{
    if(h[i]>h[i-1])
    l=h[i];
else l=h[i-1];
}
cout<<endl;
for(int i=0;i<=n-1;i++)
{
if(k[i]!=l)
    r+=(l-k[i])*q;
}
cout<<r<<endl;
return 0;
}
