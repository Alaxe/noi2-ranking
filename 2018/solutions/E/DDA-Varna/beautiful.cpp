#include<iostream>
using namespace std;
int main()
{
int n,k,a;
cin>>n>>k;
if(n==1)a=0;
if(n==2)a=10;
if(n==3)a=100;
if(n==4)a=1000;
if(n==5)a=10000;
if(n==6)a=100000;
if(n==7)a=1000000;
if(n==8)a=10000000;
if(n==9)a=100000000;
if(n==10)a=1000000000;
if(n==11)a=10000000000;
if(n==12)a=100000000000;
if(n==13)a=1000000000000;
if(n==14)a=10000000000000;
if(n==15)a=100000000000000;
if(n==16)a=1000000000000000;
if(n==17)a=10000000000000000;
if(n==18)a=100000000000000000;
while(a%k!=0)a++;
cout<<a<<endl;
}










