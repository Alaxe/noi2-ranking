#include<iostream>
using namespace std;
int main()
{
int a[1000],b[1000],maxbr=0,n,br=0;
for(int i=0;i<n;i++)
{
cin>>a[i]>>b[i];
}
for(int i=0;i<n;i++)
{
if(a[i]=a[i+1] || b[i]=b[i+1])
{
br=br+2;
}
}
cout<<br<<endl;
return 0;
}
