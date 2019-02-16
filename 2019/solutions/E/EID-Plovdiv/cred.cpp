#include<iostream>
using namespace std;
int main()
{
long long n,m,v,br=0;
cin>>n>>m;
v=n;
while(v<=m)
{
while(n>0)
{
v=n%10+v;
n=n/10;
}
n=v;
br++;}
cout<<br<<endl;
return 0;
}
