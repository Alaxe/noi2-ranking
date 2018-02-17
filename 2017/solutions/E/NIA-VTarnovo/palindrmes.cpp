#include <iostream>
using namespace std;
int main ()
{
int n,p,sum;
cin>>n;
sum=n*p;
n=n+p;
p=p+n;
if(n>p||n<p)
cout<<n<<' '<<p<<endl;
cout<<sum<<endl;
return 0;
}
