#include<iostream>
using namespace std;
int main()
{
long long i,n,m,arr[10],a,b,a1,b1,a2,b2,a3,b3,a4,b4,a5,b5,a6,b6,a7,b7;
cin>>n>>m;
a=n/10;
b=n%10;
arr[1]=n+a+b;
if(arr[1]>=m)cout<<1<<endl;
else
{
a1=arr[1]/10;
b1=arr[1]%10;
arr[2]=arr[1]+a1+b1;
if(arr[2]>m)cout<<2<<endl;
else
{
a2=arr[2]/10;
b2=arr[2]%10;
arr[3]=arr[2]+a2+b2;
if(arr[3]>m)cout<<3<<endl;
else
{
a3=arr[3]/10;
b3=arr[3]%10;
arr[4]=arr[3]+a3+b3;
if(arr[4]>m)cout<<4<<endl;
else
{
a4=arr[4]/10;
b4=arr[4]%10;
arr[5]=arr[4]+a4+b4;
if(arr[5]>m)cout<<5<<endl;
else
{
a5=arr[5]/10;
b5=arr[5]%10;
arr[6]=arr[5]+a5+b5;
if(arr[6]>m)cout<<6<<endl;
else
{
a6=arr[6]/10;
b6=arr[6]%10;
arr[7]=arr[6]+a6+b6;
if(arr[7]>m)cout<<7<<endl;
else cout<<8<<endl;
}
}
}
}
}
}

return 0;
}

