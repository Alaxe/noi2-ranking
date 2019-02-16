#include<iostream>
using namespace std;
int main()
{
long long n,i,br;
cin>>n;
br=n;
for(i=n-1;i!=0;i--)
{br=br+(i*2-1);}
cout<<br<<endl;
return 0;
}
