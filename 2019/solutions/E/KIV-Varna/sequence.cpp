#include<iostream>
using namespace std;
int main()
{
int n,a=1,b=0,br=0;
cin>>n;
while(n>a)
{b=b+2;
br=1+b;
a++;}
if(n==1)cout<<br+1<<endl;
cout<<br<<endl;
return 0;
}
