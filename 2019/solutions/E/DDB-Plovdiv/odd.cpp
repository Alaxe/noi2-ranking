#include<iostream>
using namespace std;
int main ()
{
long long a,b,c,d,br=1,flo=0;
cin>>a>>b;
c= min(a,b);
d= max(a,b);
for (long long i=c;c<=d;c++)
{
for (int j=1;j<=c/2;j++)
{
if (c%j==0) br++;
}
if (br>1&&br%2==1) flo++;
br=1;
}
cout<<flo<<endl;
return 0;
}
