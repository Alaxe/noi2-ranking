#include<iostream>
using namespace std;
int main ()
 {
   int x,n,c0,c1,c2;
   cin>>n;
   cin>>x;
   do
   {
       if(x==0)swap(c0,c1);
       if(x==1)swap(c1,c2);
   }while (n);
   cout<<x<<endl;
   return 0;
 }