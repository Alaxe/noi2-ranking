#include<iostream>
using namespace std;
int main ( )
{
    long long n,q,max,br=0,i,p,c;
   cin>>n;
   
   for (i=1;i<=n;i++)
   { 
   cin>>c;
   max=c;
   if(c>max)  max=c;
   else p=max-c;
   br=p+br;
   } 
   cin>>q;
   br=br*q;
cout<<br<<endl;
return 0;
}