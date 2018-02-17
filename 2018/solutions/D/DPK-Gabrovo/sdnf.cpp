#include <iostream>
using namespace std;
long long fact (long long n)
{
    if (n==1)return 1;
    return n*fact(n-1);
}
int main ()
{
   long  long n;
   cin>>n;
   long long k=fact(n);
   long long z=0;
   while (true)
   {

       z=z+k%10;
       k=k/10;
       if (k==0)break;
   }
   cout<<z<<endl;
   return 0;
}
