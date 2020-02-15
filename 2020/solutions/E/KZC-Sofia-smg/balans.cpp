#include<iostream>
using namespace std;
int main()
{
long long n,br=0,parva=0,vtora=0;
char niz[1000001];
cin>>n;
for(long long i=0;i<n;i++)
{
cin>>niz[i];
if(niz[i]=='a' || niz[i]=='b')
{
parva++;
}
if(niz[i]=='c' || niz[i]=='d')
{
vtora++;
}
}
if(parva==vtora)
{
br=n;
cout<<br;
}
if(parva>vtora)
{
cout<<br;
}
if(vtora>parva)
{
cout<<vtora;
}
return 0;
}
