#include<iostream>
using namespace std;
int main()
{
long long n,m=1,r=3;
cin>>n;
if(n==1) cout<<1<<endl;
else{for(int i=2;i<=n;i++)
{
if(i==n)m=m+(r+1)/2;
else {m=m+r;r=r+2;}
}}
if(n!=1)cout<<m<<endl;
return 0;
}
