#include <iostream>
using namespace std;
long long n,i=1,j=1,a=0,n1=0,b=0;
int main()
{
  cin>>n;

  for(i=1;i<=n;i++)
  {
      j=j*i;
  }
  n1=j;
    for(;;)
    {
      a=n1%10;

      b=b+a;
      n1=n1/10;
      if(n1==0) break;
    }

    cout<<b;
  return 0;
}
