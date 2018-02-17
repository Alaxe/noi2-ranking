#include <iostream>
using namespace std;
int main()
{
   long long n,k,i=0,j=1;
   cin>>n>>k;
   for(i=1;i<n;i++)
   {
       j=j*10;
   }
   for(;;)
   {
       if(j%k==0) break;
       else j++;
   }
   cout<<j;
  return 0;
}
