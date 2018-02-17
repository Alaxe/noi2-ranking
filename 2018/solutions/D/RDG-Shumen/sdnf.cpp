#include <iostream>
using namespace std;
int main()
{
    long long  int  n,u=1,sum=0,i;
   cin>>n;
   for(i=1;i<=n;i++)
   {
       u*=i;

   }
cout<<u<<endl;
while(u!=0)
   {
   int ed=u%10;
       u/=10;
       sum+=ed;
   }
   cout<<sum<<endl;
    return 0;
}
