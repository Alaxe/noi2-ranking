#include <iostream>
using namespace std;
int arr[201];
int main()
{
int n,a,b,q=0,z,e=0,v=0;

cin>>n>>a>>b;
v=a+b;
if(a>b)
{
z=a;
a=b;
b=z;
}
for(q;q<n;q++)
{
cin>>arr[q];
}
for(int p=0;p<n;p++)
{
if(arr[p]<a){e++;}
}
if(e==0)
{
cout<<b;
}
if(e!=0){cout<<v;}
return 0;
}
