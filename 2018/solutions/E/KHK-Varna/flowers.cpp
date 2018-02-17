#include<iostream>
using namespace std;
int main()
{
unsigned long long n,q,i,a[10000],m,br=0;
cin>>n;
for(i=1;i<=n;i++)
{
cin>>a[i];
}
cin>>q;
m=a[1];
for(i=2;i<=n+1;i++)
{
m=max(m,a[i-1]);
}
for(i=1;i<=n;i++)
{
    if(a[i]<m)
   {
       while(1)
       {
           if(a[i]==m)break;
           a[i]++;
        br+=q;
       }
   }
}
cout<<br<<endl;
}
