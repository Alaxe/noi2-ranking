#include<iostream>
using namespace std;
int main()
{
unsigned long long n,k,a,b,s=0;
cin>>n>>k;
a=1;
for(unsigned long long i=1;i<n;i++)
a=a*10;
b=1;
for(unsigned long long i1=1;i1<n+1;i1++)
b=b*10;
b=b-1;
for(unsigned long long j=a;j<=b;j++)
{
if(j%k==0){s=j;break;}
}
if(s!=0)cout<<s<<endl;
else cout<<"NO"<<endl;
return 0;
}
