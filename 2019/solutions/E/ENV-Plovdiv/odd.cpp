#include<iostream>
using namespace std;
int main()
{
unsigned long  long a,b,br;
cin>>a>>b;
if(a%2==0)
{
 if(b%a!=0) br=b/a;
 else br=b/a-1;
}
else
{if(b%a!=0) br=b/a-1;
else br=b/a-2;}
cout<<br<<endl;
 return 0;
}
