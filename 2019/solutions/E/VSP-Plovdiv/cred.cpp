#include<iostream>
using namespace std;
int main()
{
long long n,m,sbor,br=0;
cin>>n>>m;
sbor=n;
while(n<+m)
{
sbor=n+n%10;
while(n)
{
n/=10;
sbor=sbor+n%10;
}
n=sbor;
br++;
}
cout<<br<<endl;
}
