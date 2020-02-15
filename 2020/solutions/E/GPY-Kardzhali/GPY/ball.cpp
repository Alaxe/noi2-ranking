#include <iostream>
using namespace std;
int main()
{
int a0,a1,a2,n,x,m;
cin>>n>>x;
if(x==0){a0=1;a1=0;a2=0;}
if(x==1){a0=0;a1=1;a2=0;}
if(x==2){a0=0;a1=0;a2=1;}
for(int a=n;a>0;a--)
{if(a%2==0){m=a1;a1=a2;a2=m;}
if(a%2==1){m=a0;a0=a1;a1=m;}
}
if(a0==1)cout<<0<<endl;
if(a1==1)cout<<1<<endl;
if(a2==1)cout<<2<<endl;
return 0;
}
