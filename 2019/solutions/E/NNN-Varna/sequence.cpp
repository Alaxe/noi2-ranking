#include<iostream>
using namespace std;
int main()
{
long long int n,i,k=1,ngel,brel=1;
cin>>n;
while(n>k)
{
k++;
brel=brel+(k+1);
}
cout<<brel+(n*2)<<endl;
return 0;
}
