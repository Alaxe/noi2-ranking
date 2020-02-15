#include<iostream>
using namespace std;
int main()
{
long long n,i;
cin>>n;
long long b[n];
for(i=0;i<n;i++)
{
cin>>b[i];
}
for(i=1;i<=n;i++)
{
if(i==n)cout<<i<<endl;
else cout<<i<<" ";
}
return 0;
}