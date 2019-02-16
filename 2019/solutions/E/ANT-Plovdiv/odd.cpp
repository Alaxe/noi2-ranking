#include<iostream>
using namespace std;
int main()
{
long long a,b,arr[10],otg;
cin>>a>>b;
if(a%1==0 && a%2==0 && a%4==0)otg=1;
if(arr[1]%1==0 && arr[1]%5==0)otg=1;
if(arr[2]%1==0 && arr[2]%2==0 && arr[2]%3==0 && arr[2]%6==0)otg=1;
if(arr[3]%1==0 && arr[3]%7==0)otg=1;
if(arr[4]%1==0 && arr[4]%2==0 && arr[4]%4==0 && arr[4]%8==0)otg=1;
if(arr[5]%1==0 && arr[5]%3==0 && arr[5]%9==0)otg=2;
if(arr[6]%1==0 && arr[6]%2==0 && arr[6]%5==0 && arr[6]%10==0)otg=2;
if(b%1==0 && b%11==0)otg=2;
cout<<otg<<endl;
return 0;
}


