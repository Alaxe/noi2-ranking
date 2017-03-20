#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   long long n;
   long long w, h;
   long long mx;

   long long ans=0;

   cin>>w>>h;
   cin>>n;
   long long x[w+1000];
   long long y[h+1000];
   long long nx[w+1000];

   for(int i=1;i<=n;i++)
   {
       cin>>x[i]>>y[i];
   }

   for(int i=1;i<=h;i++)
   {
       ans+=w-x[i];
   }


   cout<<ans;

   return 0;
}
