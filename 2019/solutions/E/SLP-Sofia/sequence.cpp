#include <iostream>
using namespace std;
int main()
{
    long long n,x=1,c=0;
    cin>>n;
  while(c<n)
  {
      x=c*2+x;
      c++;
  }

    cout<<x;
    return 0;
}
