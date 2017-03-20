#include<iostream>
using namespace std;
   int main()
{int n,a[1000],i,j,br=0,d;
cin>>n;
for(i=0;i<=n-1;i++)
           cin>>a[i];
for(i=0;i<=n-1;i++)
   for(j=0;j<=n-1;j++)
      for(d=1;d<=1000;d++)
   if(a[i]==a[j]+d) br++;
cout<<br<<endl;
}
