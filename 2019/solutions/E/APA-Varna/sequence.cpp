#include<iostream>
using namespace std;
int main()
{
int n,x,a,i;
cin>>n;
a=0;
x=1;
for(i=1;i<=n;i++)
{x=x+a*2;
a++;}
cout<<x<<endl;
return 0;
}
