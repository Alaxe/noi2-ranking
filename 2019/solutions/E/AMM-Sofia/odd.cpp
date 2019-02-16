#include<iostream>
using namespace std;
int main ()
{
    unsigned long long n=0 ,k=0,d=1,o=0,a,b;
   cin>>a>>b;
for(d=1;d*d<=b;d++)
{
   if(d*d>=a)
   {
       k++;
   }
}
cout<<k;

    return 0;
}
