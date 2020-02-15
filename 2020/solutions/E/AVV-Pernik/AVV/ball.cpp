#include <iostream>
using namespace std;
int main()
{
int n,x,nch,ch,f;
char a0,a1,a2;
cin>>n>>x;
if(n%2==0) n=nch;
if(n%2!=0) n=ch;
if(n==nch) if(x==a0) f=a1;
if(n==nch) if(x==a1) f=a0;
if(n==ch) if(x==a1) f=a2;
if(n==ch) if(x==a2) f=a1;
cout<<f;



return 0;
}
