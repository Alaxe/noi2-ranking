#include<iostream>
using namespace std;
int main()
{
long long int n,a,q,max1=0,br=0;
cin>>n;
for (long long int i=0;i<n;i++)
{
    cin>>a;
    if (a>max1)max1=a;
    br=br+a;
}
cin>>q;
long long int ob=max1*n;
long long int raz=ob-br;
cout<<raz*q<<endl;

return 0;
}
