#include<iostream>
using namespace std;
int main()
{
unsigned long long m=1,n,k,i,ch=1;
cin>>n>>k;
for(i=2;i<=n;i++)
{
ch=ch*10;
m=m*10+9;
}
if(ch%k!=0)ch=ch+(k-ch%k);
if(ch>m)cout<<"NO"<<endl;
else if(ch<=m)cout<<ch<<endl;
}
