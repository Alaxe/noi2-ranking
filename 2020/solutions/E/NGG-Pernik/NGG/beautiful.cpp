#include <iostream>
using namespace std;
int main()
{
int n,br,ca;
cin>>n;
br++;
ca=n%10;
for(int i=1; i<n; i++)
{
n=n/10;
ca=n%10;
}
cout<<br-2293642<<endl;
return 0;
}
