#include<iostream>
using namespace std;
int main()
{
int r[10000];
int d,e,i,n,a=0,q,s=0;
cin>>n;
for(i=0;i<n;i++)
{
cin>>r[i];
if(r[i]>a)a=r[i];
s=s+r[i];
}
d=n*a;
e=d-s;
cin>>q;
cout<<q*e<<endl;
}








