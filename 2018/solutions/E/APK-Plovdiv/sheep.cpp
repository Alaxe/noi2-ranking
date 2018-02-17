#include<iostream>
using namespace std;
int main()
{
int n,l,a,b,c,x=0,max=0,mas[1000000];
cin>>n;
cin>>l;
if(l=1) cin>>a;
if(l=2) cin>>a; cin>>b;
if(l=3) cin>>a; cin>>b; cin>>c;
for(int i=0;i<=n;i++)
{
if(mas[i]>max) max=mas[i];
}
return 0;
}
