#include <iostream>
using namespace std;

int main()
{
long long a,b;
cin>>a>>b;
int br=0;
long long x=1;
int z=3;
if(a<=1&&b>=1)
br++;
while(x+z>=a&&x+z<=b)
{
  br++;
  x=x+z;
  z=z+2;
}
cout<<br<<endl;

 return 0;
}
