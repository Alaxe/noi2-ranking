#include<iostream>
using namespace std;
int main()
{unsigned long long a,b,br=0,br2=0,ma;
cin>>a;
cin>>b;
if (a%2!=0)
{
if (b%a!=0) ma=b/a;
else ma=b/a-2;
}
else
{
if (b%a!=0) ma=b/a-1;
else ma=b/a-2;
}
cout<<ma<<endl;
return 0;
}
