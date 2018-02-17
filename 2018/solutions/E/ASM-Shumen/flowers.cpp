#include <iostream>
using namespace std;
int main()
{int n,q;
cin>>n>>q;
int br=0;
int sum=0;
for(int i=0;i<n;i++)
{
   int ost=20-10;
   int a=ost*q;
   int ost2=20-17;
   int b=ost2*q;
   int ost3=20-12;
   int c=ost3*q;
   if(a+b+c==sum)cout<<sum<endl;
}
   return 0;   
}