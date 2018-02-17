#include <iostream>
using namespace std;
int main ()
{
    long long n,k,a,b=1;
    cin>>n>>k;

  for (a=2;a<=n;a++)
  {
    b=b*10;
  }
   if (b*10<=k)
   cout<<"NO";
   else
   {
   do
    {
        b=b+1;
    }
    while(b%k!=0);


    cout<<b;
   }
}
