#include<iostream>
using namespace std;
int main()
{
int n,q,f[10000],max=0;
cin>>n;
for (int i=0;i<n;i++)
{cin>>(f[i]);
if(f[i]>max)max=f[i];}
cin>>q;
int sum=0;
for (int i=0;i<n;i++)
sum=sum+(max-f[i]);
cout<<sum*q;
return 0;
}
