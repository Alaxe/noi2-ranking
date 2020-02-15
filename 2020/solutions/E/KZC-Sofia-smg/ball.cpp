#include<iostream>
using namespace std;
int main()
{
long long n,x;
cin>>n>>x;
while(n>0)
{
if(n%2==1)
{
if(x==1)
{
x=0;
break;
}
if(x==0)
{
x=1;
}
}
if(n%2==0)
{
if(x==2)
{
x=1;
break;
}
if(x==1)
{
x=2;
}
}
n--;
}
cout<<x;
return 0;
}
