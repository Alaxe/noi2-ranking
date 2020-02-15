#include<iostream>
using namespace std;
long long a[100];
int main()
{
long long n,v,u,V=0,i,fl=0;
cin>>n>>v>>u;
for(i=0;i<n;i++)cin>>a[i];
for(i=1;i<n;i++)
{fl=0;
if(a[i]>a[i-1])V=V+(a[i-1]*v*u);
else if(a[i]<a[i+1]){V=V+(a[i+1]*u*2*v);fl=1;}
     else V=V+(a[i]*u*v);
if(fl!=0)V=V-(a[i]*v*u);
}
cout<<V<<endl;
return 0;
}