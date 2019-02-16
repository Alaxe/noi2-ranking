#include<iostream>
using namespace std;
int main ()
{
unsigned long long a,b,cbr;
cin>>a>>b;
if (a%2==0)
{if (b%a!=0) cbr=b/a;
else cbr=b/a-1;}
else
{
if (b%a!=0) cbr=b/a-1;
else cbr=b/a-2;
}
cout<<cbr<<endl;
return 0;
}
