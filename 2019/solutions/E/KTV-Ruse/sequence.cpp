#include<iostream>
using namespace std;
int main()
{
   long long n,m,i,s=0;
   cin>>n;
   for(i=1;i<=n*2-1;i=i+2)
   {
       s=s+i;
   }
   m=s-(n-1);
   cout<<m<<endl;
   return 0;
}