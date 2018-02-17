#include <iostream>
using namespace std;
int main()
{
int n,a,ma=0,i=1;
long long brw=0,q;
cin>>n;
while (i<=n)
{
    cin>>a;
    if (a>ma) ma=a;
    brw+=a;
    i++;
}
cin>>q;
cout<<((n*ma)-brw)*q<<endl;
return 0;
}
