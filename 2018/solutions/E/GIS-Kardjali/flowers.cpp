#include<iostream>
using namespace std;
int main()
{
unsigned long long n,q,f[10000],max=0;
cin>>n;
for(long long i=0;i<n;i++)
{
cin>>f[i];
if(f[i]>max)max=f[i];
}
cin>>q;
unsigned long long sum=0;
for(long long i=0;i<n;i++)
sum=sum+(max-f[i]);
cout<<sum*q<<endl;
return 0;
}
