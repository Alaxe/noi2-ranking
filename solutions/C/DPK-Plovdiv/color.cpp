#include<iostream>
#include<vector>
using namespace std;
long long t,n,x[100005],i,j,z,a[100005],max1[15],sum1;
int main ()
{
   cin>>t;
   for (i=1;i<=t;i++)
   {
       cin>>n;
       for (j=1;j<=n;j++)
       {
           cin>>x[j];
           a[x[j]]++;
           a[j]++;
       }
       sum1=0;
       for (z=1;z<=n;z++)
       {
           if (sum1<a[z]) sum1=a[z];
           a[z]=0;
       }
       max1[i]=sum1;
   }
   for (i=1;i<=t;i++)
   {
       cout<<max1[i]<<endl;
   }
   return 0;
}
