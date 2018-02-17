#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
unsigned long long int n,br=0;
scanf("%llu",&n);
while(n%2==0)
{n=n/2;
br++;
}
if(n=24)cout<<2<<endl;
else
cout<<br<<endl;
return 0;
}
