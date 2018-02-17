#include<iostream>
using namespace std;
int main ( )
{
    long long n,k,i;
    cin>>n>>k;
if (n==1) i=1;
if (n==2) i=10;
if (n==3) i=100;
if (n==4) i=1000;
if (n==5) i=10000;
if (n==6) i=100000;
if (n==7) i=1000000;
if (n==8) i=10000000;
if (n==9) i=100000000;
if (n==10) i=1000000000;
if (n==11) i=10000000000;
if (n==12) i=100000000000;
if (n==13) i=1000000000000;
if (n==14) i=10000000000000;
if (n==15) i=100000000000000;
if (n==16) i=1000000000000000;
if (n==17) i=10000000000000000;
if (n==18) i=100000000000000000;
for (i;i;i++)
{
   if(i%k!=0) i++;
   if(i%k==0) break;
}
cout<<i<<endl;
return 0;
}
