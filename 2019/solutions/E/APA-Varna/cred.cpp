#include<iostream>
using namespace std;
int main()
{
int n,i,m,c=0;
cin>>n>>m;
if(n<=m)c=1;
for(i=n;i<=m;i++)
{n=n+n/10+n%10;
if(n<=m)c++;}
cout<<c<<endl;
return 0;
}
