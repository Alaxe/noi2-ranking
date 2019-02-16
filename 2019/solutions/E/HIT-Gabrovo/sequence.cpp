#include <iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int x=1,z=1;
if(n==1)
{
  cout<<1<<endl;
  return 0;
}
while(x<n)
{
  z=z+x*2;
  x++;
}
cout<<z<<endl;

 return 0;
}
