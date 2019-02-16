#include <iostream>
using namespace std;
int main ()
{
long long n,x,pr=-2;
cin>>n;
x=1;
for(int i=1;i<=n;i++)
{
    pr=pr+2;
    x=pr+x;
}
cout<<x<<endl;


}

